#include "token.h"

namespace calc {

int Token::Priority() { return priority; }
int Token::Type() { return type; }
double Token::Value() { return value; };

void Token::SetCharacter(TokenPriority a, TokenType b, double c) {
  priority = a;
  type = b;
  value = c;
}

}  // namespace calc