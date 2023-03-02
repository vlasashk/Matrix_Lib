#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = verifyMatrix(A);
  if (A->rows != A->columns) {
    res = CALC_ERR;
  }
  if (res == OK) {
    res = s21_create_matrix(A->rows, A->columns, result);
  }
  if (res == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor = {0};
        double temp_det = 0.0;
        minorReshape(A, &minor, i, j);
        s21_determinant(&minor, &temp_det);
        result->matrix[i][j] = pow((-1), i + j) * temp_det;
        s21_remove_matrix(&minor);
      }
    }
  }
  return res;
}
