#ifndef _game_renderer_h
#define _game_renderer_h

#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "camera.h"

struct _game_renderer
{
    mesh mesh;
    shader base_shader;
    texture base_texture;
    camera camera;
};

typedef struct _game_renderer game_renderer;

game_renderer init_game_renderer(window* window);

void render_game(game_renderer* self);

void deinit_game_renderer(game_renderer* self);

#endif