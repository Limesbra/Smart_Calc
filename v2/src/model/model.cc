#include "model.h"

namespace calc {

Model::~Model() {
  delete graph_;
  delete calc_;
  delete credit_;
}

void Model::MakeCalc(std::string& expr, std::string& X) {
  try {
    ClearModel();
    setlocale(LC_ALL, "C");
    calc_->Calculate(expr, X);
    result = calc_->GetResult();
    this->error = "ok";
  } catch (std::invalid_argument& ex) {
    if (std::string(ex.what()) == "invalid argument") {
      this->error = "invalid argument";
    } else if (std::string(ex.what()) == "extra bracket") {
      this->error = "extra bracket";
    } else if (std::string(ex.what()) == "brackets are empty") {
      this->error = "brackets are empty";
    } else if (std::string(ex.what()) == "invalid syntax") {
      this->error = "invalid syntax";
    }
  }
}

void Model::MakeGraph(std::string& expr, double& xBegin, double& xEnd,
                      double& yBegin, double& yEnd) {
  try {
    graph_->ClearDataGraph();
    graph_->CheckRangeX(xBegin, xEnd);
    graph_->CheckRangeY(yBegin, yEnd);
    std::string s = std::to_string(xBegin);
    double v = xBegin;
    for (int i = 0; i <= 500; i++) {
      std::string c = expr;
      MakeCalc(c, s);
      auto res = GetResult();
      graph_->SetY(res);
      graph_->SetX(v);
      v += (xEnd - xBegin) / 500;
      s.clear();
      s = std::to_string(v);
      c.clear();
    }
  } catch (std::invalid_argument& ex) {
    if (std::string(ex.what()) == "begining greater end") {
      this->error = "begining greater end";
    } else if (std::string(ex.what()) == "begining equal end") {
      this->error = "begining equal end";
    }
  }
}

void Model::CreditAnnuity(std::vector<double>& data) {
  credit_->CalcAnnuity(data);
}

void Model::CreditDiff(std::vector<double>& data) { credit_->CalcDiff(data); }

double Model::GetResult() { return result; }

std::string Model::GetError() { return error; }

void Model::ClearModel() {
  result = 0;
  error = "";
}

std::vector<double> Model::GetVectorXfromGraph() {
  return graph_->GetVectorX();
}

std::vector<double> Model::GetVectorYfromGraph() {
  return graph_->GetVectorY();
}

std::vector<double> Model::GetVectorAnnuity() {
  return credit_->GetResultAnnuity();
}

std::vector<double> Model::GetVectorDiff() { return credit_->GetResultDiff(); }

}  // namespace calc
