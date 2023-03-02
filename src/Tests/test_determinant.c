#include "test.h"

START_TEST(determinant_simple_test) {
  matrix_t A;
  s21_create_matrix(5, 5, &A);
  double res = 0.0;
  double must = 1116.0;
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 3;
  A.matrix[0][4] = 3;
  A.matrix[1][0] = 8;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 1;
  A.matrix[1][3] = 2;
  A.matrix[1][4] = 2;
  A.matrix[2][0] = 4;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 2;
  A.matrix[2][3] = 9;
  A.matrix[2][4] = 0;
  A.matrix[3][0] = 4;
  A.matrix[3][1] = 4;
  A.matrix[3][2] = 0;
  A.matrix[3][3] = 4;
  A.matrix[3][4] = 1;
  A.matrix[4][0] = 3;
  A.matrix[4][1] = 3;
  A.matrix[4][2] = 8;
  A.matrix[4][3] = 1;
  A.matrix[4][4] = 0;
  int test = s21_determinant(&A, &res);
  ck_assert_double_eq_tol(res, must, 1e-6);
  ck_assert_int_eq(test, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_simple_single_test) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  double res = 0.0;
  double must = 9.0;
  A.matrix[0][0] = 9;

  int test = s21_determinant(&A, &res);
  ck_assert_double_eq_tol(res, must, 1e-6);
  ck_assert_int_eq(test, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_simple_wrong_matrix_test) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  double res = 0.0;
  A.matrix[0][0] = 9;
  A.rows = -5;
  A.columns = -5;
  int test = s21_determinant(&A, &res);
  ck_assert_int_eq(test, MATRIX_ERR);
  A.rows = 1;
  A.columns = 1;
  s21_remove_matrix(&A);
}
END_TEST

Suite *test_determinant_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("determinant_test");
  /* Core test case */
  tc = tcase_create("determinant_tc");

  // determinant
  tcase_add_test(tc, determinant_simple_test);
  tcase_add_test(tc, determinant_simple_single_test);
  tcase_add_test(tc, determinant_simple_wrong_matrix_test);

  suite_add_tcase(s, tc);

  return s;
}
