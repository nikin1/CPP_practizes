#include "s21_smart_calc.h"
#include <check.h>


START_TEST(validity_check_test) {
    ck_assert(validity_check("1.0+2") == 1);
    ck_assert(validity_check("+2") == 1);
    ck_assert(validity_check("-1") == 1);
    ck_assert(validity_check("1.0+2.") == 0);
    ck_assert(validity_check("-1+2") == 1);
    ck_assert(validity_check("1-2") == 1);
    ck_assert(validity_check("1+2") == 1);
    ck_assert(validity_check("(1+2)") == 1);
    ck_assert(validity_check("(1+2") == 0);
    ck_assert(validity_check("1+2)") == 0);
    ck_assert(validity_check("1+2-1+()") == 0);
    ck_assert(validity_check("1+2-1+(5)") == 1);
    ck_assert(validity_check("1+2-1+(-5)") == 1);
    ck_assert(validity_check("1+2-1-(-5)") == 1);
    ck_assert(validity_check("1+2-1--5") == 0);
    ck_assert(validity_check("1*5") == 1);
    ck_assert(validity_check("(1+2)*(5.001-3.2)") == 1);
    ck_assert(validity_check("(1+2)**(5-3)") == 0);
    ck_assert(validity_check("(1+2)*102") == 1);
    ck_assert(validity_check("12.7/102") == 1);
    ck_assert(validity_check("sin(1)") == 1);
    ck_assert(validity_check("sin(") == 0);
    ck_assert(validity_check("si(1)") == 0);
    ck_assert(validity_check("3*si") == 0);
    ck_assert(validity_check("sqrt(1)") == 1);
    ck_assert(validity_check("sin((5+3)*2)") == 1);
    ck_assert(validity_check("sin((5+3)*2.2") == 0);
    ck_assert(validity_check("3*siq((5+3)*2)") == 0);
    ck_assert(validity_check("3*sin((5+3)*2)") == 1);
    ck_assert(validity_check("3*cos((5+3)*2)") == 1);
    ck_assert(validity_check("3+tan(sin(5)/2)-1") == 1);
    ck_assert(validity_check("ln(x)") == 1);
    ck_assert(validity_check("lg(x)") == 0);
    ck_assert(validity_check("sqrt(atan(x)+3-asin(ln(x)))") == 1);
    ck_assert(validity_check("sqrt(atan(x)+3-asin(ln(x))") == 0);
    ck_assert(validity_check("sin(atan(x)^3)") == 1);
    ck_assert(validity_check("sqrt(atan(x)^(3*8-9))") == 1);
    ck_assert(validity_check("9mod5") == 1);
    ck_assert(validity_check("9smod5") == 0);
    ck_assert(validity_check("9mod-") == 0);
    ck_assert(validity_check("9moq3") == 0);
    ck_assert(validity_check("(3+9mod)") == 0);
    ck_assert(validity_check("3*") == 0);
    ck_assert(validity_check("9mod") == 0);
    ck_assert(validity_check("log10") == 0);
    ck_assert(validity_check("ln100*ln0") == 0);
    ck_assert(validity_check("1+") == 0);
    ck_assert(validity_check("cos(4)cos(4)") == 0);
    ck_assert(validity_check("cos(4)+cos(4)") == 1);
} END_TEST

START_TEST(check_value_test) {
    int error = 0;
    ck_assert(calculator("5", 0, &error) == 5.0 && error == 0);
    ck_assert(calculator("5+", 0, &error) == 0.0 && error == 1);
    ck_assert(calculator("2", 0, &error) == 2.0 && error == 0);
    ck_assert(calculator("2-(5*6-3)", 0, &error) == -25.0);
    ck_assert(calculator("2-(5*6)", 0, &error) == -28.0);
    ck_assert(calculator("+1+2", 0, &error) == 3.0);
    ck_assert(calculator("-1+2", 0, &error) == 1.0);
    ck_assert(fabs(calculator("cos((3+2)*5)", 0, &error) - cos((3+2)*5)) < 0.0000001);
    ck_assert(calculator("(10-2)*(2-1)*5", 0, &error) == 40);
    ck_assert(calculator("(10-2)*2-1*5", 0, &error) == 11);
    ck_assert(calculator("4*2-5*1-5", 0, &error) == -2);
    ck_assert(calculator("1+2-5*1", 0, &error) == -2);
    ck_assert(calculator("1+2-5", 0, &error) == -2);
    ck_assert(calculator("3mod2", 0, &error) == 3 % 2);
    ck_assert(fabs(calculator("acos(1)", 0, &error) - acos(1)) < 0.0000001);
    ck_assert(fabs(calculator("asin(1)*atan(1)", 0, &error) - asin(1)*atan(1)) < 0.0000001);
    ck_assert(fabs(calculator("ln(1)", 0, &error) - log(1)) < 0.0000001);
    ck_assert(fabs(calculator("log(1)", 0, &error) - log10(1)) < 0.0000001);
    ck_assert(fabs(calculator("acos(1)", 0, &error) - acos(1)) < 0.0000001);
    ck_assert(fabs(calculator("cos(1)", 0, &error) - cos(1)) < 0.0000001);
    ck_assert(fabs(calculator("tan(1)", 0, &error) - tan(1)) < 0.0000001);
    ck_assert(calculator("sin(1)", 0, &error) == sin(1));
    ck_assert(calculator("sin(x)", 1, &error) == sin(1));
    ck_assert(calculator("x+3", 1, &error) == 4);
    ck_assert(calculator("x+3", -3, &error) == 0);
    ck_assert(calculator("sqrt(9)", 0, &error) == 3.0);
    ck_assert(calculator("5^2", 0, &error) == 25.0);
    ck_assert(calculator("500/2", 0, &error) == 250.0);
    ck_assert(calculator("5*2", 0, &error) == 10.0);
    ck_assert(calculator("(5-1)*2", 0, &error) == 8.0);
    ck_assert(calculator("(5-1)", 0, &error) == 4.0);
    ck_assert(calculator("5-1", 0, &error) == 4.0);
    ck_assert(calculator("5+1", 0, &error) == 6.0);
} END_TEST

START_TEST(stack_test) {
    Stack_t *tmp = NULL;
    tmp = Parse("atan(sqrt(5*5))");
    ck_assert(tmp->value == 0.0000);
    ck_assert(tmp->priority == -1);
    ck_assert(tmp->type == RIGHT_BRACKET);
    tmp = Pop(tmp);
    tmp = Pop(tmp);
    ck_assert(tmp->value == 5.0000);
    ck_assert(tmp->priority == 0);
    ck_assert(tmp->type == NUMBER);
    tmp = Pop(tmp);
    tmp = Pop(tmp);
    tmp = Pop(tmp);
    tmp = Pop(tmp);
    ck_assert(tmp->value == 0.0000);
    ck_assert(tmp->type == SQRT);
    ck_assert(tmp->priority == 4);
    Clear_stack(tmp);

    tmp = Parse("1*5");
    ck_assert(tmp->value == 5.0000);
    ck_assert(tmp->priority == 0);
    ck_assert(tmp->type == NUMBER);
    tmp = Pop(tmp);
    ck_assert(tmp->value == 0.0000);
    ck_assert(tmp->priority == 2);
    ck_assert(tmp->type == MULT);
    tmp = Pop(tmp);
    tmp = Pop(tmp);
    ck_assert(tmp == NULL);

    tmp = Parse("sin(x)");
    ck_assert(tmp->value == 0.0000);
    ck_assert(tmp->priority == -1);
    ck_assert(tmp->type == RIGHT_BRACKET);
    tmp = Pop(tmp);
    ck_assert(tmp->value == 0.0000);
    ck_assert(tmp->priority == 0);
    ck_assert(tmp->type == X);
    tmp = Pop(tmp);
    ck_assert(tmp->priority == -1);
    tmp = Pop(tmp);
    Clear_stack(tmp);

    tmp = Parse("sin(x)");
    Stack_t *tmp_copy = CopyStack(tmp);
    ck_assert(tmp_copy->value == tmp->value);
    tmp = Pop(tmp);
    tmp_copy = Pop(tmp_copy);
    ck_assert(tmp_copy->value == tmp->value);
    tmp = Pop(tmp);
    tmp_copy = Pop(tmp_copy);
    Clear_stack(tmp_copy);
    Clear_stack(tmp);
} END_TEST

START_TEST(functions_for_qt_test) {
    ck_assert(StringIsNumber("1.0") == 1);
    ck_assert(StringIsNumber("-1.0") == 1);
    ck_assert(StringIsNumber("+1.0") == 1);
    ck_assert(StringIsNumber("5") == 1);
    ck_assert(StringIsNumber("5.2") == 1);
    ck_assert(StringIsNumber("5.2q") == 0);
    ck_assert(StringIsNumber("5.2.") == 0);
    ck_assert(StringIsNumber(".4") == 0);
    ck_assert(StringIsNumber("4.") == 0);
    ck_assert(StringIsNumber("asfd") == 0);
    ck_assert(StringIsNumber("4-2") == 0);
    ck_assert(StringIsNumber("4-") == 0);

    Stack_t *S;
    S = convert_str_to_rpn_stack("1+5");
    double res = calculate_algoritm(S, 0);
    ck_assert(res == 6);
} END_TEST


int main(void) {
  Suite *s1 = suite_create("s21_smart_calc");
  TCase *tc1_1 = tcase_create("s21_smart_calc");
  SRunner *sr = srunner_create(s1);
  int nf;
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, validity_check_test);
  tcase_add_test(tc1_1, check_value_test);
  tcase_add_test(tc1_1, stack_test);
  tcase_add_test(tc1_1, functions_for_qt_test);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nf == 0 ? 0 : 1;
}
