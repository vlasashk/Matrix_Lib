#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = verifyMatrix(A);
  double det = 0.0;
  if (A->rows != A->columns) {
    res = CALC_ERR;
  }
  if (res == OK) {
    s21_determinant(A, &det);
    if (fabs(det) < 1e-6) {
      res = CALC_ERR;
    }
  }
  if (res == OK) {
    res = s21_create_matrix(A->rows, A->columns, result);
  }
  if (A->rows != 1 && res == OK) {
    matrix_t minor = {0};
    matrix_t temp_trans = {0};
    res = s21_calc_complements(A, &minor);
    if (res == OK) {
      res = s21_transpose(&minor, &temp_trans);
      s21_remove_matrix(&minor);
    }
    if (res == OK) {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = temp_trans.matrix[i][j] / det;
        }
      }
    }
    s21_remove_matrix(&temp_trans);
  } else if (res == OK) {
    result->matrix[0][0] = 1 / det;
  }
  return res;
}
