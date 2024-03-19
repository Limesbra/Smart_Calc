#include "credit.h"

namespace calc {

void Credit::CalcDiff(std::vector<double>& data) {
  resultDiff.clear();
  data[1] *= 12;
  data[2] = data[2] / 100 / 12;
  double mPayment = data[0] / data[1];
  double total = 0;
  resultDiff.push_back(data[0]);
  resultDiff.push_back(data[0]);
  while (data[0] > 0) {
    double percent = data[0] * data[2];
    resultDiff.push_back(mPayment + percent);
    total += percent;
    data[0] -= mPayment;
  }
  resultDiff[0] = resultDiff[0] + total;
  resultDiff[1] = resultDiff[0] - resultDiff[1];
}

void Credit::CalcAnnuity(std::vector<double>& data) {
  resultAnnuity.clear();
  data[1] *= 12;
  data[2] = data[2] / 100 / 12;
  resultAnnuity.push_back(
      data[0] *
      (data[2] / (1 - std::pow(1 + data[2], data[1] * (-1)))));  //ежемесячныый
  resultAnnuity.push_back((std::round(resultAnnuity[0] * 100) / 100) *
                          data[1]);                     // всего
  resultAnnuity.push_back(resultAnnuity[1] - data[0]);  // переплата
}

std::vector<double> Credit::GetResultAnnuity() { return resultAnnuity; }
std::vector<double> Credit::GetResultDiff() { return resultDiff; }

}  // namespace calc