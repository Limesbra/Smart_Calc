#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "SmartCalc_v1.h"

/*--------------------SmartCalc_v1--------------------*/

START_TEST(SmartCalc_test_1) {
  double result = 0;
  char expression[255] = "-5";
  double expression_for_x = 0.0;

  ck_assert_int_eq(SmartCalc(expression, expression_for_x, &result), 0);
  ck_assert_double_eq_tol(result, -5.0, EPS);
}
END_TEST

/*-------------------------------------------------*/

START_TEST(SmartCalc_test_2) {
  double result = 0;
  char expression[255] = "aafafxcdvrdbd566wfcwf  segwg sgegrf";
  double expression_for_x = 0.0;

  ck_assert_int_eq(SmartCalc(expression, expression_for_x, &result), 1);
}
END_TEST

/*-------------------------------------------------*/

START_TEST(SmartCalc_test_3) {
  double result = 0;
  char expression[255] = "0+4*6/12-0";
  double expression_for_x = 0.0;

  ck_assert_int_eq(SmartCalc(expression, expression_for_x, &result), 0);
  ck_assert_double_eq_tol(result, 2.0, EPS);
}
END_TEST

/*-------------------------------------------------*/

START_TEST(SmartCalc_test_4) {
  double result = 0;
  char expression[255] = "2^3^2";
  double expression_for_x = 0.0;

  ck_assert_int_eq(SmartCalc(expression, expression_for_x, &result), 0);
  ck_assert_double_eq_tol(result, 512.0, EPS);
}
END_TEST

/*-------------------------------------------------*/

START_TEST(SmartCalc_test_5) {
  double result = 0;
  char expression[255] = "sqrt(4)";
  double expression_for_x = 0.0;

  ck_assert_int_eq(SmartCalc(expression, expression_for_x, &result), 0);
  ck_assert_double_eq_tol(result, 2.0, EPS);
}
END_TEST

/*-------------------------------------------------*/

START_TEST(SmartCalc_test_6) {
  double result = 0;
  char expression[255] = "log(10)+ln(4)";
  double expression_for_x = 0.0;

  ck_assert_int_eq(SmartCalc(expression, expression_for_x, &result), 0);
  ck_assert_double_eq_tol(result, 2.38629436112, EPS);
}
END_TEST

/*-------------------------------------------------*/

START_TEST(SmartCalc_test_7) {
  double result = 0;
  char expression[255] = "acos(0)+cos(1)+asin(1)+sin(0)+atan(0)+tan(1)";
  double expression_for_x = 0.0;

  ck_assert_int_eq(SmartCalc(expression, expression_for_x, &result), 0);
  ck_assert_double_eq_tol(result, 5.23930266, EPS);
}
END_TEST

/*-------------------------------------------------*/

START_TEST(SmartCalc_test_8) {
  double result = 0;
  char expression[255] = "cos(pi)";
  double expression_for_x = 0.0;

  ck_assert_int_eq(SmartCalc(expression, expression_for_x, &result), 0);
  ck_assert_double_eq_tol(result, -1.0, EPS);
}
END_TEST

/*-------------------------------------------------*/

START_TEST(SmartCalc_test_9) {
  double result = 0;
  char expression[255] = "X^2";
  double expression_for_x = 2.0;

  ck_assert_int_eq(SmartCalc(expression, expression_for_x, &result), 0);
  ck_assert_double_eq_tol(result, 4.0, EPS);
}
END_TEST

/*-------------------------------------------------*/

START_TEST(SmartCalc_test_10) {
  double result = 0;
  char expression[255] = "+e";
  double expression_for_x = 0.0;

  ck_assert_int_eq(SmartCalc(expression, expression_for_x, &result), 0);
  ck_assert_double_eq_tol(result, 2.71828182, EPS);
}
END_TEST

/*-------------------------------------------------*/

START_TEST(SmartCalc_test_11) {
  double result = 0;
  char expression[255] = "(((()))";
  double expression_for_x = 0.0;

  ck_assert_int_eq(SmartCalc(expression, expression_for_x, &result), 1);
}
END_TEST

/*-------------------------------------------------*/

START_TEST(SmartCalc_test_12) {
  double result = 0;
  char expression[255] = "7acos";
  double expression_for_x = 0.0;

  ck_assert_int_eq(SmartCalc(expression, expression_for_x, &result), 1);
}
END_TEST

/*-------------------------------------------------*/

START_TEST(SmartCalc_test_13) {
  double result = 0;
  char expression[255] = "srt";
  double expression_for_x = 0.0;

  ck_assert_int_eq(SmartCalc(expression, expression_for_x, &result), 1);
}
END_TEST

/*-------------------------------------------------*/

START_TEST(SmartCalc_test_14) {
  double result = 0;
  char expression[255] = ")(";
  double expression_for_x = 0.0;

  ck_assert_int_eq(SmartCalc(expression, expression_for_x, &result), 1);
}
END_TEST

/*-------------------------------------------------*/

START_TEST(SmartCalc_test_15) {
  double result = 0;
  char expression[255] = "10%2";
  double expression_for_x = 0.0;

  ck_assert_int_eq(SmartCalc(expression, expression_for_x, &result), 0);
}
END_TEST

/*-------------------------------------------------*/

START_TEST(SmartCalc_test_16) {
  double result = 0;
  char expression[255] = "3+(4*4)";
  double expression_for_x = 0.0;

  ck_assert_int_eq(SmartCalc(expression, expression_for_x, &result), 0);
  ck_assert_double_eq_tol(result, 19.0, EPS);
}
END_TEST

/*-------------------------------------------------*/

START_TEST(SmartCalc_test_17) {
  double result = 0;
  char expression[255] = "*4";
  double expression_for_x = 0.0;

  ck_assert_int_eq(SmartCalc(expression, expression_for_x, &result), 1);
}
END_TEST

/*-------------------------------------------------*/

START_TEST(SmartCalc_test_18) {
  double year = 1.0;
  double percent = 10.0;
  double period = year * 12;
  double size = 1000000.0;
  double ante = percent / (100.0 * 12);
  double mDebt = size / period;
  double total = 0.0;
  double overpay = 0.0;
  double *payt = (double *)calloc(sizeof(double), period);
  int *nPayment = (int *)calloc(sizeof(int), period);

  double true[12] = {91666.670, 90972.220, 90277.780, 89583.330,
                     88888.890, 88194.440, 87500.000, 86805.560,
                     86111.110, 85416.670, 84722.220, 84027.780};
  double total_true = 1054166.670;
  double overpay_true = 54166.670;

  creditCalcDif(size, ante, mDebt, payt, nPayment, &total, &overpay);

  for (int i = 0; i < period; i++) {
    ck_assert_double_eq_tol(payt[i], true[i], 0.01);
  }

  ck_assert_double_eq_tol(total, total_true, 0.01);
  ck_assert_double_eq_tol(overpay, overpay_true, 0.01);

  free(payt);
  free(nPayment);
}
END_TEST

/*-------------------------------------------------*/

START_TEST(SmartCalc_test_19) {
  double year = 1.0;
  double percent = 10.0;
  double period = year * 12;
  double size = 1000000.0;
  double ante = percent / (100.0 * 12);
  double total = 0.0;
  double overpay = 0.0;
  double result = 0.0;

  double result_true = 87915.890;
  double total_true = 1054990.680;
  double overpay_true = 54990.680;

  creditCalcAnnuity(size, ante, period, &total, &overpay, &result);

  ck_assert_double_eq_tol(result, result_true, 0.01);

  ck_assert_double_eq_tol(total, total_true, 0.01);
  ck_assert_double_eq_tol(overpay, overpay_true, 0.01);
}
END_TEST

/*-------------------------------------------------*/

int main() {
  Suite *test = suite_create("calc");
  TCase *tc_1 = tcase_create("calc");
  SRunner *sr = srunner_create(test);
  // srunner_set_fork_status(sr, CK_NOFORK);
  int fail;
  suite_add_tcase(test, tc_1);

  tcase_add_test(tc_1, SmartCalc_test_1);
  tcase_add_test(tc_1, SmartCalc_test_2);
  tcase_add_test(tc_1, SmartCalc_test_3);

  tcase_add_test(tc_1, SmartCalc_test_4);
  tcase_add_test(tc_1, SmartCalc_test_5);
  tcase_add_test(tc_1, SmartCalc_test_6);

  tcase_add_test(tc_1, SmartCalc_test_7);
  tcase_add_test(tc_1, SmartCalc_test_8);
  tcase_add_test(tc_1, SmartCalc_test_9);
  tcase_add_test(tc_1, SmartCalc_test_10);
  tcase_add_test(tc_1, SmartCalc_test_11);
  tcase_add_test(tc_1, SmartCalc_test_12);
  tcase_add_test(tc_1, SmartCalc_test_13);
  tcase_add_test(tc_1, SmartCalc_test_14);
  tcase_add_test(tc_1, SmartCalc_test_15);
  tcase_add_test(tc_1, SmartCalc_test_16);
  tcase_add_test(tc_1, SmartCalc_test_17);
  tcase_add_test(tc_1, SmartCalc_test_18);
  tcase_add_test(tc_1, SmartCalc_test_19);

  srunner_run_all(sr, CK_ENV);
  fail = srunner_ntests_failed(sr);
  srunner_free(sr);
  return fail == 0 ? 0 : 1;
}
