#include <gtest/gtest.h>

#include <iomanip>

#include "../model/model.h"
namespace calc {

TEST(Calc, test1) {
  std::string expr =
      "15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/"
      "(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))";
  std::string X = "0";
  Model model;
  model.MakeCalc(expr, X);
  EXPECT_EQ(model.GetError(), "ok");
  EXPECT_DOUBLE_EQ(model.GetResult(), -30.072164948453608);

  std::string expr1 = "15/15";
  X = "0";
  model.MakeCalc(expr1, X);
  EXPECT_EQ(model.GetError(), "ok");
  EXPECT_DOUBLE_EQ(model.GetResult(), 1);
}

TEST(Calc, test2) {
  std::string expr = "2^3^2";
  std::string X = "0";
  Model model;
  model.MakeCalc(expr, X);
  EXPECT_EQ(model.GetError(), "ok");
  EXPECT_EQ(model.GetResult(), 512);
}

TEST(Calc, test3) {
  std::string expr =
      "2+sin(1)+2-cos(1)+tan(1)+asin(1)+acos(1)-atan(1)+sqrt(4)+ln(1)+log(1)";
  std::string X = "0";
  Model model;
  model.MakeCalc(expr, X);
  EXPECT_EQ(model.GetError(), "ok");
  EXPECT_EQ(model.GetResult(),
            (2 + std::sin(1) + 2 - std::cos(1) + std::tan(1) + std::asin(1) +
             std::acos(1) - std::atan(1) + std::sqrt(4) + std::log(1) +
             std::log10(1)));
}

TEST(Calc, test4) {
  std::string expr = "2e+1";
  std::string X = "0";
  Model model;
  model.MakeCalc(expr, X);
  EXPECT_EQ(model.GetError(), "ok");
  EXPECT_EQ(model.GetResult(), 20.0);

  std::string expr2 = "2e-1";
  std::string X2 = "0";
  Model model2;
  model2.MakeCalc(expr2, X2);
  EXPECT_EQ(model2.GetError(), "ok");
  EXPECT_EQ(model2.GetResult(), 0.2);

  std::string expr3 = "2e1";
  std::string X3 = "0";
  Model model3;
  model3.MakeCalc(expr3, X3);
  EXPECT_EQ(model3.GetError(), "ok");
  EXPECT_EQ(model3.GetResult(), 20.0);
}

TEST(Calc, test5) {
  std::string expr = "-2+3*(+X+1)";
  std::string X = "1";
  Model model;
  model.MakeCalc(expr, X);
  EXPECT_EQ(model.GetError(), "ok");
  EXPECT_EQ(model.GetResult(), 4.0);
}

TEST(Calc, test6) {
  std::string expr = "X+X+X-X-X-X";
  std::string X = "2";
  Model model;
  model.MakeCalc(expr, X);
  EXPECT_EQ(model.GetError(), "ok");
  EXPECT_EQ(model.GetResult(), 0.0);
}

TEST(Calc, test7) {
  std::string expr = "2eX";
  std::string X = "1";
  Model model;
  model.MakeCalc(expr, X);
  EXPECT_EQ(model.GetError(), "ok");
  EXPECT_EQ(model.GetResult(), 20.0);

  std::string expr2 = "2e+X";
  std::string X2 = "1";
  Model model2;
  model2.MakeCalc(expr2, X2);
  EXPECT_EQ(model2.GetError(), "ok");
  EXPECT_EQ(model2.GetResult(), 20.0);

  std::string expr3 = "Xe+X";
  std::string X3 = "1";
  Model model3;
  model3.MakeCalc(expr3, X3);
  EXPECT_EQ(model3.GetError(), "ok");
  EXPECT_EQ(model3.GetResult(), 10.0);
}

TEST(Calc, test8) {
  std::string expr = "2-";
  std::string X = "0";
  Model model;
  model.MakeCalc(expr, X);
  EXPECT_EQ(model.GetError(), "invalid syntax");
}

TEST(Calc, test9) {
  std::string expr = "8%2";
  std::string X = "0";
  Model model;
  model.MakeCalc(expr, X);
  EXPECT_EQ(model.GetResult(), 0.0);
}

TEST(Calc, test10) {
  std::string expr = "2..2";
  std::string X = "0";
  Model model;
  model.MakeCalc(expr, X);
  EXPECT_EQ(model.GetError(), "invalid argument");
}

TEST(Calc, test11) {
  std::string expr = "()";
  std::string X = "0";
  Model model;
  model.MakeCalc(expr, X);
  EXPECT_EQ(model.GetError(), "brackets are empty");
}

TEST(Calc, test12) {
  std::string expr = "sin(1";
  std::string X = "0";
  Model model;
  model.MakeCalc(expr, X);
  EXPECT_EQ(model.GetError(), "extra bracket");
}

TEST(Calc, test13) {
  std::string expr = "2(1";
  std::string X = "0";
  Model model;
  model.MakeCalc(expr, X);
  EXPECT_EQ(model.GetError(), "invalid syntax");
}

TEST(Calc, test14) {
  std::string expr = "X";
  std::string X = "0";
  Model model;
  double xBegin = 0;
  double xEnd = 500;
  double yBegin = 0;
  double yEnd = 500;
  model.MakeGraph(expr, xBegin, xEnd, yBegin, yEnd);

  EXPECT_EQ(model.GetError(), "ok");

  std::vector<double> x(500);
  std::vector<double> y(500);
  x = model.GetVectorXfromGraph();
  y = model.GetVectorYfromGraph();

  for (int i = 0; i <= 500; i++) {
    auto x1 = x.at(i);
    auto y1 = y.at(i);
    EXPECT_EQ(x1, i);
    EXPECT_EQ(y1, i);
  }
  model.MakeGraph(expr, xBegin, xEnd, yBegin, yEnd);
  EXPECT_EQ(model.GetError(), "ok");

  x = model.GetVectorXfromGraph();
  y = model.GetVectorYfromGraph();

  for (int i = 0; i <= 500; i++) {
    auto x1 = x.at(i);
    auto y1 = y.at(i);
    EXPECT_EQ(x1, i);
    EXPECT_EQ(y1, i);
  }
}

TEST(Calc, test15) {
  std::string expr = "X";
  std::string X = "0";
  Model model;
  double xBegin = 0;
  double xEnd = 0;
  double yBegin = 0;
  double yEnd = 500;
  model.MakeGraph(expr, xBegin, xEnd, yBegin, yEnd);

  EXPECT_EQ(model.GetError(), "begining equal end");
}

TEST(Calc, test16) {
  std::string expr = "X";
  std::string X = "0";
  Model model;
  double xBegin = 10;
  double xEnd = 0;
  double yBegin = 0;
  double yEnd = 500;
  model.MakeGraph(expr, xBegin, xEnd, yBegin, yEnd);

  EXPECT_EQ(model.GetError(), "begining greater end");
}

TEST(Calc, test17) {
  std::string expr = "X";
  std::string X = "0";
  Model model;
  double xBegin = 0;
  double xEnd = 500;
  double yBegin = 0;
  double yEnd = 0;
  model.MakeGraph(expr, xBegin, xEnd, yBegin, yEnd);

  EXPECT_EQ(model.GetError(), "begining equal end");
}

TEST(Calc, test18) {
  std::string expr = "X";
  std::string X = "0";
  Model model;
  double xBegin = 0;
  double xEnd = 500;
  double yBegin = 10;
  double yEnd = 0;
  model.MakeGraph(expr, xBegin, xEnd, yBegin, yEnd);

  EXPECT_EQ(model.GetError(), "begining greater end");
}

TEST(Calc, test19) {
  std::vector<double> a;
  a.push_back(10000.0);
  a.push_back(10.0);
  a.push_back(10.0);
  Model model;
  model.CreditAnnuity(a);
  auto b = model.GetVectorAnnuity();

  b[0] = round(b[0] * 100) / 100;

  EXPECT_EQ(b[0], 132.15);
  EXPECT_EQ(b[2], 5858.0);
  EXPECT_EQ(b[1], 15858.0);
}

TEST(Calc, test20) {
  std::vector<double> a;
  a.push_back(10000.0);
  a.push_back(10.0);
  a.push_back(10.0);
  Model model;
  model.CreditDiff(a);
  auto b = model.GetVectorDiff();

  for (int i = -1; i != 2; ++i) {
    if (i < 0) {
      auto x = round(b[0] * 100) / 100;
      EXPECT_EQ(x, 15041.67);
      continue;
    }
    if (i < 1) {
      auto x = round(b[1] * 100) / 100;
      EXPECT_EQ(x, 5041.67);
      continue;
    }
    if (i < 2) {
      auto x = round(b[2] * 100) / 100;
      EXPECT_EQ(x, 166.67);
      continue;
    }
  }
  auto x = round(b[b.size() - 1] * 100) / 100;
  EXPECT_EQ(x, 84.03);
}

TEST(Calc, test21) {
  std::string expr = "--2";
  std::string X = "0";
  Model model;
  model.MakeCalc(expr, X);
  EXPECT_EQ(model.GetError(), "invalid syntax");
}

TEST(Calc, test22) {
  std::string expr = ")";
  std::string X = "0";
  Model model;
  model.MakeCalc(expr, X);
  EXPECT_EQ(model.GetError(), "extra bracket");
}

TEST(Calc, test23) {
  std::string expr = "Xe+";
  std::string X = "2";
  Model model;
  model.MakeCalc(expr, X);
  EXPECT_EQ(model.GetError(), "invalid syntax");
}

TEST(Calc, test24) {
  std::string expr = "XX";
  std::string X = "2";
  Model model;
  model.MakeCalc(expr, X);
  EXPECT_EQ(model.GetError(), "invalid syntax");
}

}  // namespace calc