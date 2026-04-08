#include "vector.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

vec4 *read_obj_file(const char* path) {
  vec4 *vertices = NULL;
  size_t vertex_count = 0;

  FILE *file = fopen(path, "r");
  if (file == NULL) {
    printf("Could not open the file");
    return NULL;
  }
  
  char buf[256];
  while (fgets(buf, sizeof(buf), file) != NULL) {
    if (strncmp(buf, "v ", 2) == 0) {
      vec4 vertex;
      sscanf(buf, "v %f %f %f", &vertex.x, &vertex.y, &vertex.z);
      vertex.w = 1.0;
      
      vertices = realloc(vertices, (vertex_count + 1) * sizeof(vec4));
      vertices[vertex_count] = vertex;
      vertex_count++;
    }
  }

  return vertices;
}
