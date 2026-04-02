#include "vector.h"

struct vec3 add_vec3(struct vec3 a, struct vec3 b) {
  struct vec3 c = {a.x + b.x, a.y + b.y, a.z + b.z};
  return c;
}

struct vec4 add_vec4(struct vec4 a, struct vec4 b) {
  struct vec4 c =  {a.x + b.x, a.y + b.y, a.z + b.z, a.w};
  return c;
}


