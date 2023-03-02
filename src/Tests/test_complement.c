#include "test.h"

START_TEST(calc_complements_simple_test) {
  matrix_t A, res, must;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &must);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  int test = s21_calc_complements(&A, &res);
  must.matrix[0][0] = 0;
  must.matrix[0][1] = 10;
  must.matrix[0][2] = -20;
  must.matrix[1][0] = 4;
  must.matrix[1][1] = -14;
  must.matrix[1][2] = 8;
  must.matrix[2][0] = -8;
  must.matrix[2][1] = -2;
  must.matrix[2][2] = 4;

  int check = s21_eq_matrix(&res, &must);
  ck_assert_int_eq(check, SUCCESS);
  ck_assert_int_eq(test, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&must);
}
END_TEST

START_TEST(calc_complements_simple_small_test) {
  matrix_t A, res, must;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &must);
  A.matrix[0][0] = 6;
  A.matrix[0][1] = 5;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 7;

  int test = s21_calc_complements(&A, &res);
  must.matrix[0][0] = 7;
  must.matrix[0][1] = -3;
  must.matrix[1][0] = -5;
  must.matrix[1][1] = 6;
  int check = s21_eq_matrix(&res, &must);
  ck_assert_int_eq(check, SUCCESS);
  ck_assert_int_eq(test, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&must);
}
END_TEST

Suite *test_calc_complements_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("calc_complements_test");
  /* Core test case */
  tc = tcase_create("calc_complements_tc");

  // calc_complements
  tcase_add_test(tc, calc_complements_simple_test);
  tcase_add_test(tc, calc_complements_simple_small_test);

  suite_add_tcase(s, tc);

  return s;
}
