#ifndef V2_SRC_MODEL_RPN_H
#define V2_SRC_MODEL_RPN_H

#include <queue>
#include <stack>

#include "pars.h"

namespace calc {

/// @brief Class for converting to reverse Polish notation
class RPN {
 public:
  /*Constructor and destructor*/
  RPN()
      : pars(new Pars()),
        out(std::queue<Token>()),
        stack(std::stack<Token>()){};
  ~RPN() { delete pars; };

  /*Methods*/
  /// @brief Converting to reverse Polish notation.
  void ToPostfix(std::string& expr, std::string& X);

  /// @brief Checks the output string for emptyness.
  bool Empty();

  /// @brief Returns the token from the output queue.
  /// @return token;
  Token GetToken();

  /// @brief Clears the output queue and stack.
  void ClearRPN();

 private:
  /*Fields*/
  Pars* pars;
  std::queue<Token> out;
  std::stack<Token> stack;
};

}  // namespace calc

#endif  // V2_SRC_MODEL_RPN_H