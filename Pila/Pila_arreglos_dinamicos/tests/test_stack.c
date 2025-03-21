#include <check.h>
#include "../src/stack.h"

START_TEST(test_stack_init) {
    Stack stack=  stack_create(5);
    ck_assert(stack_is_empty(&stack));
    stack_delete(&stack);
    ck_assert(stack.data == NULL);

    
}
END_TEST

START_TEST(test_stack_push_pop) {
    Stack stack = stack_create(5);

    stack_push(&stack, 10);
    stack_push(&stack, 20);

    ck_assert_int_eq(stack_pop(&stack), 20);
    ck_assert_int_eq(stack_pop(&stack), 10);
    ck_assert(stack_is_empty(&stack));
    stack_delete(&stack);
    ck_assert(stack.data == NULL);
}
END_TEST

Suite* stack_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("Stack");

    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_stack_init);
    tcase_add_test(tc_core, test_stack_push_pop);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite* s;
    SRunner* sr;

    s = stack_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}