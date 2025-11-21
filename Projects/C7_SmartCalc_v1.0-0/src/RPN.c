#include "s21_smart_calc.h"

int IsTypeFunction(Stack_t *TEMP) {
    int res = 0;
    if (TEMP->type >= COS && TEMP->type <= LOG) res = 1;
    return res;
}

int IsTypeOperator(Stack_t *TEMP) {
    int res = 0;
    if (TEMP->type > 2) res = 1;
    return res;
}

Stack_t *RPN(Stack_t *Input) {
    Stack_t *Ready = NULL, *Support = NULL;
    while (Input != NULL) {
        if (Input->type == NUMBER || Input->type == X) {
            Ready = Push(Ready, Input->value, Input->priority, Input->type);
        } else {
            if (Support != NULL) {
                // до тех пор пока нужно убрать операторы
                while (Input->priority <= Support->priority
                && Input->type != LEFT_BRACKET && Input->type != RIGHT_BRACKET) {
                    // Переносим из суппорта в основной
                    Ready = Push(Ready, Support->value, Support->priority, Support->type);
                    Support = Pop(Support);  // удаляем в суппорте
                    if (Support == NULL) break;
                }
            }
            Support = Push(Support, Input->value, Input->priority, Input->type);
            if (Support->type == RIGHT_BRACKET) {
                Support = Pop(Support);  // Удаляем закрывающую скобку
                while (Support->type != LEFT_BRACKET) {
                    // переносим все, что находится в скобках
                    Ready = Push(Ready, Support->value, Support->priority, Support->type);
                    Support = Pop(Support);
                }
                // удаляем открывающую скобку
                Support = Pop(Support);
            }
        }
        Input = Pop(Input);
    }
    // Затем все оставшиеся значения в Суппорте переносим в ready
    while (Support != NULL) {
        // Переносим из суппорта в основной
        Ready = Push(Ready, Support->value, Support->priority, Support->type);
        Support = Pop(Support);  // удаляем в суппорте
    }
    return Ready;
}

double calculate_algoritm(Stack_t *Ready, double x) {
    double new_value = 0;
    Stack_t *Support = NULL;
    Stack_t *TEMP;
    TEMP = Ready;
    Stack_t *temp1 = NULL, *temp2 = NULL;

    while (Ready != NULL) {
        if (TEMP == NULL) {
            if (temp1 != NULL) {
                new_value = temp1->value;
            }
            Ready = Pop(Ready);
        } else if (IsTypeOperator(TEMP)) {
            // Значит перед оператором сейчас нах-ся числа, к-ые записаны в temp
            new_value = calculate(temp1, temp2, TEMP->type);
            // Сначала нужно узнать, Стоит ли учитывать второй аргумент
            int argument = 2;
            // В функцию мы подаем только 1 аргумент
            if (IsTypeFunction(TEMP) == 1)
                argument = 1;
            while (Ready != TEMP) {
                // все элементы до оператора удаляются.
                // Если были элементы до аргментов, то они сохраняются в Суппорт
                if ((Ready != temp1 && Ready != temp2 && argument == 2)
                || (Ready != temp1 && argument == 1)) {
                    Support = Push(Support, Ready->value, Ready->priority, Ready->type);
                }
                Ready = Pop(Ready);
            }
            // Удаляем сам оператор
            Ready = Pop(Ready);
            if (Ready != NULL) Ready = Push(Ready, new_value, 0, NUMBER);
            // затем пушим если были перед ним значения
            while (Support != NULL) {
                Ready = Push(Ready, Support->value, Support->priority, NUMBER);
                Support = Pop(Support);
            }
            // Переносим temp опять в начало
            TEMP = Ready;
        } else {
            // value
            if (TEMP->type == X) {
                TEMP->type = NUMBER;
                TEMP->value = x;
            }
            if (temp1 != NULL) temp2 = temp1;
            temp1 = TEMP;
            TEMP = TEMP->prev;
        }
    }
    return new_value;
}

double calculate(Stack_t *arg1, Stack_t *arg2, int type_operator) {
    double res, temp1, temp2;
    temp1 = arg1->value;
    if (arg2 != NULL) temp2 = arg2->value;
    switch (type_operator) {
    case PLUS:
        res = temp2 + temp1;
        break;

    case MINUS:
        res = temp2 - temp1;
        break;

    case MULT:
        res = temp2 * temp1;
        break;
    case DIV:

        res = temp2 / temp1;
        break;

    case POW:
        res = pow(temp2, temp1);
        break;

    case MOD:
        res =  fmod(temp2, temp1);
        break;

    case COS:
        res = cos(temp1);
        break;

    case SIN:
        res = sin(temp1);
        break;

    case TAN:
        res = tan(temp1);
        break;

    case ACOS:
        res = acos(temp1);
        break;

    case ASIN:
        res = asin(temp1);
        break;

    case ATAN:
        res = atan(temp1);
        break;

    case SQRT:
        res = sqrt(temp1);
        break;

    case LN:
        res = log(temp1);
        break;

    case LOG:
        res = log10(temp1);
        break;
    }
    return res;
}

