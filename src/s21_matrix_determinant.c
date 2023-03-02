#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int res = verifyMatrix(A);
  if (A->rows != A->columns) {
    res = CALC_ERR;
  }
  if (res == OK) {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else {
      *result = determinantRecursive(A);
    }
  }
  return res;
}

double determinantRecursive(matrix_t *A) {
  double res = 0.0;
  if (A->rows == 2) {
    res = A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    for (int i = 0; i < A->rows; i++) {
      matrix_t minor = {0};
      minorReshape(A, &minor, i, 0);
      res += pow((-1), i) * A->matrix[i][0] * determinantRecursive(&minor);
      s21_remove_matrix(&minor);
    }
  }
  return res;
}

int minorReshape(matrix_t *A, matrix_t *result, int row, int column) {
  int res = s21_create_matrix(A->rows - 1, A->columns - 1, result);
  if (res == OK) {
    for (int i = 0, k = 0; i < A->rows; i++, k++) {
      if (i == row) {
        i++;
      }
      for (int j = 0, m = 0; j < A->columns; j++, m++) {
        if (j == column) {
          j++;
        }
        if (i < A->rows && j < A->columns) {
          result->matrix[k][m] = A->matrix[i][j];
        }
      }
    }
  }
  return res;
}
