#ifndef V2_SRC_MODEL_TOKEN_H
#define V2_SRC_MODEL_TOKEN_H

#include <iostream>

namespace calc {

/// @brief Class for storing tokens
class Token {
 public:
  enum TokenType {
    NUM = 0,
    PLUS,
    MINUS,
    MUL,
    DIV,
    MOD,
    POW,
    SQRT,
    LOG,
    LN,
    SIN,
    ASIN,
    COS,
    ACOS,
    TAN,
    ATAN,
    LBRACKET,
    RBRACKET
  };

  enum TokenPriority {
    NUM_ = 0,
    PLUS_OR_MINUS,
    MUL_OR_DIV_OR_MOD,
    POW_,
    FUNCTION,
    BRACKET = 0
  };

  /*Constructor and destructor*/
  Token() = default;
  ~Token() = default;

  /*Methods*/
  /// @brief Returns priority
  /// @return Returns the value from enum TokenPriority
  int Priority();

  /// @brief Returns type
  /// @return Returns the value from enum TokenType
  int Type();

  /// @brief Returns value
  /// @return Returns the value if it is a number
  double Value();

  /// @brief Writes data about a token
  void SetCharacter(TokenPriority a, TokenType b, double c);

 private:
  /*Fields*/
  TokenPriority priority;
  TokenType type;
  double value;
};

}  // namespace calc

#endif  // V2_SRC_MODEL_TOKEN_H