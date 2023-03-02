#include "s21_matrix.h"

int verifyMatrix(matrix_t *matrix) {
  int res = OK;
  if (matrix->columns < 1 || matrix->rows < 1 || matrix->matrix == NULL) {
    res = MATRIX_ERR;
  }
  return res;
}

void operationSumSub(matrix_t *A, matrix_t *B, matrix_t *result, int sign) {
  result->rows = A->rows;
  result->columns = A->columns;
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      if (sign == SUM) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      } else {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
}

int validateSumSub(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (A->rows != B->rows || A->columns != B->columns) {
    res = CALC_ERR;
  } else if (verifyMatrix(A) != OK || verifyMatrix(B) != OK) {
    res = MATRIX_ERR;
  } else {
    res = s21_create_matrix(A->rows, A->columns, result);
  }
  return res;
}

int validateMul(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (A->columns != B->rows) {
    res = CALC_ERR;
  } else if (verifyMatrix(A) != OK || verifyMatrix(B) != OK) {
    res = MATRIX_ERR;
  } else {
    res = s21_create_matrix(A->rows, B->columns, result);
  }
  return res;
}
