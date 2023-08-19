#include "SmartCalc_v1.h"


int S21_SmartCalc(char *expression, double expression_for_x, double *result) {
  L pars;
  L output;
  L stack;
  toZero(&pars);
  toZero(&output);
  toZero(&stack);
  int error = 0;
  error = parser(expression, expression_for_x, &pars);
  if (error == 0) {
    RPN(&pars, &output, &stack);
    mathProcess(&output, &stack, &result);
  }
  return error;
}

int parser(char *expression, double expression_for_x, L *pars) {
  int error = 0;
  int s_counter = 0;
  while (*expression != '\0' && error == 0) {
    char *check = expression;
    handlerNum(&expression, pars, &error);
    expression += trigonometryCheck(expression, pars, &error);
    expression += scobeChecker(expression, pars, &s_counter, &error);
    expression += logChecker(expression, pars);
    expression += arithmeticSign(expression, pars);
    expression += constAnalyze(expression, expression_for_x, pars, &error);

    if (expression == check) {
      error = 1;
    }
  }
  if(s_counter != 0){error = 1;}
  return error;
}

void setInputLexeme(L *pars, double num, lexeme_type type,
                    lexeme_priority type_1, int *step) {
  pars->value[pars->counter] = num;
  pars->priority[pars->counter] = type_1;
  pars->type[pars->counter] = type;
  pars->counter += 1;
  *step += 1;
}

int trigonometryCheck(char *expression, L *pars, int *error) {
  int step = 0;
  if (*expression != '\0') {
    if (*expression == 'a' && *(expression + 1) == 't' &&
        *(expression + 2) == 'a' && *(expression + 3) == 'n') {
      setInputLexeme(pars, 0, ATAN, trigonometry, &step);
      step += 3;
    } else if (*expression == 'a' && *(expression + 1) == 's' &&
               *(expression + 2) == 'i' && *(expression + 3) == 'n') {
      setInputLexeme(pars, 0, ASIN, trigonometry, &step);
      step += 3;
    } else if (*expression == 'a' && *(expression + 1) == 'c' &&
               *(expression + 2) == 'o' && *(expression + 3) == 's') {
      setInputLexeme(pars, 0, ACOS, trigonometry, &step);
      step += 3;
    } else if (*expression == 't' && *(expression + 1) == 'a' &&
               *(expression + 2) == 'n') {
      setInputLexeme(pars, 0, TAN, trigonometry, &step);
      step += 2;
    } else if (*expression == 's' && *(expression + 1) == 'i' &&
               *(expression + 2) == 'n') {
      setInputLexeme(pars, 0, SIN, trigonometry, &step);
      step += 2;
    } else if (*expression == 'c' && *(expression + 1) == 'o' &&
               *(expression + 2) == 's') {
      setInputLexeme(pars, 0, COS, trigonometry, &step);
      step += 2;
    } else if (*expression == 's' && *(expression + 1) != 'q' &&
               *(expression + 2) != 'r' && *(expression + 3) != 't') {
      *error = 1;
    }
  }
  return step;
}

int scobeChecker(char *expression, L *pars, int *s_counter, int *error) {
  int step = 0;
  if (*expression != '\0' && (*expression == '(' || *expression == ')')) {
    if (*expression == '(' && (*(expression + 1) != ')' || *(expression + 1) != '\0')) {
      setInputLexeme(pars, 0, leftScobe, scobe, &step);
      *s_counter += 1;
    } else if (*expression == ')' && *s_counter != 0) {
      setInputLexeme(pars, 0, rightScobe, scobe, &step);
      *s_counter -= 1;
    } else {
      *error = 1;
    }
  }

  return step;
}

int logChecker(char *expression, L *pars) {
  int step = 0;
  if (*expression != '\0') {
    if (*expression == 'l' && *(expression + 1) == 'o' &&
        *(expression + 2) == 'g' && *(expression + 3) == '(') {
      setInputLexeme(pars, 0, LOG, log_or_ln, &step);
      step += 2;
    } else if (*expression == 'l' && *(expression + 1) == 'n' &&
               *(expression + 2) == '(') {
      setInputLexeme(pars, 0, LN, log_or_ln, &step);
      step += 1;
    }
  }
  return step;
}

int arithmeticSign(char *expression, L *pars) {
  int step = 0;
  int valid = validSign(expression, pars);
  if (*expression == '+' && valid == 1) {
    if(pars->counter == 0 || *(expression-1) == '('){
      setInputLexeme(pars, 0, NUM, number, &step);
      step = 0;
    }
    setInputLexeme(pars, 0, plus, plus_or_minus, &step);
  } else if (*expression == '-' && valid) {
    if(pars->counter == 0 || *(expression-1) == '('){
      setInputLexeme(pars, 0, NUM, number, &step);
      step = 0;
    }
    setInputLexeme(pars, 0, minus, plus_or_minus, &step);
  } else if (*expression == '*' && valid) {
    setInputLexeme(pars, 0, mult, mult_or_div, &step);
  } else if (*expression == '/' && valid) {
    setInputLexeme(pars, 0, DIV, mult_or_div, &step);
  } else if (*expression == '%' && valid) {
    setInputLexeme(pars, 0, MOD, mod, &step);
  } else if (*expression == '^' && valid) {
    setInputLexeme(pars, 0, POW, PPOW, &step);
  } else if (*expression == 's' && *(expression + 1) == 'q' &&
             *(expression + 2) == 'r' && *(expression + 3) == 't' && valid) {
    setInputLexeme(pars, 0, SQRT, PSQRT, &step);
    step += 3;
  }
  return step;
}

int validSign(char *expression, L *pars) {
  int valid = 0;
  if (isdigit(*(expression + 1)) != 0 || *(expression + 1) == 'X') {
    valid++;
  } else if (*(expression + 1) == '(') {
    valid++;
  } else if (*(expression + 1) == 'l') {
    valid++;
  } else if (*(expression + 1) == 'a') {
    valid++;
  } else if (*(expression + 1) == 'c' || *(expression + 1) == 's' ||
             *(expression + 1) == 't') {
    valid++;
  } else if ((*expression == '*' || *expression == '/' || *expression == '%' ||
              *expression == '^') &&
             pars->counter != 0) {
    valid++;
  } else if (*expression == 's' && *(expression + 1) == 'q' &&
             *(expression + 2) == 'r' && *(expression + 3) == 't') {
    valid++;
  }
  if (valid > 0) {
    valid = 1;
  }
  return valid;
}

int constAnalyze(char *expression, double expression_for_x, L *pars,
                 int *error) {
  int step = 0;
  if (*expression != '\0') {
    if (*expression == 'e') {
      setInputLexeme(pars, M_E, NUM, number, &step);
    } else if (*expression == 'p' && *(expression+1) == 'i') {
      setInputLexeme(pars, M_PI, NUM, number, &step);
      step += 1;
    } else if (*expression == 'X') {
      setInputLexeme(pars, expression_for_x, NUM, number, &step);
    }
  }
  return step;
}

int handlerNum(char **expression, L *pars, int *error) {
  int step = 0;
  if(isdigit(**expression)){
    double num = strtod(*expression, expression);
    setInputLexeme(pars, num, NUM, number, &step);
    if(**expression == '(' || **expression == 'a' || **expression == 'c' || **expression == 's' || **expression == 't' || **expression == 'l'){*error = 1;}
  }
  return 0;
}

void RPN(L *pars, L *output, L *stack) {
  for (int i = 0; i < pars->counter; i++) {
    if (pars->type[i] == NUM) {
      output->value[0 + output->counter] = pars->value[i];
      output->type[0 + output->counter] = pars->type[i];
      output->priority[0 + output->counter] = pars->priority[i];
      output->counter += 1;
    } else if (pars->type[i] == leftScobe || pars->type[i] == rightScobe) {
      RpnScobe(pars, output, stack, i);
    } else if (pars->priority[i] == PSQRT || pars->priority[i] == log_or_ln ||
               pars->priority[i] == trigonometry) {
      stack->value[0 + stack->counter] = pars->value[i];
      stack->type[0 + stack->counter] = pars->type[i];
      stack->priority[0 + stack->counter] = pars->priority[i];
      stack->counter += 1;
    } else if (pars->priority[i] == plus_or_minus ||
               pars->priority[i] == mult_or_div || pars->priority[i] == mod ||
               pars->priority[i] == PPOW) {
      RpnMathOperators(pars, stack, i);
    }
  }
  while (stack->counter != 0) {
    output->value[0 + output->counter] = stack->value[stack->counter - 1];
    output->type[0 + output->counter] = stack->type[stack->counter - 1];
    output->priority[0 + output->counter] = stack->priority[stack->counter - 1];
    output->counter += 1;
    stack->counter -= 1;
  }
}

void mathProcess(L *output, L *stack, double **result) {
  toZero(stack);
  for (int i = 0; i < output->counter; i++) {
    if (output->type[i] == NUM) {
      isNumber(output, stack, i);
    } else if (output->priority[i] == PSQRT ||
               output->priority[i] == log_or_ln ||
               output->priority[i] == trigonometry) {
      mathFunction(output, stack, i);
    } else if (output->priority[i] == plus_or_minus) {
      plusMinusOperators(output, stack, i);
    } else if (output->priority[i] == mult_or_div ||
               output->priority[i] == mod) {
      multDivMod(output, stack, i);
    } else if (output->priority[i] == PPOW) {
      powOperator(stack);
    }
  }
  **result = stack->value[0];
}

void multDivMod(L *output, L *stack, int i) {
  if (output->type[i] == mult) {
    double r =
        stack->value[stack->counter - 1] * stack->value[stack->counter - 2];
    stack->value[stack->counter - 2] = r;
    stack->value[stack->counter - 1] = 0;
    stack->counter -= 1;
  } else if (output->type[i] == DIV) {
    double r =
        stack->value[stack->counter - 2] / stack->value[stack->counter - 1];
    stack->value[stack->counter - 2] = r;
    stack->value[stack->counter - 1] = 0;
    stack->counter -= 1;
  } else if (output->type[i] == MOD) {
    double r = fmod(stack->value[stack->counter - 2],
                    stack->value[stack->counter - 1]);
    stack->value[stack->counter - 2] = r;
    stack->value[stack->counter - 1] = 0;
    stack->counter -= 1;
  }
}

void mathFunction(L *output, L *stack, int i) {
  if (output->priority[i] == PSQRT) {
    double r = sqrt(stack->value[stack->counter - 1]);
    stack->value[stack->counter - 1] = r;
  } else if (output->priority[i] == log_or_ln) {
    if (output->type[i] == LOG) {
      double r = log10(stack->value[stack->counter - 1]);
      stack->value[stack->counter - 1] = r;
    }
    if (output->type[i] == LN) {
      double r = log(stack->value[stack->counter - 1]);
      stack->value[stack->counter - 1] = r;
    }
  } else if (output->priority[i] == trigonometry) {
    if (output->type[i] == SIN) {
      double r = sin(stack->value[stack->counter - 1]);
      stack->value[stack->counter - 1] = r;
    }
    if (output->type[i] == ASIN) {
      double r = asin(stack->value[stack->counter - 1]);
      stack->value[stack->counter - 1] = r;
    }
    if (output->type[i] == COS) {
      double r = cos(stack->value[stack->counter - 1]);
      stack->value[stack->counter - 1] = r;
    }
    if (output->type[i] == ACOS) {
      double r = acos(stack->value[stack->counter - 1]);
      stack->value[stack->counter - 1] = r;
    }
    if (output->type[i] == TAN) {
      double r = tan(stack->value[stack->counter - 1]);
      stack->value[stack->counter - 1] = r;
    }
    if (output->type[i] == ATAN) {
      double r = atan(stack->value[stack->counter - 1]);
      stack->value[stack->counter - 1] = r;
    }
  }
}

void plusMinusOperators(L *output, L *stack, int i) {
  if (output->type[i] == plus) {
    double r =
        stack->value[stack->counter - 1] + stack->value[stack->counter - 2];
    stack->value[stack->counter - 2] = r;
    stack->value[stack->counter - 1] = 0;
    stack->counter -= 1;
  } else {
    double r =
        stack->value[stack->counter - 2] - stack->value[stack->counter - 1];
    stack->value[stack->counter - 2] = r;
    stack->value[stack->counter - 1] = 0;
    stack->counter -= 1;
  }
}

void isNumber(L *output, L *stack, int i) {
  stack->value[0 + stack->counter] = output->value[i];
  stack->type[0 + stack->counter] = output->type[i];
  stack->priority[0 + stack->counter] = output->priority[i];
  stack->counter += 1;
}

void powOperator(L *stack) {
  double r =
      pow(stack->value[stack->counter - 2], stack->value[stack->counter - 1]);
  stack->value[stack->counter - 2] = r;
  stack->value[stack->counter - 1] = 0;
  stack->counter -= 1;
}

void RpnMathOperators(L *pars, L *stack, int i) {
  if (stack->counter == 0) {
    stack->value[0 + stack->counter] = pars->value[i];
    stack->type[0 + stack->counter] = pars->type[i];
    stack->priority[0 + stack->counter] = pars->priority[i];
    stack->counter += 1;
  } else if (pars->priority[i] >= stack->priority[stack->counter - 1]) {
    stack->value[0 + stack->counter] = pars->value[i];
    stack->type[0 + stack->counter] = pars->type[i];
    stack->priority[0 + stack->counter] = pars->priority[i];
    stack->counter += 1;
  } else {
    stack->value[0 + stack->counter] = pars->value[i];
    stack->type[0 + stack->counter] = pars->type[i];
    stack->priority[0 + stack->counter] = pars->priority[i];
    stack->counter += 1;
  }
}

void RpnScobe(L *pars, L *output, L *stack, int i) {
  if (pars->type[i] == leftScobe) {
    stack->value[0 + stack->counter] = pars->value[i];
    stack->type[0 + stack->counter] = pars->type[i];
    stack->priority[0 + stack->counter] = pars->priority[i];
    stack->counter += 1;
  } else if (pars->type[i] == rightScobe) {
    while (stack->type[stack->counter - 1] != leftScobe) {
      output->value[0 + output->counter] = stack->value[stack->counter - 1];
      output->type[0 + output->counter] = stack->type[stack->counter - 1];
      output->priority[0 + output->counter] =
          stack->priority[stack->counter - 1];
      output->counter += 1;
      stack->counter -= 1;
    }
    if (stack->type[stack->counter - 1] == 16) {
      stack->value[stack->counter - 1] = 0;
      stack->type[stack->counter - 1] = 0;
      stack->priority[stack->counter - 1] = 0;
      stack->counter -= 1;
    }
  }
}

void toZero(L *a){
  for(int i = 0; i < 255; i++){
    a ->value[i] = 0;
    a ->type[i] = 0;
    a ->priority[i] = 0;
  }
  a ->counter = 0;
}