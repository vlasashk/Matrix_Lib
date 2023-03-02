#include "test.h"

START_TEST(transpose_simple_test) {
  matrix_t A, res, must;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &must);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  int test = s21_transpose(&A, &res);
  must.matrix[0][0] = 2;
  must.matrix[0][1] = 6;
  must.matrix[0][2] = 5;
  must.matrix[1][0] = 5;
  must.matrix[1][1] = 3;
  must.matrix[1][2] = -2;
  must.matrix[2][0] = 7;
  must.matrix[2][1] = 4;
  must.matrix[2][2] = -3;

  int check = s21_eq_matrix(&res, &must);
  ck_assert_int_eq(check, SUCCESS);
  ck_assert_int_eq(test, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&must);
}
END_TEST

START_TEST(transpose_simple_single_test) {
  matrix_t A, res, must;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &must);
  A.matrix[0][0] = 2;
  int test = s21_transpose(&A, &res);
  must.matrix[0][0] = 2;

  int check = s21_eq_matrix(&res, &must);
  ck_assert_int_eq(check, SUCCESS);
  ck_assert_int_eq(test, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&must);
}
END_TEST

Suite *test_transpose_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("transpose_test");
  /* Core test case */
  tc = tcase_create("transpose_tc");

  // transpose
  tcase_add_test(tc, transpose_simple_test);
  tcase_add_test(tc, transpose_simple_single_test);
  suite_add_tcase(s, tc);

  return s;
}
