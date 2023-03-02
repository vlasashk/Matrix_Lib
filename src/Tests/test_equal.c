#include "test.h"

START_TEST(eq_matrix_simple_test) {
  matrix_t A, must;
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

  must.matrix[0][0] = 2;
  must.matrix[0][1] = 5;
  must.matrix[0][2] = 7;
  must.matrix[1][0] = 6;
  must.matrix[1][1] = 3;
  must.matrix[1][2] = 4;
  must.matrix[2][0] = 5;
  must.matrix[2][1] = -2;
  must.matrix[2][2] = -3;
  int check = s21_eq_matrix(&A, &must);
  ck_assert_int_eq(check, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&must);
}
END_TEST

START_TEST(eq_matrix_simple_test_2) {
  matrix_t A, must;
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

  must.matrix[0][0] = 2;
  must.matrix[0][1] = 5;
  must.matrix[0][2] = 7;
  must.matrix[1][0] = 6;
  must.matrix[1][1] = 3;
  must.matrix[1][2] = 4;
  must.matrix[2][0] = 5;
  must.matrix[2][1] = -2;
  must.matrix[2][2] = -3.000000034534;
  int check = s21_eq_matrix(&A, &must);
  ck_assert_int_eq(check, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&must);
}
END_TEST

START_TEST(eq_matrix_simple_test_3) {
  matrix_t A, must;
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

  must.matrix[0][0] = 2;
  must.matrix[0][1] = 5;
  must.matrix[0][2] = 7;
  must.matrix[1][0] = 1;
  must.matrix[1][1] = 3;
  must.matrix[1][2] = 4;
  must.matrix[2][0] = 5;
  must.matrix[2][1] = -2;
  must.matrix[2][2] = -3;
  int check = s21_eq_matrix(&A, &must);
  ck_assert_int_eq(check, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&must);
}
END_TEST

Suite *test_eq_matrix_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("eq_matrix_test");
  /* Core test case */
  tc = tcase_create("eq_matrix_tc");

  // eq_matrix
  tcase_add_test(tc, eq_matrix_simple_test);
  tcase_add_test(tc, eq_matrix_simple_test_2);
  tcase_add_test(tc, eq_matrix_simple_test_3);

  suite_add_tcase(s, tc);

  return s;
}
