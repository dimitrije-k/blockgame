#include "game_renderer.h"

game_renderer init_game_renderer(window* window)
{
    game_renderer self = { 0 };

    self.base_shader = load_shader("res/base.vs", "res/base.fs");
    self.base_texture = load_texture("res/blocks.png");
    self.camera = init_camera(window);

    self.camera.pos.y = 50.0f;

    return self;
}

void render_game(game_renderer* self)
{
    use_shader(&self->base_shader);
    use_texture(&self->base_texture);

    project_camera(&self->camera);
    use_camera_matrices(&self->base_shader, &self->camera);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    for (int x = 0; x < VIEW_DISTANCE * 2 + 1; x++)
    {
        for (int z = 0; z < VIEW_DISTANCE * 2 + 1; z++)
        {
            mat4 m; glm_mat4_identity(m);
            glm_translate(m, (vec3){(f32)(x-VIEW_DISTANCE) * 16.0f, 0.0f, (f32)(z-VIEW_DISTANCE) * 16.0f});

            set_model_matrix(&self->base_shader, m);

            render_mesh(&self->world->chunks[x*(VIEW_DISTANCE*2+1)+z].chunk_mesh);
        }
    }
}

void deinit_game_renderer(game_renderer* self)
{
    unload_texture(&self->base_texture);
    unload_shader(&self->base_shader);
}