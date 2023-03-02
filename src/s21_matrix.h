#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

#define SUCCESS 1
#define FAILURE 0

#define SUB 1
#define SUM 0

enum { OK = 0, MATRIX_ERR = 1, CALC_ERR = 2 };

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);
int verifyMatrix(matrix_t *matrix);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
void operationSumSub(matrix_t *A, matrix_t *B, matrix_t *result, int sign);
int validateSumSub(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int validateMul(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
double determinantRecursive(matrix_t *A);
int minorReshape(matrix_t *A, matrix_t *result, int row, int column);

void showMatrix(matrix_t A);
void fillRandomMatrix(matrix_t *A);
void copyMatrix(matrix_t *A, matrix_t *res);

#endif  // SRC_S21_MATRIX_H_
