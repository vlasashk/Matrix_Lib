#include "test.h"

START_TEST(remove_matrix_simple_test) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(0, A.columns);
  ck_assert_int_eq(0, A.rows);
}
END_TEST

START_TEST(remove_matrix_loop_test) {
  matrix_t m = {0};

  for (int i = -50; i < 0; i++) {
    int res = s21_create_matrix(i, i, &m);
    ck_assert_int_eq(res, MATRIX_ERR);
    ck_assert_int_eq(m.rows, 0);
    ck_assert_int_eq(m.columns, 0);
    ck_assert_ptr_eq(m.matrix, NULL);

    s21_remove_matrix(&m);
    ck_assert_int_eq(m.rows, 0);
    ck_assert_int_eq(m.columns, 0);
    ck_assert_ptr_eq(m.matrix, NULL);
  }
}
END_TEST

Suite *test_remove_matrix_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("remove_matrix_test");
  /* Core test case */
  tc = tcase_create("remove_matrix_tc");

  // remove_matrix
  tcase_add_test(tc, remove_matrix_simple_test);
  tcase_add_test(tc, remove_matrix_loop_test);

  suite_add_tcase(s, tc);

  return s;
}
