#ifndef VECTOR_H
#define VECTOR_H

struct vec3 {
  float x;
  float y;
  float z;
};

struct vec4 {
  float x;
  float y;
  float z;
  float w;
};

struct vec3 add_vec3(struct vec3 a, struct vec3 b);

struct vec4 add_vec4(struct vec4 a, struct vec4 b); 

struct vec4 cross_product(struct vec4 a, struct vec4 b);

#endif 




