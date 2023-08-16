#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


typedef enum{
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
}lexeme_type;

typedef enum{
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
}lexeme_priority;

typedef struct {
    double value[255];
    int priority[255];
    int type[255];
    int counter;
}L;

int S21_SmartCalc(char *expression, char *expression_for_x, char *answer);
int parser(char *expression, char *expression_for_x, L *pars);
void setInputLexeme(L *pars, double num, lexeme_type type, lexeme_priority type_1, int *step);
int trigonometryCheck(char *expression, L *pars, int error);
int scobeChecker(char *expression, L *pars, int *s_counter, int *error);
int logChecker(char *expression, L *pars);
int arithmeticSign(char *expression, L *pars, int error);
int validSign(char *expression, L *pars);
int constAnalyze(char *expression, char *expression_for_x, L *pars, int *error);
int handlerNum (char *expression, L *pars);
void RPN(L *pars, L *output, L *stack);
void setStackZero(L *stack);
void mathProcess(L *output, L *stack);
void multDivMod(L *output, L *stack, int i);
void mathFunction(L *output, L *stack, int i);
void plusMinusOperators(L *output, L *stack, int i);
void isNumber(L *output, L *stack, int i);
void powOperator(L *output, L *stack, int i);
void RpnMathOperators(L *pars, L *stack, int i);
void RpnScobe(L *pars, L *output, L *stack, int i);

int main(){
    // char expression[255] = "log(sqrt(2^3*cos(0)))";
    char expression[255] = "sqrt(4)";
    char expression_for_x[255] = "\0";
    char answer[255] = "";
    // L pars ={0, 0, 0, 0};
    S21_SmartCalc(expression, expression_for_x, answer);

    return 0;
}

int S21_SmartCalc(char *expression, char *expression_for_x, char *answer){
    L pars ={0, 0, 0, 0};
    L output = {0, 0, 0, 0};
    L stack = {0, 0, 0, 0};
    int error = 0;
    error = parser(expression, expression_for_x, &pars);
    if(error == 0){
        RPN(&pars, &output, &stack);
        mathProcess(&output, &stack);
    }
    return error;
}

int parser(char *expression, char *expression_for_x, L *pars){
    int error = 0;
    int i = 0;
    int s_counter = 0;
    while(*expression != '\0' && error == 0){

        expression += handlerNum (expression, pars);
        expression += trigonometryCheck(expression, pars, error);
        expression += scobeChecker(expression, pars, &s_counter, &error);
        expression += logChecker(expression, pars);
        expression += arithmeticSign(expression, pars, error);
        expression += constAnalyze(expression, expression_for_x, pars, &error);
        
        if(*expression == '.'){error = 1;}
    }
    return error;
}


void setInputLexeme(L *pars, double num, lexeme_type type, lexeme_priority type_1, int *step){
    pars -> value[pars ->counter] = num;
    pars ->priority[pars ->counter] = type_1;
    pars ->type[pars ->counter] = type;
    pars ->counter += 1;
    *step+= 1;
    // printf("!!!%d\n", step);
}

int trigonometryCheck(char *expression, L *pars, int error){
    int step = 0;
    if(*expression != '\0'){
        if(*expression == 'a' && *(expression + 1) == 't' && *(expression + 2) == 'a' && *(expression + 3) == 'n'){
            setInputLexeme(pars, 0, ATAN, trigonometry, &step);
            step += 3;
        }else if(*expression == 'a' && *(expression + 1) == 's' && *(expression + 2) == 'i' && *(expression + 3) == 'n'){
            setInputLexeme(pars, 0, ASIN, trigonometry, &step);
            step += 3;
        }else if(*expression == 'a' && *(expression + 1) == 'c' && *(expression + 2) == 'o' && *(expression + 3) == 's'){
            setInputLexeme(pars, 0, ACOS, trigonometry, &step);
            step += 3;
        }else if(*expression == 't' && *(expression + 1) == 'a' && *(expression + 2) == 'n'){
            setInputLexeme(pars, 0, TAN, trigonometry, &step);
            step += 2;
        }else if(*expression == 's' && *(expression + 1) == 'i' && *(expression + 2) == 'n'){
            setInputLexeme(pars, 0, SIN, trigonometry, &step);
            step += 2;
        }else if(*expression == 'c' && *(expression + 1) == 'o' && *(expression + 2) == 's'){
            setInputLexeme(pars, 0, COS, trigonometry, &step);
            step += 2;
        }else if(*expression == 's' && *(expression + 1) != 'q' && *(expression + 2) != 'r' && *(expression + 3) != 't'){
            error = 1;
        }
    }
    return step;
}

int scobeChecker(char *expression, L *pars, int *s_counter, int *error){
    int step = 0;
    if(*expression != '\0' && (*expression == '(' ||*expression == ')')){
        if(*expression == '(' && *(expression +1 ) != ')'){
            setInputLexeme(pars, 0, leftScobe, scobe, &step);
            *s_counter += 1;
        }else if(*expression == ')' && s_counter != 0){
            setInputLexeme(pars, 0, rightScobe, scobe, &step);
            *s_counter -= 1;
        }
        else{*error = 1;}
    }
    
    return step;
}

int logChecker(char *expression, L *pars){
    int step = 0;
    if(*expression != '\0'){
        if(*expression == 'l'&& *(expression + 1) == 'o' && *(expression + 2) == 'g'&& *(expression + 3) == '('){
            setInputLexeme(pars, 0, LOG, log_or_ln, &step);
            step += 2;
        }else if(*expression == 'l'&& *(expression + 1) == 'n' && *(expression + 2) == '('){
            setInputLexeme(pars, 0, LN, log_or_ln, &step);
            step += 1;
        }
    }
    return step;
}

int arithmeticSign(char *expression, L *pars, int error){
    int step = 0;
    int valid = validSign(expression, pars);
    if(*expression == '+' && valid == 1){
        setInputLexeme(pars, 0, plus, plus_or_minus, &step);
    }else if(*expression == '-' && valid){
        setInputLexeme(pars, 0, minus, plus_or_minus, &step);
    }else if(*expression == '*' && valid){
        setInputLexeme(pars, 0, mult, mult_or_div, &step);
    }else if(*expression == '/' && valid){
        setInputLexeme(pars, 0, DIV, mult_or_div, &step);
    }else if(*expression == '%' && valid){
        setInputLexeme(pars, 0, MOD, mod, &step);
    }else if(*expression == '^' && valid){
        setInputLexeme(pars, 0, POW, PPOW, &step);}
    else if(*expression == 's' && *(expression + 1) == 'q' && *(expression + 2) == 'r' && *(expression + 3) == 't' && valid){
        setInputLexeme(pars, 0, SQRT, PSQRT, &step);
        step += 3;
    }else{
        error = 1;}
    return step;
}

int validSign(char *expression, L *pars){
    int valid = 0;
    if(isdigit(*(expression+1)) != 0){valid++;}
    else if(*(expression + 1) == '('){valid++;}
    else if(*(expression + 1) == 'l'){valid++;}
    else if(*(expression + 1) == 'a'){valid++;}
    else if(*(expression + 1) == 'c'||*(expression + 1) == 's'||*(expression + 1) == 't'){valid++;}
    else if((*expression == '*' ||*expression == '/' ||*expression == '%'||*expression == '^') && pars->counter != 0){valid++;}
    else if(*expression == 's' && *(expression + 1) == 'q' && *(expression + 2) == 'r' && *(expression + 3) == 't'){valid++;}
    if(valid > 0){valid = 1;}
    return valid;
}

int constAnalyze(char *expression, char *expression_for_x, L *pars, int *error){
    int step = 0;
    if(*expression != '\0'){
        if(*expression == 'e' ){
            setInputLexeme(pars, M_E, NUM, number, &step);
        }else if(*expression == 'p'){
            setInputLexeme(pars, M_PI, NUM, number, &step);
        }else if(*expression == 'X'){
            if(isdigit(*expression_for_x) == 0){*error = 1;}
            else{
                double num = strtod(expression_for_x, &expression_for_x);
                setInputLexeme(pars, num, NUM, number, &step);
                if(*expression_for_x != '\0'){*error = 1;}
            }
        }
    }
    return step;
}

int handlerNum (char *expression, L *pars){
    int step = 0;
    if(isdigit(*expression)){
        while(isdigit(*(expression + step))){
            step++;
        }
        double num = strtod(expression, &expression);
        int step = 0;
        setInputLexeme(pars, num, NUM, number, &step);
    }

    return step;
}

void RPN(L *pars, L *output, L *stack){
    for(int i = 0; i < pars ->counter; i ++){
        if(pars ->type[i] == NUM){
            output->value[0 + output->counter] = pars ->value[i];
            output->type[0 + output->counter] = pars ->type[i];
            output->priority[0 + output->counter] = pars ->priority[i];
            output->counter += 1;
        }
        else if(pars ->type[i] == leftScobe || pars ->type[i] == rightScobe){
            RpnScobe(pars, output, stack, i);
        }
        else if(pars ->priority[i] == PSQRT || pars ->priority[i] == log_or_ln || pars ->priority[i] == trigonometry){
            stack->value[0 + stack->counter] = pars ->value[i];
            stack->type[0 + stack->counter] = pars ->type[i];
            stack->priority[0 + stack->counter] = pars ->priority[i];
            stack->counter += 1; 
        }
        else if(pars ->priority[i] == plus_or_minus || pars ->priority[i] == mult_or_div || pars ->priority[i] == mod || pars ->priority[i] == PPOW){
            RpnMathOperators(pars, stack, i);
        }
    }
    while(stack->counter != 0){
        output->value[0 + output->counter] = stack->value[stack->counter - 1];
        output->type[0 + output->counter] = stack->type[stack->counter - 1];
        output->priority[0 + output->counter] = stack->priority[stack->counter - 1];
        output->counter += 1;
        stack->counter -= 1;
    }
}

void mathProcess(L *output, L *stack){
    setStackZero(stack);
    for(int i = 0; i < output ->counter; i ++){
        if(output ->type[i] == NUM){
            isNumber(output, stack, i);
        }
        else if(output ->priority[i] == PSQRT ||output ->priority[i] == log_or_ln ||output ->priority[i] == trigonometry){
            mathFunction(output, stack, i);
        }
        else if(output ->priority[i] == plus_or_minus){
            plusMinusOperators(output, stack, i);
        }
        else if(output ->priority[i] == mult_or_div || output ->priority[i] == mod){
            multDivMod(output, stack, i);
        }
        else if(output ->priority[i] == PPOW){
            powOperator(output, stack, i);
        }
    }
    double result = stack -> value[0];
    printf("%lf", result);
}

void setStackZero(L *stack){
    for(int i = 0; i <255; i++){
        stack -> value[i] = 0;
        stack -> type[i] = 0;
        stack -> priority[i] = 0;
    }
    stack -> counter = 0;
}

void multDivMod(L *output, L *stack, int i){
    if(output ->type[i] == mult){
        double r = stack -> value[stack->counter - 1] * stack -> value[stack->counter - 2];
        stack->value[stack -> counter - 2] = r;
        stack->value[stack -> counter - 1] = 0;
        stack -> counter -= 1;
    }
    else if(output ->type[i] == DIV){
        double r = stack -> value[stack->counter - 2] / stack -> value[stack->counter - 1];
        stack->value[stack -> counter - 2] = r;
        stack->value[stack -> counter - 1] = 0;
        stack -> counter -= 1;
    }
    else if(output ->type[i] == MOD){
        double r = fmod(stack -> value[stack->counter - 2], stack -> value[stack->counter - 1]);
        stack->value[stack -> counter - 2] = r;
        stack->value[stack -> counter - 1] = 0;
        stack -> counter -= 1;
    }
}

void mathFunction(L *output, L *stack, int i){
    if(output ->priority[i] == PSQRT){
        double r = sqrt(stack -> value[stack->counter - 1]);
        stack->value[stack -> counter - 1] = r;
    }
    else if(output ->priority[i] == log_or_ln){
        if(output ->type[i] == LOG){
            double r = log10(stack -> value[stack->counter - 1]);
            stack->value[stack -> counter - 1] = r;
        }
        if(output ->type[i] == LN){
            double r = log(stack -> value[stack->counter - 1]);
            stack->value[stack -> counter - 1] = r;
        }
    }
    else if(output ->priority[i] == trigonometry){
        if(output ->type[i] == SIN){
            double r = sin(stack -> value[stack->counter - 1]);
            stack->value[stack -> counter - 1] = r;
        }
        if(output ->type[i] == ASIN){
            double r = asin(stack -> value[stack->counter - 1]);
            stack->value[stack -> counter - 1] = r;   
        }
        if(output ->type[i] == COS){
            double r = cos(stack -> value[stack->counter - 1]);
            stack->value[stack -> counter-1] = r;
        }
        if(output ->type[i] == ACOS){
            double r = acos(stack -> value[stack->counter - 1]);
            stack->value[stack -> counter - 1] = r;
        }
        if(output ->type[i] == TAN){
            double r = tan(stack -> value[stack->counter - 1]);
            stack->value[stack -> counter - 1] = r;
        }
        if(output ->type[i] == ATAN){
            double r = atan(stack -> value[stack->counter - 1]);
            stack->value[stack -> counter - 1] = r;
        }
    }
}

void plusMinusOperators(L *output, L *stack, int i){
    if(output ->type[i] == plus){
        double r = stack -> value[stack->counter - 1] + stack -> value[stack->counter - 2];
        stack->value[stack -> counter - 2] = r;
        stack->value[stack -> counter - 1] = 0;
        stack -> counter -= 1;
    }
    else{
        double r = stack -> value[stack->counter - 2] - stack -> value[stack->counter - 1];
        stack->value[stack -> counter - 2] = r;
        stack->value[stack -> counter - 1] = 0;
        stack -> counter -= 1;
    }
}

void isNumber(L *output, L *stack, int i){
    stack->value[0 + stack->counter] = output ->value[i];
    stack->type[0 + stack->counter] = output ->type[i];
    stack->priority[0 + stack->counter] = output ->priority[i];
    stack->counter += 1;
}

void powOperator(L *output, L *stack, int i){
    double r = pow(stack -> value[stack->counter - 2], stack -> value[stack->counter - 1]);
    stack->value[stack -> counter - 2] = r;
    stack->value[stack -> counter - 1] = 0;
    stack -> counter -= 1;
}

void RpnMathOperators(L *pars, L *stack, int i){
    if(stack->counter == 0){
        stack->value[0 + stack->counter] = pars ->value[i];
        stack->type[0 + stack->counter] = pars ->type[i];
        stack->priority[0 + stack->counter] = pars ->priority[i];
        stack->counter += 1; 
    }
    else if(pars ->priority[i] >= stack->priority[stack->counter - 1]){
        stack->value[0 + stack->counter] = pars ->value[i];
        stack->type[0 + stack->counter] = pars ->type[i];
        stack->priority[0 + stack->counter] = pars ->priority[i];
        stack->counter += 1;
    }
    else{
        stack->value[0 + stack->counter] = pars ->value[i];
        stack->type[0 + stack->counter] = pars ->type[i];
        stack->priority[0 + stack->counter] = pars ->priority[i];
        stack->counter += 1; 
    }
}

void RpnScobe(L *pars, L *output, L *stack, int i){
    if(pars ->type[i] == leftScobe){
        stack->value[0 + stack->counter] = pars ->value[i];
        stack->type[0 + stack->counter] = pars ->type[i];
        stack->priority[0 + stack->counter] = pars ->priority[i];
        stack->counter += 1;
    }
    else if(pars ->type[i] == rightScobe){
        while (stack->type[stack->counter - 1] != leftScobe){
            output->value[0 + output->counter] = stack->value[stack->counter - 1];
            output->type[0 + output->counter] = stack->type[stack->counter - 1];
            output->priority[0 + output->counter] = stack->priority[stack->counter - 1];
            output->counter += 1;
            stack->counter -= 1;
        }
        if(stack->type[stack->counter - 1] == 16){
            stack->value[stack->counter - 1] = 0;
            stack->type[stack->counter - 1] = 0;
            stack->priority[stack->counter - 1] = 0;
            stack->counter -= 1;
        }
    }
}