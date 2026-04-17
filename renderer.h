#ifndef RENDERER_H
#define RENDERER_H
#include "matrix.h"
#include "vector.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include "obj_parser.h"

mat4* get_model_matrix(vec3 translation, vec3 scale, vec3 rotation);

mat4 *get_view_matrix(vec4 camera_pos, vec4 viewing_direction, vec4 up_vector);

mat4 *get_projection_matrix(float near, float far, float right, float left, float top, float bottom);

void vertex_shader(vec4 *vertices, size_t n, mat4 *m_matrix, mat4 *v_matrix, mat4 *p_matrix);

void viewport_transformation(vec4 *vertices, size_t n, float screen_x, float screen_y);

#endif // 
