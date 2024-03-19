#ifndef V2_SRC_CONTROLLER_H
#define V2_SRC_CONTROLLER_H

#include "../model/model.h"

namespace calc {

class Controller {
 public:
  Controller(){};
  Controller(Model* model) : model(model){};
  ~Controller(){};

  int LetsCalc(std::string& expr, std::string& X);
  int LetsGraph(std::string& expr, double& xBegin, double& xEnd, double& yBegin,
                double& yEnd);
  void LetsAnnuity(std::vector<double>& data);
  void LetsDiff(std::vector<double>& data);

  double GetResultFromModel();
  std::string GetErrorFromModel();
  std::vector<double> GetVectorXfromModel();
  std::vector<double> GetVectorYfromModel();
  std::vector<double> GetAnnuity();
  std::vector<double> GetDiff();

 private:
  Model* model;
};
}  // namespace calc

#endif  // V2_SRC_CONTROLLER_H