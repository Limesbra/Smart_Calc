#include "graph.h"

namespace calc {

void Graph::CheckRangeX(double& xBegin, double& xEnd) {
  if (xBegin > xEnd) {
    throw std::invalid_argument("begining greater end");
  } else if (xBegin == xEnd) {
    throw std::invalid_argument("begining equal end");
  }
}

void Graph::CheckRangeY(double& yBegin, double& yEnd) {
  if (yBegin > yEnd) {
    throw std::invalid_argument("begining greater end");
  } else if (yBegin == yEnd) {
    throw std::invalid_argument("begining equal end");
  }
}

void Graph::ClearDataGraph() {
  xValue.clear();
  yValue.clear();
}

void Graph::SetX(double& v) { xValue.push_back(v); }

void Graph::SetY(double& res) { yValue.push_back(res); }

std::vector<double> Graph::GetVectorX() { return xValue; }

std::vector<double> Graph::GetVectorY() { return yValue; }

}  // namespace calc