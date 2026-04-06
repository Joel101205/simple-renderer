#ifndef MATRIX_H
#define MATRIX_H

struct mat4 {
  float matrix[16];
};

struct mat4 get_mat4_identiy();

void mul_mat4(struct mat4 *a, struct mat4 *b, struct mat4 *result);

void mul_mat4_vec4(struct mat4 *mat, struct vec4 *vec, struct vec4 *result);

#endif 
