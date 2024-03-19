#ifndef V2_SRC_MODEL_GRAPH_H
#define V2_SRC_MODEL_GRAPH_H

#include <stdexcept>
#include <vector>

namespace calc {

/// @brief Class for checking and storing data for a graph.
class Graph {
 public:
  /*Constructor and destructor*/
  Graph(){};
  ~Graph(){};

  /*Methods*/

  /// @brief x range check.
  void CheckRangeX(double& xBegin, double& xEnd);

  /// @brief y range check.
  void CheckRangeY(double& yBegin, double& yEnd);

  /// @brief Writes value to vector.
  void SetX(double& v);

  /// @brief Writes value to vector.
  void SetY(double& res);

  /// @brief Returns a vector to the model.
  /// @return std::vector<double>.
  std::vector<double> GetVectorX();

  /// @brief Returns a vector to the model.
  /// @return std::vector<double>.
  std::vector<double> GetVectorY();

  /// @brief Checking for emptiness.
  void ClearDataGraph();

 private:
  /*Fields*/
  std::vector<double> xValue;
  std::vector<double> yValue;
};
}  // namespace calc

#endif  // V2_SRC_MODEL_GRAPH_H