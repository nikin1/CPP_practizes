#include "s21_smart_calc.h"

double calculator(char *A, double x, int *error) {
    *error = 0;
    double res = 0;
    if (validity_check(A) == 1) {
        Stack_t *S = Parse(A);
        S = ReverseStack(S);
        S = RPN(S);
        S = ReverseStack(S);
        res = calculate_algoritm(S, x);
    } else {
        *error = 1;
    }
    return res;
}

Stack_t *convert_str_to_rpn_stack(char *A) {
    Stack_t *S;
    S = Parse(A);
    S = ReverseStack(S);
    S = RPN(S);
    S = ReverseStack(S);
    return S;
}
