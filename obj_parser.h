#ifndef OBJ_PARSER_H
#define OBJ_PARSER_H
#include "vector.h"

typedef struct{
  int count;
  vec4 *vertices;
} Model ;

Model *read_obj_file(const char* path);

#endif
