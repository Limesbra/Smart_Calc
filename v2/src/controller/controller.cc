#include "controller.h"

namespace calc {

int Controller::LetsCalc(std::string& expr, std::string& X) {
  model->MakeCalc(expr, X);
  if (model->GetError() == "ok") {
    return 0;
  } else {
    return 1;
  }
}

int Controller::LetsGraph(std::string& expr, double& xBegin, double& xEnd,
                          double& yBegin, double& yEnd) {
  model->MakeGraph(expr, xBegin, xEnd, yBegin, yEnd);
  if (model->GetError() == "ok") {
    return 0;
  } else {
    return 1;
  }
}

void Controller::LetsAnnuity(std::vector<double>& data) {
  model->CreditAnnuity(data);
}

void Controller::LetsDiff(std::vector<double>& data) {
  model->CreditDiff(data);
}

double Controller::GetResultFromModel() { return model->GetResult(); }

std::string Controller::GetErrorFromModel() { return model->GetError(); }

std::vector<double> Controller::GetVectorXfromModel() {
  return model->GetVectorXfromGraph();
}

std::vector<double> Controller::GetVectorYfromModel() {
  return model->GetVectorYfromGraph();
}

std::vector<double> Controller::GetAnnuity() {
  return model->GetVectorAnnuity();
}
std::vector<double> Controller::GetDiff() { return model->GetVectorDiff(); }

}  // namespace calc