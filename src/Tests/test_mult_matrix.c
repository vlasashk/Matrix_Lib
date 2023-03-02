#include "test.h"

START_TEST(mult_matrix_simple_test) {
  matrix_t A, B, res, must;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &must);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;
  B.matrix[1][2] = 4;

  must.matrix[0][0] = 9;
  must.matrix[0][1] = 11;
  must.matrix[0][2] = 17;
  must.matrix[1][0] = 12;
  must.matrix[1][1] = 13;
  must.matrix[1][2] = 22;
  must.matrix[2][0] = 15;
  must.matrix[2][1] = 15;
  must.matrix[2][2] = 27;

  int test = s21_mult_matrix(&A, &B, &res);

  int check = s21_eq_matrix(&res, &must);
  ck_assert_int_eq(check, SUCCESS);
  ck_assert_int_eq(test, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&must);
}
END_TEST

START_TEST(mult_matrix_simple_test_2) {
  matrix_t A, MUL, res, must;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &MUL);
  s21_create_matrix(3, 3, &must);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 2;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = 6;

  MUL.matrix[0][0] = 1;
  MUL.matrix[0][1] = -1;
  MUL.matrix[0][2] = 1;
  MUL.matrix[1][0] = 2;
  MUL.matrix[1][1] = 3;
  MUL.matrix[1][2] = 4;
  MUL.matrix[2][0] = 2;
  MUL.matrix[2][1] = 3;
  MUL.matrix[2][2] = 4;

  must.matrix[0][0] = 13;
  must.matrix[0][1] = 17;
  must.matrix[0][2] = 25;
  must.matrix[1][0] = 23;
  must.matrix[1][1] = 22;
  must.matrix[1][2] = 41;
  must.matrix[2][0] = 23;
  must.matrix[2][1] = 22;
  must.matrix[2][2] = 41;

  int test = s21_mult_matrix(&A, &MUL, &res);

  int check = s21_eq_matrix(&res, &must);
  ck_assert_int_eq(check, SUCCESS);
  ck_assert_int_eq(test, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&MUL);
  s21_remove_matrix(&res);
  s21_remove_matrix(&must);
}
END_TEST

START_TEST(mult_matrix_simple_single_test) {
  matrix_t A, B, res, must;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  s21_create_matrix(1, 1, &must);
  A.matrix[0][0] = 8;

  B.matrix[0][0] = 1.33;

  must.matrix[0][0] = 8 * 1.33;

  int test = s21_mult_matrix(&A, &B, &res);

  int check = s21_eq_matrix(&res, &must);
  ck_assert_int_eq(check, SUCCESS);
  ck_assert_int_eq(test, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&must);
}
END_TEST

Suite *test_mult_matrix_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("mult_matrix_test");
  /* Core test case */
  tc = tcase_create("mult_matrix_tc");

  // mult_matrix
  tcase_add_test(tc, mult_matrix_simple_test);
  tcase_add_test(tc, mult_matrix_simple_test_2);
  tcase_add_test(tc, mult_matrix_simple_single_test);

  suite_add_tcase(s, tc);

  return s;
}
