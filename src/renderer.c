#include "matrix.h"
#include "vector.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#define PI 3.14159265358979323846f
#define DEG2RAD(x) ((x) * (PI / 180.0f))

mat4 *get_model_matrix(vec3 translation, vec3 scale, vec3 rotation) {
  mat4 m_translation = get_mat4_identiy();
  m_translation.matrix[3] = translation.x;
  m_translation.matrix[7] = translation.y;
  m_translation.matrix[11] = translation.z;

  mat4 m_scale = get_mat4_identiy();
  m_scale.matrix[0] = scale.x;
  m_scale.matrix[5] = scale.y;
  m_scale.matrix[10] = scale.z;

  rotation.x = DEG2RAD(rotation.x);
  rotation.y = DEG2RAD(rotation.y);
  rotation.z = DEG2RAD(rotation.z);

  mat4 m_rotation_x = get_mat4_identiy();
  m_rotation_x.matrix[5] = cos(rotation.x);
  m_rotation_x.matrix[6] = -sin(rotation.x);
  m_rotation_x.matrix[9] = sin(rotation.x);
  m_rotation_x.matrix[10] = cos(rotation.x);

  mat4 m_rotation_y = get_mat4_identiy();
  m_rotation_y.matrix[0] = cos(rotation.y);
  m_rotation_y.matrix[2] = -sin(rotation.y);
  m_rotation_y.matrix[8] = sin(rotation.y);
  m_rotation_y.matrix[10] = cos(rotation.y);

  mat4 m_rotation_z = get_mat4_identiy();
  m_rotation_z.matrix[0] = cos(rotation.z);
  m_rotation_z.matrix[1] = -sin(rotation.z);
  m_rotation_z.matrix[4] = sin(rotation.z);
  m_rotation_z.matrix[5] = cos(rotation.z);

  mat4 m_rotation;
  mul_mat4(&m_rotation_z, &m_rotation_y, &m_rotation);
  mul_mat4(&m_rotation, &m_rotation_x, &m_rotation);

  mat4 *model_matrix = malloc(sizeof(mat4));  // allocate memory for model matrix
  mul_mat4(&m_rotation, &m_scale, model_matrix);
  mul_mat4(&m_translation, model_matrix, model_matrix);

  return model_matrix;  // return pointer to model matrix
}

mat4 *get_view_matrix(vec4 camera_pos, vec4 viewing_direction, vec4 up_vector) {
  mat4 translation = get_mat4_identiy();
  translation.matrix[3] = - camera_pos.x;
  translation.matrix[7] = - camera_pos.y;
  translation.matrix[11] = - camera_pos.z;

  vec4 right_vec = cross_product(viewing_direction, up_vector);
  mat4 temp = {.matrix = {right_vec.x, up_vector.x, viewing_direction.x, 0,
                          right_vec.y, up_vector.y, viewing_direction.y, 0,
                          right_vec.z, up_vector.z, viewing_direction.z, 0,
                          0          , 0          , 0                  , 1}};

  mat4 *view_matrix = malloc(sizeof(mat4));
  transpose(&temp, view_matrix);
  mul_mat4(view_matrix, &translation, view_matrix);
  
  return view_matrix;  // return pointer to view matrix
}

mat4 *get_projection_matrix(float near, float far, float right, float left, float top, float bottom) {
  mat4 m_p = {.matrix = {near, 0   , 0       , 0,
                         0   , near, 0       , 0,
                         0   , 0   , near+far, -(near*far),
                         0   , 0   , 1       , 0}};

  mat4 m_o = {.matrix = {2/(right-left), 0,              0,            -(right+left)/(right-left),
                         0,              2/(top-bottom), 0,            -(top+bottom)/(top-bottom),
                         0,              0,              2/(far-near), -(far+near)/(far-near),
                         0,              0,              0,            1}};

  mat4 *projection_matrix = malloc(sizeof(mat4));

  mul_mat4(&m_o, &m_p, projection_matrix);

  return projection_matrix;
}

// apply modelview and perspective treansformation to every vertex of the input array
// also apply the division by the w component
void vertex_shader(vec4 *vertices, size_t n, mat4 *m_matrix, mat4 *v_matrix, mat4 *p_matrix) {
  mat4 M;
  mul_mat4(v_matrix, m_matrix, &M);
  mul_mat4(p_matrix, &M, &M);

  vec4 temp;
  float w;
  for (int i = 0; i < n; i++) {
    mul_mat4_vec4(&M, vertices + i, &temp);

    w = temp.w;
    temp.x /= w;
    temp.y /= w;
    temp.z /= w;
    temp.w /= w;

    *(vertices + i) = temp;
  }
}

void viewport_transformation(vec4 *vertices, size_t n, float screen_x, float screen_y) {
  mat4 viewport_matrx = {.matrix = {0.5 * screen_x, 0,              0,   0.5 * screen_x,
                         0,              0.5 * screen_y, 0,   0.5 * screen_y,
                         0,              0,              0.5, 0.5,
                         0,              0,              0,   1}};

  for(int i = 0; i < n; i++) {
    vec4 temp;
    mul_mat4_vec4(&viewport_matrx ,(vertices + i), &temp);
    vertices[i] = temp;
  } 
}


