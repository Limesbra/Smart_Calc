#ifndef V2_SRC_MODEL_PARS_H
#define V2_SRC_MODEL_PARS_H

#include <list>
#include <sstream>

#include "token.h"

namespace calc {

/// @brief Class for token parsing and error handling.
class Pars {
 public:
  /*Constructor and destructor*/
  Pars();
  ~Pars() = default;

  /*Methods*/

  /// @brief Translating an expression into tokens.
  void Tokenization(std::string& expr, std::string& X);

  /// @brief Return with removal of the first token from the list.
  /// @return Returns token from the list.
  Token GetListItem();

  /// @brief Сhecking for emptiness.
  /// @return true or false.
  bool empty();

  /// @brief Clears the list.
  void ClearPars();

 private:
  /*Methods*/
  /// @brief Ceplaces x with the value.
  void ReplaceXToValue(std::string& expr, std::string& X);

  /// @brief Checks and creates an operator token.
  void OperatorTokenization(std::string& expr, std::string& X);

  /// @brief Checks and creates a bracket token.
  void BracketsTokenization(std::string& expr);

  /// @brief Checks and creates a function token.
  void FuncTokenization(std::string& expr);

  /// @brief Checks and creates a number token.
  void ValueTokenization(std::string& expr, std::string& X);

  /// @brief Convert scientific notation.
  void ConvertFromNotation(std::string& expr, std::string& X, double& d);

  /*Fields*/
  int count;
  std::list<Token> listOfTokens;
  std::string operators;
};

}  // namespace calc

#endif  // V2_SRC_MODEL_PARS_H
