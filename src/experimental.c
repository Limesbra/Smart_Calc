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

int parser(char *expression, char *expression_for_x);
void setInputLexeme(L *pars, double num, lexeme_type type, lexeme_priority type_1, int *step);
int trigonometryCheck(char *expression, L *pars, int error);
int scobeChecker(char *expression, L *pars, int *s_counter, int *error);
int logChecker(char *expression, L *pars);
int arithmeticSign(char *expression, L *pars, int error);
int validSign(char *expression, L *pars);
int constAnalyze(char *expression, char *expression_for_x, L *pars, int error);
int n (char *expression, L *pars);

int main(){
    char expression[255] = "23+44*(cos(11))";
    char expression_for_x[255] = "\0";
    parser(expression, expression_for_x);

    // L pars ={0};
    // char expression[255] = "()";
    // int x = trigonometryCheck(expression, &pars);
    // int s_counter = -1;
    // int error = 0;
    // int x = scobeChecker(expression, &pars, s_counter, error);
    // printf("%d\n", x);
    // printf("%d\n", error);

   

    return 0;
}

int parser(char *expression, char *expression_for_x){
    int error = 0;
    int i = 0;
    L pars ={0, 0, 0, 0};
    int s_counter = 0;
    while(*expression != '\0' && error == 0){

        // expression += 2;
        expression += n (expression, &pars);
        expression += trigonometryCheck(expression, &pars, error);
        expression += scobeChecker(expression, &pars, &s_counter, &error);
        expression += logChecker(expression, &pars);
        expression += arithmeticSign(expression, &pars, error);
        expression += constAnalyze(expression, expression_for_x, &pars, error);
        

        // if(isdigit(*expression)){
        //     double num = strtod(expression, &expression);
        //     int step = 0;
        //     setInputLexeme(&pars, num, NUM, number, &step);
        // }
        if(*expression == '.'){error = 1;}
        // else {error = 1;}
    }
    for(int i = 0; i != pars.counter; i++){
    printf("%f ", pars.value[i]);
    printf("%d ", pars.priority[i]);
    printf("%d ", pars.type[i]);
    printf("%d", pars.counter);
    printf("\n");
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
    if(*expression != '\0'){
        if(*expression == '('){
            setInputLexeme(pars, 0, leftScobe, scobe, &step);
            *s_counter += 1;
        }else if(*expression == ')' && s_counter != 0){
            setInputLexeme(pars, 0, rightScobe, scobe, &step);
            *s_counter -= 1;
        }/*else{*error = 1;}*/
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
        setInputLexeme(pars, 0, POW, pow_or_sqrt, &step);}
    else if(*expression == 's' && *(expression + 1) == 'q' && *(expression + 2) == 'r' && *(expression + 2) == 't' && valid){
        setInputLexeme(pars, 0, SQRT, pow_or_sqrt, &step);
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
    else if(*expression == 's' && *(expression + 1) == 'q' && *(expression + 2) == 'r' && *(expression + 2) == 't'){valid++;}
    if(valid > 0){valid = 1;}
    return valid;
}

int constAnalyze(char *expression, char *expression_for_x, L *pars, int error){
    int step = 0;
    if(*expression != '\0'){
        if(*expression == 'e' ){
            setInputLexeme(pars, M_E, NUM, number, &step);
        }else if(*expression == 'p' ){
            setInputLexeme(pars, M_PI, NUM, number, &step);
        }else if(*expression == 'X' ){
            double num = strtod(expression_for_x, &expression_for_x);
            setInputLexeme(pars, num, NUM, variable, &step);
            if(*expression_for_x != '\0'){error = 1;}
        }
    }
    return step;
}

int n (char *expression, L *pars){
    int i = 0;
    if(isdigit(*expression)){
        while(isdigit(*(expression + i))){
            i++;
        }
        double num = strtod(expression, &expression);
        int step = 0;
        setInputLexeme(pars, num, NUM, number, &step);
    }

    return i;
}