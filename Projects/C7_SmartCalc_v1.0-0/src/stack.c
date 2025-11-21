#include "s21_smart_calc.h"

Stack_t *Push(Stack_t *last_element, double value, int prioprity, int type) {
    Stack_t *new;
    new = malloc(sizeof(Stack_t));
    assert(new != NULL);
    new->prev = last_element;
    new->value = value;
    new->priority = prioprity;
    new->type = type;
    return new;
}

Stack_t *Pop(Stack_t *last_element) {
    Stack_t *tmp;
    assert(last_element != NULL);
    tmp = last_element;
    last_element = last_element->prev;
    free(tmp);
    return last_element;
}

// void PrintStack(Stack_t *last_el, char *A) {
//     int cnt = 0;
//     char *types[] = {"0",
//         "NUMBER",
//         "X",
//         "PLUS",
//         "MINUS",
//         "MULT",
//         "DIV",
//         "POW",
//         "MOD",
//         "COS",
//         "SIN",
//         "TAN",
//         "ACOS",
//         "ASIN",
//         "ATAN",
//         "SQRT",
//         "LN",
//         "LOG",
//         "LEFT_BRACKET",
//         "RIGHT_BRACKET"
//     };
//     printf("\n");
//     printf("PARSE: %s\n", A);
//     while (last_el != NULL) {
//         printf("| value: %lf | priority: %2d |", last_el->value, last_el->priority);
//         printf(" type: %12s |\n", types[last_el->type]);
//         printf("-------------------------------------------------------\n");
//         // last_el = last_el->prev;
//         last_el = last_el->prev;
//         cnt++;
//     }
// }

Stack_t *ReverseStack(Stack_t *A) {
    Stack_t *B = NULL;
    while (A != NULL) {
        B = Push(B, A->value, A->priority, A->type);
        A = Pop(A);
    }
    return B;
}
void Clear_stack(Stack_t *A) {
    while (A != NULL) {
        A = Pop(A);
    }
}

Stack_t *CopyStack(Stack_t *A) {
    Stack_t *B = NULL;
    Stack_t *A_tmp = A;
    while (A_tmp != NULL) {
        B = Push(B, A_tmp->value, A_tmp->priority, A_tmp->type);
        A_tmp = A_tmp->prev;
    }
    Stack_t *C = ReverseStack(B);
    return C;
}

