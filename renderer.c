#include "matrix.h"
#include "vector.h"
#include <math.h>

void model_view_projection(struct vec4 *object_vertices, long n, struct vec3 translation, struct vec3 scale, struct vec3 rotation) {
  struct mat4 m_translation = get_mat4_identiy();
  m_translation.matrix[3] = translation.x;
  m_translation.matrix[7] = translation.y;
  m_translation.matrix[11] = translation.z;

  struct mat4 m_scale = get_mat4_identiy();
  m_scale.matrix[0] = scale.x;
  m_scale.matrix[5] = scale.y;
  m_scale.matrix[10] = scale.z;

  struct mat4 m_rotation_x = get_mat4_identiy();
  m_rotation_x.matrix[5] = cos(rotation.x);
  m_rotation_x.matrix[6] = -sin(rotation.x);
  m_rotation_x.matrix[9] = sin(rotation.x);
  m_rotation_x.matrix[10] = cos(rotation.x);

  struct mat4 m_rotation_y = get_mat4_identiy();
  m_rotation_y.matrix[0] = cos(rotation.y);
  m_rotation_y.matrix[2] = -sin(rotation.y);
  m_rotation_y.matrix[8] = sin(rotation.y);
  m_rotation_y.matrix[10] = cos(rotation.y);

  struct mat4 m_rotation_z = get_mat4_identiy();
  m_rotation_z.matrix[0] = cos(rotation.z);
  m_rotation_z.matrix[1] = -sin(rotation.z);
  m_rotation_z.matrix[4] = sin(rotation.z);
  m_rotation_z.matrix[5] = cos(rotation.z);

  struct mat4 m_rotation;
  mul_mat4(&m_rotation_z, &m_rotation_y, &m_rotation);
  mul_mat4(&m_rotation, &m_rotation_x, &m_rotation);

  struct mat4 model_matrix;
  mul_mat4(&m_rotation, &m_scale, &model_matrix);
  mul_mat4(&m_translation, &model_matrix, &model_matrix);

  for (long i = 0; i < n; i++) {
    struct vec4 transformed;
    mul_mat4_vec4(&model_matrix, &object_vertices[i], &transformed);
    object_vertices[i] = transformed;
  }
}
