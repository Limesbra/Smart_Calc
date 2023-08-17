#ifndef SmartCalc_v1_H
#define SmartCalc_v1_H

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EPS 0.0000001

typedef enum {
  NUM,
  plus,
  minus,
  mult,
  DIV,
  MOD,
  POW,
  SQRT,
  LOG,
  LN,
  SIN,
  ASIN,
  COS,
  ACOS,
  TAN,
  ATAN,
  leftScobe,
  rightScobe
} lexeme_type;

typedef enum {
  variable = -1,
  number,
  plus_or_minus,
  mult_or_div,
  mod = 2,
  PPOW,
  PSQRT = -2,
  log_or_ln = -3,
  trigonometry = -4,
  scobe = 6
} lexeme_priority;

typedef struct {
  double value[255];
  int priority[255];
  int type[255];
  int counter;
} L;

int S21_SmartCalc(char *expression, char *expression_for_x, double *result);
int parser(char *expression, char *expression_for_x, L *pars);
void setInputLexeme(L *pars, double num, lexeme_type type,
                    lexeme_priority type_1, int *step);
int trigonometryCheck(char *expression, L *pars, int *error);
int scobeChecker(char *expression, L *pars, int *s_counter, int *error);
int logChecker(char *expression, L *pars);
int arithmeticSign(char *expression, L *pars, int *error);
int validSign(char *expression, L *pars);
int constAnalyze(char *expression, char *expression_for_x, L *pars, int *error);
int handlerNum(char **expression, L *pars, int *error);
void RPN(L *pars, L *output, L *stack);
void setStackZero(L *stack);
void mathProcess(L *output, L *stack, double **result);
void multDivMod(L *output, L *stack, int i);
void mathFunction(L *output, L *stack, int i);
void plusMinusOperators(L *output, L *stack, int i);
void isNumber(L *output, L *stack, int i);
void powOperator(L *output, L *stack, int i);
void RpnMathOperators(L *pars, L *stack, int i);
void RpnScobe(L *pars, L *output, L *stack, int i);


#endif