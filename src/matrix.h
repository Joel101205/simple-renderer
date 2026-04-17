#ifndef MATRIX_H
#define MATRIX_H
#include "vector.h"

typedef struct {
  float matrix[16];
} mat4;

mat4 get_mat4_identiy();

void mul_mat4(mat4 *a, mat4 *b, mat4 *result);

void mul_mat4_vec4(mat4 *mat, vec4 *vec, vec4 *result);

void transpose(mat4 *mat, mat4 *result);

#endif 
