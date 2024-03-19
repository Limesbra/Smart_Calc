
#include "RPN.h"

namespace calc {

void RPN::ToPostfix(std::string& expr, std::string& X) {
  ClearRPN();
  pars->Tokenization(expr, X);
  for (; !pars->empty();) {
    auto t = pars->GetListItem();
    if (t.Type() == Token::TokenType::NUM) {
      out.push(t);
    } else if (t.Priority() == Token::TokenPriority::BRACKET) {
      if (t.Type() == Token::TokenType::LBRACKET) {
        stack.push(t);
      } else {
        while (stack.top().Type() != Token::TokenType::LBRACKET) {
          out.push(stack.top());
          stack.pop();
        }
        stack.pop();
      }
    } else if (t.Priority() == Token::TokenPriority::FUNCTION) {
      while (!stack.empty() && stack.top().Priority() >= t.Priority()) {
        out.push(stack.top());
        stack.pop();
      }
      stack.push(t);
    } else if (t.Priority() > 0 && t.Priority() <= 3) {
      while (!stack.empty() &&
             (t.Priority() < 3 ? stack.top().Priority() >= t.Priority()
                               : stack.top().Priority() > t.Priority())) {
        out.push(stack.top());
        stack.pop();
      }
      stack.push(t);
    }
  }
  while (!stack.empty()) {
    out.push(stack.top());
    stack.pop();
  }
}

bool RPN::Empty() { return out.empty(); }

Token RPN::GetToken() {
  auto t = out.front();
  out.pop();
  return t;
}

void RPN::ClearRPN() {
  while (!out.empty() || !stack.empty()) {
    if (!out.empty()) {
      out.pop();
    }
    if (!stack.empty()) {
      stack.pop();
    }
  }
}

}  // namespace calc
