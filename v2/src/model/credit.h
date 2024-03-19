#ifndef V2_SRC_MODEL_CREDIT_H
#define V2_SRC_MODEL_CREDIT_H

#include <cmath>
#include <vector>

namespace calc {

/// @brief Class for calculating credit
class Credit {
 public:
  /*Constructor and destructor*/
  Credit(){};
  ~Credit(){};

  /*Methods*/
  /// @brief Calculating values for an annuity loan.
  void CalcAnnuity(std::vector<double>& data);

  /// @brief Calculation of values for differentiated credit.
  void CalcDiff(std::vector<double>& data);

  /// @brief Returns a vector to the model
  /// @return std::vector<double>.
  std::vector<double> GetResultAnnuity();

  /// @brief Returns a vector to the model
  /// @return std::vector<double>.
  std::vector<double> GetResultDiff();

 private:
  /*Fields*/
  std::vector<double> resultAnnuity;
  std::vector<double> resultDiff;
};

}  // namespace calc

#endif  // V2_SRC_MODEL_CREDIT_H