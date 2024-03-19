#ifndef V2_SRC_MODEL_MODEL_H
#define V2_SRC_MODEL_MODEL_H

#include <locale>

#include "calculate.h"
#include "credit.h"
#include "graph.h"

namespace calc {

/// @brief Сlass model stores and accesses basic data and performs operations
/// determined by the business logic of the program based on requests.
class Model {
 public:
  /*Constructor and destructor*/
  Model() : calc_(new Calc()), graph_(new Graph), credit_(new Credit){};
  ~Model();

  /*Methods*/
  /// @brief Calls functions for calculation.
  void MakeCalc(std::string& expr, std::string& X);

  /// @brief Calls functions to calculate a graph.
  void MakeGraph(std::string& expr, double& xBegin, double& xEnd,
                 double& yBegin, double& yEnd);

  /// @brief Calls functions to calculate annuity credit.
  void CreditAnnuity(std::vector<double>& data);

  /// @brief Calls functions to calculate differentiated credit.
  void CreditDiff(std::vector<double>& data);

  /// @brief Returns the result from the model.
  /// @return Returns the value of the result
  double GetResult();

  /// @brief Returns an error message.
  /// @return Returns a string with text
  std::string GetError();

  /// @brief returns a vector with coordinates for the graph.
  /// @return Returns std::vector with coordinates
  std::vector<double> GetVectorXfromGraph();

  /// @brief returns a vector with coordinates for the graph.
  /// @return Returns std::vector with coordinates
  std::vector<double> GetVectorYfromGraph();

  /// @brief returns a vector with values for annuity.
  /// @return Returns std::vector with values
  std::vector<double> GetVectorAnnuity();

  /// @brief returns a vector with values for differentiated.
  /// @return Returns std::vector with values
  std::vector<double> GetVectorDiff();

 private:
  /*Methods*/
  /// @brief Clears the model.
  void ClearModel();

  /*Fields*/
  Calc* calc_;
  Graph* graph_;
  Credit* credit_;
  double result;
  std::string error;
};

}  // namespace calc

#endif  // V2_SRC_MODEL_MODEL_H
