#ifndef V2_SRC_MODEL_CALCULATE_H
#define V2_SRC_MODEL_CALCULATE_H

#include <cmath>
#include <map>

#include "RPN.h"

namespace calc {

/// @brief functions for binary calculation
inline double Sum(double a, double b) { return a + b; };
inline double Sub(double a, double b) { return a - b; };
inline double Mul(double a, double b) { return a * b; };
inline double Div(double a, double b) { return a / b; };
inline double Pow(double a, double b) { return std::pow(a, b); };
inline double Mod(double a, double b) { return std::fmod(a, b); };

/// @brief functions for unary calculation
inline double Sin(double a) { return sin(a); };
inline double Cos(double a) { return cos(a); };
inline double Tan(double a) { return tan(a); };
inline double Asin(double a) { return asin(a); };
inline double Acos(double a) { return acos(a); };
inline double Atan(double a) { return atan(a); };
inline double Sqrt(double a) { return sqrt(a); };
inline double Log(double a) { return std::log10(a); };
inline double Ln(double a) { return std::log(a); };

/// @brief Class for evaluating expressions
class Calc {
  typedef double (*func_ptr_bin)(double, double);
  typedef double (*func_ptr_un)(double);

 public:
  /*Constructor and destructor*/
  Calc();
  ~Calc() { delete r; }

  /*Methods*/
  /// @brief Computes the result of an expression in reverse Polish notation
  /// @param expr The line with expression
  /// @param X stores the value of a variable Х
  /// @return Returns the error code
  int Calculate(std::string& expr, std::string& X);

  /// @brief Pops an operand from the stack
  /// @return Returns the value of the operand
  double TakeOperand();

  /// @brief Pops an operand from the stack
  /// @return Returns the result of expression
  double GetResult();

  /// @brief Clears class fields
  void ClearCalc();

 private:
  /*Fields*/
  RPN* r;
  std::stack<double> stackForCalc;
  std::map<int, func_ptr_bin> funcBin;
  std::map<int, func_ptr_un> funcUn;
  double result;
};
}  // namespace calc

#endif  // V2_SRC_MODEL_CALCULATE_H