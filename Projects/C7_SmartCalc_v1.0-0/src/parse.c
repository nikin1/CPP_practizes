#include "s21_smart_calc.h"

int IsNumber(char a) {
    int res = 1;
    if ((a < '0' || a > '9') && a != 'x') res = 0;
    return res;
}

int IsOperator(char a) {
    int res = 1;
    if (a != '-' && a != '+' && a != '*' && a != '/' && a != '^' && a != 'm') res = 0;
    return res;
}

int StringIsNumber(char *A) {
    int i = 0;
    int res = 1;
    while (A[i]) {
        if (!IsNumber(A[i]) && A[i] != '.' && A[i] != '+' && A[i] != '-') {
            res = 0;
            break;
        } else if (A[i] == '.') {
            if (i == 0 || !A[i+1]) {
                res = 0;
                break;
            }
        } else if ((A[i] == '+' || A[i] == '-') && i > 0) {
            res = 0;
            break;
        }
        i++;
    }
    if (i == 0) res = 0;
    return res;
}

int CheckFunctions(char *A, int i) {
    int res = 0;
    if (A[i] == 'c') {
        if (A[i + 1] == 'o' && A[i + 2] == 's' && A[i + 3] == '(') res = 2;
    } else if (A[i] == 's' && A[i + 1] == 'i') {
        if (A[i + 2] == 'n' && A[i + 3] == '(') res = 2;
    } else if (A[i] == 't') {
        if (A[i + 1] == 'a' && A[i + 2] == 'n' && A[i + 3] == '(') res = 2;
    } else if (A[i] == 's' && A[i + 1] == 'q') {
        if (A[i + 2] == 'r' && A[i + 3] == 't' && A[i + 4] == '(') res = 3;
    } else if (A[i] == 'l' && A[i + 1] == 'n') {
        if (A[i + 2] == '(') res = 1;
    } else if (A[i] == 'l' && A[i + 1] == 'o') {
        if (A[i + 2] == 'g' && A[i + 3] == '(') res = 2;
    }
    return res;
}

int TypeFunctions(char *A, int i, int *len) {
    int type_enum = 0;
    if (A[i] == 'c')  {
        type_enum = 9;
        *len = 2;
    } else if (A[i] == 's' && A[i + 1] == 'i') {
        type_enum = 10;
        *len = 2;
    } else if (A[i] == 't') {
        type_enum = 11;
        *len = 2;
    } else if (A[i] == 'a' && A[i + 1] == 'c') {
        type_enum = 12;
        *len = 3;
    } else if (A[i] == 'a' && A[i + 1] == 's') {
        type_enum = 13;
        *len = 3;
    } else if (A[i] == 'a' && A[i + 1] == 't') {
        type_enum = 14;
        *len = 3;
    } else if (A[i] == 's' && A[i + 1] == 'q') {
        type_enum = 15;
        *len = 3;
    } else if (A[i] == 'l' && A[i + 1] == 'n') {
        type_enum = 16;
        *len = 1;
    } else if (A[i] == 'l' && A[i + 1] == 'o') {
        type_enum = 17;
        *len = 2;
    }
    return type_enum;
}


int validity_check(char *A) {
    int res = 1;
    int i = 0, bracket = 0;
    while (A[i]) {
        if (IsNumber(A[i])) {
            i++;
            continue;
        } else if (A[i] == '.') {
            if (!IsNumber(A[i - 1]) || !IsNumber(A[i + 1])) res = 0;
        } else if (A[i] ==  '(') {
            bracket++;
        } else if (A[i] ==  ')') {
            if (bracket > 0 && A[i - 1] != '(')
                bracket--;
            else
            // если есть перед ним открывающая скобка и какое-то значение м/у ними
                res = 0;
            if (A[i + 1])
                if ((IsOperator(A[i + 1]) == 0 &&  A[i + 1] != ')')) res = 0;
        } else if (A[i] ==  '+' || A[i] ==  '-') {
            if (!A[i+1]) res = 0;
            if (A[i - 1] && A[i - 1] != ')' && A[i - 1] != '(' && (IsNumber(A[i - 1]) == 0)) res = 0;
        } else if (A[i] ==  '*' || A[i] == '/'|| A[i] == '^') {
            if (!A[i + 1] || IsOperator(A[i + 1]) == 1 || A[i + 1] == ')') res = 0;
            if (!A[i - 1] || IsOperator(A[i - 1]) == 1 || A[i - 1] == '(') res = 0;
        } else if (A[i] == 'm') {
            if (A[i + 1] == 'o' && A[i + 2] == 'd')
                i += 2;
            else
                res = 0;
            if (!A[i + 1] || IsOperator(A[i + 1]) == 1 || A[i + 1] == ')') res = 0;
            if (!A[i - 3] || IsOperator(A[i - 3]) == 1 || A[i - 3] == '(') res = 0;
        } else if (A[i] == 's' || A[i] == 'c' || A[i] == 't' || A[i] == 'a' || A[i] == 'l') {
            if (A[i + 4]) {
                if (A[i] == 'a') {
                    i++;
                }
                int tmp = CheckFunctions(A, i);
                if (tmp == 0)
                    res = 0;
                else
                    i += tmp;
            }
        } else {
            res = 0;
        }
        if (res == 0) {
            break;
        }
        i++;
    }
    if (bracket != 0) {
        res = 0;
    }
    return res;
}

Stack_t *Parse(char *A) {
    int  i = 0;
    char tmp[256];
    Stack_t *S = NULL;
    int priority, type;
    double value;
    while (A[i]) {
        value = 0;
        if (IsNumber(A[i]) && A[i] != 'x') {
            int j = 0;
            memset(tmp, '\0', 255);
            while (1) {
                tmp[j] = A[i];
                if (IsNumber(A[i + 1]) || A[i + 1] == '.') {
                    i++;
                    j++;
                } else {
                    break;
                }
            }
            sscanf(tmp, "%lf", &value);
            type = NUMBER;
            priority = 0;
        } else if (A[i] == 'x') {
            priority = 0;
            type = X;
        } else if (A[i] == '+') {
            priority = 1;
            type = PLUS;
        } else if (A[i] == '-') {
            priority = 1;
            type = MINUS;
        } else if (A[i] == '*') {
            priority = 2;
            type = MULT;
        } else if (A[i] == '/') {
            priority = 2;
            type = DIV;
        } else if (A[i] == 'm') {
            priority = 2;
            type = MOD;
            i += 2;
        } else if (A[i] == '^') {
            priority = 3;
            type = POW;
        } else if (A[i] == 's' || A[i] == 'a' || A[i] == 'c' || A[i] == 't' || A[i] == 'l') {
            int len_function;
            int type_enum = TypeFunctions(A, i, &len_function);
            priority = 4;
            type = type_enum;
            i += len_function;
        } else if (A[i] == '(') {
            priority = -1;
            type = LEFT_BRACKET;
        } else if (A[i] == ')') {
            priority = -1;
            type = RIGHT_BRACKET;
        }
        if (type == MINUS || type == PLUS) {
            if (!A[i - 1] || (A[i - 1] && A[i - 1] == '(')) S = Push(S, 0, 0, NUMBER);
        }
        S = Push(S, value, priority, type);
        i++;
    }
    return S;
}

