#include "vector.h"
#include "matrix.h"


mat4 get_mat4_identiy() {
  return (mat4){
    .matrix = {
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, 1, 0,
      0, 0, 0, 1
    }
  };
}

void mul_mat4(mat4 *a, mat4 *b, mat4 *result){
  mat4 temp;

  for (int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++) {
      temp.matrix[i * 4 + j] = 
          a->matrix[i * 4 + 0] * b->matrix[0 * 4 + j] +
          a->matrix[i * 4 + 1] * b->matrix[1 * 4 + j] +
          a->matrix[i * 4 + 2] * b->matrix[2 * 4 + j] +
          a->matrix[i * 4 + 3] * b->matrix[3 * 4 + j];
    }
  }

  *result = temp;
}

void mul_mat4_vec4(mat4 *mat, vec4 *vec, vec4 *result) {
  vec4 temp;

  temp.x = mat->matrix[0] * vec->x + mat->matrix[1] * vec->y + mat->matrix[2] * vec->z + mat->matrix[3] * vec->w;
  temp.y = mat->matrix[4] * vec->x + mat->matrix[5] * vec->y + mat->matrix[6] * vec->z + mat->matrix[7] * vec->w;
  temp.z = mat->matrix[8] * vec->x + mat->matrix[9] * vec->y + mat->matrix[10] * vec->z + mat->matrix[11] * vec->w;
  temp.w = mat->matrix[12] * vec->x + mat->matrix[13] * vec->y + mat->matrix[14] * vec->z + mat->matrix[15] * vec->w;

  *result = temp;
}

void transpose(mat4 *mat, mat4 *result) {
  mat4 temp;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      temp.matrix[i + j * 4] = mat->matrix[i * 4 + j];
    }
  }

  *result = temp;
}
