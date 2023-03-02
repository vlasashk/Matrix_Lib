#include "test.h"

START_TEST(inverse_matrix_simple_test) {
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
  int test = s21_inverse_matrix(&A, &res);
  must.matrix[0][0] = 1;
  must.matrix[0][1] = -1;
  must.matrix[0][2] = 1;
  must.matrix[1][0] = -38;
  must.matrix[1][1] = 41;
  must.matrix[1][2] = -34;
  must.matrix[2][0] = 27;
  must.matrix[2][1] = -29;
  must.matrix[2][2] = 24;

  int check = s21_eq_matrix(&res, &must);
  ck_assert_int_eq(check, SUCCESS);
  ck_assert_int_eq(test, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&must);
}
END_TEST

START_TEST(inverse_matrix_simple_fract_test) {
  matrix_t A, res, must;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &must);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 6;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 1;
  int test = s21_inverse_matrix(&A, &res);
  must.matrix[0][0] = -0.04;
  must.matrix[0][1] = 0.24;
  must.matrix[1][0] = 0.2;
  must.matrix[1][1] = -0.2;
  int check = s21_eq_matrix(&res, &must);
  ck_assert_int_eq(check, SUCCESS);
  ck_assert_int_eq(test, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&must);
}
END_TEST

START_TEST(inverse_matrix_hard_test) {
  matrix_t A, must;
  matrix_t res = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &must);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -4;
  A.matrix[2][2] = -3;
  int test = s21_inverse_matrix(&A, &res);
  must.matrix[0][0] = -0.1014492754;
  must.matrix[0][1] = 0.1884057971;
  must.matrix[0][2] = 0.01449275362;
  must.matrix[1][0] = -0.5507246377;
  must.matrix[1][1] = 0.5942028986;
  must.matrix[1][2] = -0.4927536232;
  must.matrix[2][0] = 0.5652173913;
  must.matrix[2][1] = -0.4782608696;
  must.matrix[2][2] = 0.347826087;
  int check = s21_eq_matrix(&res, &must);
  ck_assert_int_eq(check, SUCCESS);
  ck_assert_int_eq(test, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&must);
}
END_TEST

START_TEST(inverse_matrix_simple_single_test_1) {
  matrix_t A, res, must;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &must);
  A.matrix[0][0] = 8;
  int test = s21_inverse_matrix(&A, &res);
  must.matrix[0][0] = 0.125;
  int check = s21_eq_matrix(&res, &must);
  ck_assert_int_eq(check, SUCCESS);
  ck_assert_int_eq(test, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&must);
}
END_TEST

START_TEST(inverse_matrix_simple_single_test_2) {
  matrix_t A, res, must;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &must);
  A.matrix[0][0] = 19;
  int test = s21_inverse_matrix(&A, &res);
  must.matrix[0][0] = 0.05263157895;
  int check = s21_eq_matrix(&res, &must);
  ck_assert_int_eq(check, SUCCESS);
  ck_assert_int_eq(test, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&must);
}
END_TEST

START_TEST(inverse_matrix_zero_det_test) {
  matrix_t A, res;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 9;
  A.matrix[0][1] = 9;
  A.matrix[1][0] = 9;
  A.matrix[1][1] = 9;
  int test = s21_inverse_matrix(&A, &res);
  ck_assert_int_eq(test, CALC_ERR);
  s21_remove_matrix(&A);
}
END_TEST

Suite *test_inverse_matrix_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("inverse_matrix_test");
  /* Core test case */
  tc = tcase_create("inverse_matrix_tc");

  // inverse_matrix
  tcase_add_test(tc, inverse_matrix_simple_test);
  tcase_add_test(tc, inverse_matrix_simple_fract_test);
  tcase_add_test(tc, inverse_matrix_hard_test);
  tcase_add_test(tc, inverse_matrix_simple_single_test_1);
  tcase_add_test(tc, inverse_matrix_simple_single_test_2);
  tcase_add_test(tc, inverse_matrix_zero_det_test);

  suite_add_tcase(s, tc);

  return s;
}
