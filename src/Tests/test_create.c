#include "test.h"

START_TEST(create_matrix_simple_test) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_no_rows_test) {
  const int rows = 0;
  const int cols = 10;
  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), MATRIX_ERR);
}
END_TEST

START_TEST(create_matrix_no_cols_test) {
  const int rows = 10;
  const int cols = 0;

  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), MATRIX_ERR);
}
END_TEST

START_TEST(create_matrix_bad_rows_cols_test) {
  const int rows = -1;
  const int cols = -4;

  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), MATRIX_ERR);
}
END_TEST

Suite *test_create_matrix_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("create_matrix_test");
  /* Core test case */
  tc = tcase_create("create_matrix_tc");

  // create_matrix
  tcase_add_test(tc, create_matrix_simple_test);
  tcase_add_test(tc, create_matrix_no_rows_test);
  tcase_add_test(tc, create_matrix_no_cols_test);
  tcase_add_test(tc, create_matrix_bad_rows_cols_test);

  suite_add_tcase(s, tc);

  return s;
}
