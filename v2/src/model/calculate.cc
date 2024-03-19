#include "calculate.h"

namespace calc {

Calc::Calc() : r(new RPN()), stackForCalc(), funcBin(), funcUn(), result(0.0) {
  funcBin.insert({1, Sum});
  funcBin.insert({2, Sub});
  funcBin.insert({3, Mul});
  funcBin.insert({4, Div});
  funcBin.insert({5, Mod});
  funcBin.insert({6, Pow});
  funcUn.insert({10, Sin});
  funcUn.insert({11, Asin});
  funcUn.insert({12, Cos});
  funcUn.insert({13, Acos});
  funcUn.insert({14, Tan});
  funcUn.insert({15, Atan});
  funcUn.insert({7, Sqrt});
  funcUn.insert({8, Log});
  funcUn.insert({9, Ln});
}

int Calc::Calculate(std::string& expr, std::string& X) {
  ClearCalc();
  r->ToPostfix(expr, X);
  while (!r->Empty()) {
    auto t = r->GetToken();
    if (t.Type() == Token::TokenType::NUM) {
      stackForCalc.push(t.Value());
    } else if (t.Type() != Token::TokenType::NUM) {
      if (t.Priority() > 0 && t.Priority() < 4) {
        auto num1 = TakeOperand();
        auto num2 = TakeOperand();
        auto it = funcBin.find(t.Type());
        double num3 = it->second(num2, num1);
        stackForCalc.push(num3);
      } else if (t.Priority() == Token::TokenPriority::FUNCTION) {
        auto num1 = TakeOperand();
        auto it = funcUn.find(t.Type());
        double num2 = it->second(num1);
        stackForCalc.push(num2);
      }
    }
  }
  result = stackForCalc.top();
  stackForCalc.pop();
  return 0;
};

double Calc::TakeOperand() {
  auto num = stackForCalc.top();
  stackForCalc.pop();
  return num;
}

double Calc::GetResult() { return result; };

void Calc::ClearCalc() {
  while (!stackForCalc.empty()) {
    stackForCalc.pop();
  }
}

}  // namespace calc