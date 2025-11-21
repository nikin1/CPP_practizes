#ifndef SRC_S21_SMART_CALC_H_
#define SRC_S21_SMART_CALC_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>

typedef enum {
    NUMBER = 1,
    X = 2,
    PLUS = 3,
    MINUS = 4,
    MULT = 5,
    DIV = 6,
    POW = 7,
    MOD = 8,
    COS = 9,
    SIN = 10,
    TAN = 11,
    ACOS = 12,
    ASIN = 13,
    ATAN = 14,
    SQRT = 15,
    LN = 16,
    LOG = 17,
    LEFT_BRACKET = 18,
    RIGHT_BRACKET = 19
} type_t;

typedef struct Stack {
    double value;
    int priority;
    type_t type;
    struct Stack *prev;
} Stack_t;

Stack_t *Push(Stack_t *last_element, double value, int prioprity, int type);
Stack_t *Pop(Stack_t *last_element);
// void PrintStack(Stack_t *last_el, char *A);
Stack_t *ReverseStack(Stack_t *A);
Stack_t *CopyStack(Stack_t *A);

int StringIsNumber(char *A);
int IsNumber(char a);
int validity_check(char *A);
Stack_t *Parse(char *A);
Stack_t *RPN(Stack_t *Input);
double calculate_algoritm(Stack_t *Ready, double x);
double calculate(Stack_t *arg1, Stack_t *arg2, int type_operator);
double calculator(char *A, double x, int *error);
Stack_t *convert_str_to_rpn_stack(char *A);
void Clear_stack(Stack_t *A);


#endif  // SRC_S21_SMART_CALC_H_
