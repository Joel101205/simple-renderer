#include "vector.h"

vec3 add_vec3(vec3 a,  vec3 b) {
   vec3 c = {a.x + b.x, a.y + b.y, a.z + b.z};
  return c;
}

vec4 add_vec4(vec4 a, vec4 b) {
   vec4 c =  {a.x + b.x, a.y + b.y, a.z + b.z, a.w};
  return c;
}

 vec4 cross_product( vec4 a,  vec4 b) {
   vec4 result = {a.y*b.z - a.z*b.y, 
                        a.z*b.x - a.x*b.z,
                        a.x*b.y - a.y*b.x,
                        1};
  return result;
}


