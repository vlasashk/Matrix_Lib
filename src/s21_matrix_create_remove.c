#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = OK;
  if (rows < 1 || columns < 1) {
    res = MATRIX_ERR;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix != NULL) {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          res = MATRIX_ERR;
          for (int j = 0; j < i; i++) {
            free(result->matrix[j]);
          }
          free(result->matrix);
          break;
        }
      }
    } else {
      res = MATRIX_ERR;
    }
  }
  return res;
}

void s21_remove_matrix(matrix_t *A) {
  if (A->matrix) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->matrix = NULL;
  }
  if (A->columns) {
    A->columns = 0;
  }
  if (A->rows) {
    A->rows = 0;
  }
}
