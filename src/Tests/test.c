#include "test.h"

int run_tests(Suite *test_case) {
  int number_failed;
  SRunner *sr = srunner_create(test_case);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}

void showMatrix(matrix_t A) {
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      printf("%f ", A.matrix[i][j]);
    }
    printf("\b\n");
  }
}

int main() {
  /* UNCOMMENT TO RUN MAIN TESTS */

  int number_failed = 0;
  Suite *suites_list[] = {
      test_calc_complements_suite(), test_create_matrix_suite(),
      test_determinant_suite(),      test_eq_matrix_suite(),
      test_mult_matrix_suite(),      test_mult_number_suite(),
      test_remove_matrix_suite(),    test_sub_matrix_suite(),
      test_sum_matrix_suite(),       test_transpose_suite(),
      test_inverse_matrix_suite(),   NULL};
  for (Suite **current = suites_list; *current != NULL; current++) {
    printf("_______________________________________\n");
    number_failed += run_tests(*current);
  }

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

  // // s21_mult_matrix(&A, &B, &R);

  // // minorReshape(&R2, &R, 2, 0);
  // // showMatrix(R2);
  // // printf("--------------\n");
  // // showMatrix(R);
  // matrix_t A, res, must;
  // s21_create_matrix(3, 3, &A);
  // s21_create_matrix(3, 3, &must);
  // A.matrix[0][0] = 2;
  // A.matrix[0][1] = 5;
  // A.matrix[0][2] = 7;
  // A.matrix[1][0] = 6;
  // A.matrix[1][1] = 3;
  // A.matrix[1][2] = 4;
  // A.matrix[2][0] = 5;
  // A.matrix[2][1] = -4;
  // A.matrix[2][2] = -3;
  // s21_inverse_matrix(&A, &res);
  // must.matrix[0][0] = -0.1014492754;
  // must.matrix[0][1] = 0.1884057971;
  // must.matrix[0][2] = 0.01449275362;
  // must.matrix[1][0] = -0.5507246377;
  // must.matrix[1][1] = 0.5942028986;
  // must.matrix[1][2] = -0.4927536232;
  // must.matrix[2][0] = 0.5652173913;
  // must.matrix[2][1] = -0.4782608696;
  // must.matrix[2][2] = 0.347826087;

  // s21_remove_matrix(&A);
  // s21_remove_matrix(&res);
  // s21_remove_matrix(&must);
  // return 0;
}
