#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"

Suite *test_calc_complements_suite(void);
Suite *test_create_matrix_suite(void);
Suite *test_determinant_suite(void);
Suite *test_eq_matrix_suite(void);
Suite *test_inverse_matrix_suite(void);
Suite *test_mult_matrix_suite(void);
Suite *test_mult_number_suite(void);
Suite *test_remove_matrix_suite(void);
Suite *test_sub_matrix_suite(void);
Suite *test_sum_matrix_suite(void);
Suite *test_transpose_suite(void);

#endif  // SRC_TESTS_TEST_H_
