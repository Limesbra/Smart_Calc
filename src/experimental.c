#include <stdio.h>
#include <string.h>
#include <math.h>


typedef enum{
    number,
    plus,
    minus,
    mult,
    div,
    mod,
    pow,
    sqrt,
    log,
    ln,
    sin,
    asin,
    cos,
    acos,
    tan,
    atan,
    leftScobe,
    rightScobe
}lexeme_type;

typedef enum{
    variable = -1,
    number,
    plus_or_minus,
    mult_or_div,
    mod = 2,
    pow_or_sqrt,
    log_or_ln,
    trigonometry,
    scobe
}lexeme_priority;

// typedef struct {
//     // double value;
//     int priority;
//      a[255] ="25", "+", 567,;
//     // struct lexeme*next;
//     lexeme_type type;
// }lexeme;

typedef struct {
    double value[255];
    int priority[255];
    int type[255];
    int counter;
}L;

int main(){
    char expression[255] = "23+44*(cos(11))";
    char expression_for_x[255] = "";

    return 0;
}

int parser(char *expression, char *expression_for_x){
    int error = 0;
    int i = 0;
    L pars ={0};
    int s_counter = 0;
    while(expression && error == 0){

        expression += trigonometryCheck(expression, &pars);
        expression += scobeChecker(expression, &pars, s_counter, &error);
        expression += logChecker(expression, &pars);
        expression += arithmeticSign(expression, &pars, &error);
        expression += constAnalyze(expression, expression_for_x, &pars, &error);

        if(isdigit(expression)){
            double num = strtod(expression, &expression);
            setInputLexeme(&pars, num, number, number, 0);
        }else if(expression == '.'){error = 1;}
        else{error = 1;}

    }
    return error;
}


void setInputLexeme(L *pars, double num, lexeme_type type, lexeme_priority type_1, int *step){
    int step = 0;
    pars -> value[pars ->counter] = num;
    pars ->priority[pars ->counter] = type_1;
    pars ->type[pars ->counter] = type;
    pars ->counter++;
    step++;
}

int trigonometryCheck(char *expression, L *pars){
    int step = 0;
    if(expression == 'a' && expression + 1 == 't' && expression + 2 == 'a' && expression + 3 == 'n'){
        setInputLexeme(&pars, 0, atan, trigonometry, &step);
    }else if(expression == 'a' && expression + 1 == 's' && expression + 2 == 'i' && expression + 3 == 'n'){
        setInputLexeme(&pars, 0, asin, trigonometry, &step);
    }else if(expression == 'a' && expression + 1 == 'c' && expression + 2 == 'o' && expression + 3 == 's'){
        setInputLexeme(&pars, 0, acos, trigonometry, &step);
    }else if(expression == 't' && expression + 1 == 'a' && expression + 2 == 'n'){
        setInputLexeme(&pars, 0, tan, trigonometry, &step);
    }else if(expression == 's' && expression + 1 == 'i' && expression + 2 == 'n'){
        setInputLexeme(&pars, 0, sin, trigonometry, &step);
    }else if(expression == 'c' && expression + 1 == 'o' && expression + 2 == 's'){
        setInputLexeme(&pars, 0, cos, trigonometry, &step);
    }
    return step;
}

int scobeChecker(char *expression, L *pars, int s_counter, int *error){
    int step = 0;
    if(expression == '('){
        setInputLexeme(&pars, 0, leftScobe, scobe, &step);
        s_counter += 1;
    }else if(expression == ')' && s_counter != 0){
        setInputLexeme(&pars, 0, rightScobe, scobe, &step);
        s_counter -= 1;
    }else{error = 1;}
    return step;
}

int logChecker(char *expression, L *pars){
    int step = 0;
    if(expression == 'l'&& expression + 1 == 'o' && expression + 2 == 'g'&& expression + 3 == '('){
        setInputLexeme(&pars, 0, log, log_or_ln, &step);
        step += 2;
    }else if(expression == 'l'&& expression + 1 == 'n' && expression + 2 == '('){
        setInputLexeme(&pars, 0, ln, log_or_ln, &step);
        step += 1;
    }
    return step;
}

int arithmeticSign(char *expression, L *pars, int *error){
    int step = 0;
    int valid = validSign(expression, pars);
    if(expression == '+' && valid){
        setInputLexeme(&pars, 0, plus, plus_or_minus, &step);
    }else if(expression == '-' && valid){
        setInputLexeme(&pars, 0, minus, plus_or_minus, &step);
    }else if(expression == '*' && valid){
        setInputLexeme(&pars, 0, mult, mult_or_div, &step);
    }else if(expression == '/' && valid){
        setInputLexeme(&pars, 0, div, mult_or_div, &step);
    }else if(expression == '%' && valid){
        setInputLexeme(&pars, 0, sin, trigonometry, &step);
    }else if(expression == '^' && valid){
        setInputLexeme(&pars, 0, cos, trigonometry, &step);
    }else{error = 1;}
    return step;
}

int validSign(char *expression, L *pars){
    int valid = 0;
    if(isdigit(expression+1)){valid++;}
    else if(expression + 1 == '('){valid++;}
    else if(expression + 1 == 'l'){valid++;}
    else if(expression + 1 == 'a'){valid++;}
    else if(expression + 1 == 'c'||expression + 1 == 's'||expression + 1 == 't'){valid++;}
    else if((expression == '*' ||expression == '/' ||expression == '%'||expression == '^') && pars->counter != 0){valid++;}
    if(valid > 0){valid = 1;}
    return valid;
}

int constAnalyze(char *expression, char *expression_for_x, L *pars, int *error){
    int step = 0;
    if(expression == 'e' ){
        setInputLexeme(&pars, M_E, number, number, &step);
    }else if(expression == 'p' ){
        setInputLexeme(&pars, M_PI, number, number, &step);
    }else if(expression == 'X' ){
        double num = strtod(expression_for_x, &expression_for_x);
        setInputLexeme(&pars, num, number, variable, &step);
        if(expression_for_x != '\0'){error = 1;}
    }
    return step;
}