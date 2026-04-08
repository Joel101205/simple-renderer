#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
  float x;
  float y;
  float z;
} vec3;

typedef struct {
  float x;
  float y;
  float z;
  float w;
} vec4;

vec3 add_vec3(vec3 a, vec3 b);

vec4 add_vec4(vec4 a, vec4 b); 

vec4 cross_product(vec4 a, vec4 b);

#endif 




