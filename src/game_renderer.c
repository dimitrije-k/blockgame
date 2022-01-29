#include "game_renderer.h"

game_renderer init_game_renderer(window* window)
{
    game_renderer self = { 0 };

    self.base_shader = load_shader("res/base.vs", "res/base.fs");
    self.base_texture = load_texture("res/blocks.png");
    self.camera = init_camera(window);

    return self;
}

void render_game(game_renderer* self)
{
    use_shader(&self->base_shader);
    use_texture(&self->base_texture);

    project_camera(&self->camera);
    use_camera_matrices(&self->base_shader, &self->camera);

    mat4 m; glm_mat4_identity(m);
    set_model_matrix(&self->base_shader, m);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    render_mesh(&self->mesh);
}

void deinit_game_renderer(game_renderer* self)
{
    deinit_mesh(&self->mesh);
    unload_texture(&self->base_texture);
    unload_shader(&self->base_shader);
}