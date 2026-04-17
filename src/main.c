#include "renderer.h"
#include "obj_parser.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  Model *teapot = read_obj_file("utah_teapot.obj");
  vec4* vertices = teapot->vertices;
  size_t n = teapot->count;

  mat4 *m_matrix = get_model_matrix((vec3){0,0,1},(vec3){100,100,100} ,(vec3) {0,0,0});
  mat4 *v_matrix = get_view_matrix((vec4) {0,0,0,1}, (vec4) {0,0,1,0}, (vec4) {0,1,0,0});
  mat4 *p_matrix = get_projection_matrix(2, 100, -100, 100, 100, -100);

  vertex_shader(vertices, n, m_matrix, v_matrix, p_matrix);
  viewport_transformation(vertices, n, 640, 480);
  
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;

  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  
  for (int i = 0; i < n; i++) {
    SDL_RenderDrawPoint(renderer, vertices[i].x, vertices[i].y);
  }

  SDL_RenderPresent(renderer);
  SDL_Delay(10000);
  
  return EXIT_SUCCESS;
}
