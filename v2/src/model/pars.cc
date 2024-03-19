#include "pars.h"

namespace calc {

Pars::Pars() : count(), listOfTokens(), operators("+-*/^%"){};

void Pars::ReplaceXToValue(std::string& expr, std::string& X) {
  auto pos = expr.find('X');
  expr.replace(pos, 1, X);
}

void Pars::Tokenization(std::string& expr, std::string& X) {
  ClearPars();
  while (!expr.empty()) {
    if (std::isdigit(expr[0]) || expr[0] == 'X') {
      ValueTokenization(expr, X);
    } else if (std::isalpha(expr[0])) {
      FuncTokenization(expr);
    } else if (expr[0] == '(' || expr[0] == ')') {
      BracketsTokenization(expr);
    } else if (operators.find(expr[0]) != std::string::npos) {
      OperatorTokenization(expr, X);
    } else {
      throw std::invalid_argument("invalid argument");
    }
  }
  if (this->count != 0) {
    throw std::invalid_argument("extra bracket");
  }
  if (listOfTokens.back().Type() != Token::TokenType::NUM &&
      listOfTokens.back().Type() != Token::TokenType::RBRACKET) {
    throw std::invalid_argument("invalid syntax");
  }
};

void Pars::OperatorTokenization(std::string& expr, std::string& X) {
  if (listOfTokens.empty() ||
      listOfTokens.back().Type() == Token::TokenType::LBRACKET) {
    char op = expr[0];
    expr.erase(0, 1);
    if (operators.find(expr[0]) != std::string::npos) {
      throw std::invalid_argument("invalid syntax");
    }
    if (expr.empty()) {
      throw std::invalid_argument("invalid syntax");
    }
    ValueTokenization(expr, X);
    listOfTokens.back().SetCharacter(
        Token::TokenPriority::NUM_, Token::TokenType::NUM,
        listOfTokens.back().Value() * (op == '-' ? -1.0 : 1.0));
  } else if (listOfTokens.back().Type() != Token::TokenType::NUM &&
             listOfTokens.back().Type() != Token::TokenType::RBRACKET) {
    throw std::invalid_argument("invalid syntax");
  } else {
    Token t;
    if (expr[0] == '-') {
      t.SetCharacter(Token::TokenPriority::PLUS_OR_MINUS,
                     Token::TokenType::MINUS, 0.0);
    } else if (expr[0] == '+') {
      t.SetCharacter(Token::TokenPriority::PLUS_OR_MINUS,
                     Token::TokenType::PLUS, 0.0);
    } else if (expr[0] == '*') {
      t.SetCharacter(Token::TokenPriority::MUL_OR_DIV_OR_MOD,
                     Token::TokenType::MUL, 0.0);
    } else if (expr[0] == '/') {
      t.SetCharacter(Token::TokenPriority::MUL_OR_DIV_OR_MOD,
                     Token::TokenType::DIV, 0.0);
    } else if (expr[0] == '%') {
      t.SetCharacter(Token::TokenPriority::MUL_OR_DIV_OR_MOD,
                     Token::TokenType::MOD, 0.0);
    } else if (expr[0] == '^') {
      t.SetCharacter(Token::TokenPriority::POW_, Token::TokenType::POW, 0.0);
    }
    expr.erase(0, 1);
    listOfTokens.push_back(t);
  }
}

void Pars::BracketsTokenization(std::string& expr) {
  Token t;
  if (expr[0] == '(') {
    if ((listOfTokens.back().Priority() >= 1 &&
         listOfTokens.back().Priority() <= 4) ||
        listOfTokens.back().Type() == Token::TokenType::LBRACKET ||
        listOfTokens.empty()) {
      t.SetCharacter(Token::TokenPriority::BRACKET, Token::TokenType::LBRACKET,
                     0.0);
      ++count;
    } else {
      throw std::invalid_argument("invalid syntax");
    }
  } else {
    if (listOfTokens.empty()) {
      throw std::invalid_argument("extra bracket");
    } else if (listOfTokens.back().Type() == Token::TokenType::LBRACKET) {
      throw std::invalid_argument("brackets are empty");
    }
    t.SetCharacter(Token::TokenPriority::BRACKET, Token::TokenType::RBRACKET,
                   0.0);
    --count;
  }
  expr.erase(0, 1);
  listOfTokens.push_back(t);
}

void Pars::FuncTokenization(std::string& expr) {
  if (listOfTokens.empty() ||
      (listOfTokens.back().Priority() >= 1 &&
       listOfTokens.back().Priority() <= 3) ||
      listOfTokens.back().Type() == Token::TokenType::LBRACKET) {
    Token t;
    if (expr[0] == 's' && expr[1] == 'i' && expr[2] == 'n') {
      t.SetCharacter(Token::TokenPriority::FUNCTION, Token::TokenType::SIN,
                     0.0);
      expr.erase(0, 3);
    } else if (expr[0] == 'c' && expr[1] == 'o' && expr[2] == 's') {
      t.SetCharacter(Token::TokenPriority::FUNCTION, Token::TokenType::COS,
                     0.0);
      expr.erase(0, 3);
    } else if (expr[0] == 't' && expr[1] == 'a' && expr[2] == 'n') {
      t.SetCharacter(Token::TokenPriority::FUNCTION, Token::TokenType::TAN,
                     0.0);
      expr.erase(0, 3);
    } else if (expr[0] == 'a' && expr[1] == 's' && expr[2] == 'i' &&
               expr[3] == 'n') {
      t.SetCharacter(Token::TokenPriority::FUNCTION, Token::TokenType::ASIN,
                     0.0);
      expr.erase(0, 4);
    } else if (expr[0] == 'a' && expr[1] == 'c' && expr[2] == 'o' &&
               expr[3] == 's') {
      t.SetCharacter(Token::TokenPriority::FUNCTION, Token::TokenType::ACOS,
                     0.0);
      expr.erase(0, 4);
    } else if (expr[0] == 'a' && expr[1] == 't' && expr[2] == 'a' &&
               expr[3] == 'n') {
      t.SetCharacter(Token::TokenPriority::FUNCTION, Token::TokenType::ATAN,
                     0.0);
      expr.erase(0, 4);
    } else if (expr[0] == 's' && expr[1] == 'q' && expr[2] == 'r' &&
               expr[3] == 't') {
      t.SetCharacter(Token::TokenPriority::FUNCTION, Token::TokenType::SQRT,
                     0.0);
      expr.erase(0, 4);
    } else if (expr[0] == 'l' && expr[1] == 'n') {
      t.SetCharacter(Token::TokenPriority::FUNCTION, Token::TokenType::LN, 0.0);
      expr.erase(0, 2);
    } else if (expr[0] == 'l' && expr[1] == 'o' && expr[2] == 'g') {
      t.SetCharacter(Token::TokenPriority::FUNCTION, Token::TokenType::LOG,
                     0.0);
      expr.erase(0, 3);
    } else {
      throw std::invalid_argument("invalid argument");
    }
    listOfTokens.push_back(t);
  } else {
    throw std::invalid_argument("invalid syntax");
  }
}

void Pars::ValueTokenization(std::string& expr, std::string& X) {
  Token t;
  if (expr[0] == 'X') {
    if (listOfTokens.empty() ||
        (listOfTokens.back().Type() != Token::TokenType::NUM &&
         listOfTokens.back().Type() != Token::TokenType::RBRACKET)) {
      ReplaceXToValue(expr, X);
    } else {
      throw std::invalid_argument("invalid syntax");
    }
  }
  size_t pos;
  auto d = std::stod(expr, &pos);
  if (expr[pos] == 'e') {
    ConvertFromNotation(expr, X, d);
  } else {
    expr.erase(0, pos);
  }
  t.SetCharacter(Token::TokenPriority::NUM_, Token::TokenType::NUM, d);
  listOfTokens.push_back(t);
}

void Pars::ConvertFromNotation(std::string& expr, std::string& X, double& d) {
  std::string sup = std::to_string(d);
  sup.push_back('e');
  auto p = expr.find('e');
  if (expr[p + 1] == '+' || expr[p + 1] == '-') {
    sup.push_back(expr[p + 1]);
  }
  if (expr[p + 1] == 'X' || expr[p + 2] == 'X') {
    if (expr[p + 1] == 'X') {
      expr.replace(p + 1, 1, X);
      for (int i = p + 1; isdigit(expr[0 + i]); i++) {
        sup.push_back(expr[0 + i]);
      }
    } else if (expr[p + 2] == 'X') {
      expr.replace(p + 2, 1, X);
      ;
      for (int i = p + 2; isdigit(expr[0 + i]); i++) {
        sup.push_back(expr[0 + i]);
      }
    }
  }
  if (sup.back() == '-' || sup.back() == '+') {
    throw std::invalid_argument("invalid syntax");
  }
  size_t pos = sup.length();
  d = std::stod(sup);
  expr.erase(0, pos - 1);
}

bool Pars::empty() { return listOfTokens.empty(); }

Token Pars::GetListItem() {
  Token t = listOfTokens.front();
  listOfTokens.pop_front();
  return t;
}

void Pars::ClearPars() {
  this->count = 0;
  listOfTokens.clear();
}

}  // namespace calc