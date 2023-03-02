#include "test.h"

START_TEST(sub_matrix_simple_test) {
  matrix_t A, B, res, must;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &must);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 0;
  B.matrix[0][2] = 0;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 0;
  B.matrix[1][2] = 0;
  B.matrix[2][0] = 3;
  B.matrix[2][1] = 4;
  B.matrix[2][2] = 1;

  int test = s21_sub_matrix(&A, &B, &res);
  must.matrix[0][0] = 0;
  must.matrix[0][1] = 2;
  must.matrix[0][2] = 3;
  must.matrix[1][0] = -2;
  must.matrix[1][1] = 4;
  must.matrix[1][2] = 5;
  must.matrix[2][0] = -3;
  must.matrix[2][1] = -4;
  must.matrix[2][2] = 5;

  int check = s21_eq_matrix(&res, &must);
  ck_assert_int_eq(check, SUCCESS);
  ck_assert_int_eq(test, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&must);
}
END_TEST

START_TEST(sub_matrix_loop_test) {
  matrix_t m1 = {0};
  matrix_t m2 = {0};
  matrix_t m_result = {0};

  for (int i = 1; i < 20; i++) {
    for (int j = 1; j < 20; j++) {
      s21_create_matrix(i, j, &m1);
      s21_create_matrix(j, i, &m2);

      if (i == j) {
        ck_assert_int_eq(s21_sub_matrix(&m1, &m2, &m_result), OK);
      } else {
        ck_assert_int_eq(s21_sub_matrix(&m1, &m2, &m_result), CALC_ERR);
      }

      s21_remove_matrix(&m1);
      s21_remove_matrix(&m2);
      s21_remove_matrix(&m_result);
    }
  }
}
END_TEST

START_TEST(sub_matrix_simple_single_test) {
  matrix_t A, B, res, must;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  s21_create_matrix(1, 1, &must);
  A.matrix[0][0] = 45.98;
  B.matrix[0][0] = 67.9808;
  int test = s21_sub_matrix(&A, &B, &res);
  must.matrix[0][0] = 45.98 - 67.9808;
  int check = s21_eq_matrix(&res, &must);
  ck_assert_int_eq(check, SUCCESS);
  ck_assert_int_eq(test, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&must);
}
END_TEST

Suite *test_sub_matrix_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("sub_matrix_test");
  /* Core test case */
  tc = tcase_create("sub_matrix_tc");

  // sub_matrix
  tcase_add_test(tc, sub_matrix_simple_test);
  tcase_add_test(tc, sub_matrix_loop_test);
  tcase_add_test(tc, sub_matrix_simple_single_test);

  suite_add_tcase(s, tc);

  return s;
}
