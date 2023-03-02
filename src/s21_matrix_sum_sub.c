#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = validateSumSub(A, B, result);
  if (res == OK) {
    operationSumSub(A, B, result, SUM);
  }
  return res;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = validateSumSub(A, B, result);
  if (res == OK) {
    operationSumSub(A, B, result, SUB);
  }
  return res;
}
