#include "game.h"

struct vertex vertices[4] = {
    {0.0f, 0.0f, 0.0f,   1.0f, 1.0f, 1.0f, 0.0f, 0.0625f},
    {1.0f, 0.0f, 0.0f,   1.0f, 1.0f, 1.0f, 0.0625f, 0.0625f},
    {1.0f, 1.0f, 0.0f,   1.0f, 1.0f, 1.0f, 0.0625f, 0.0},
    {0.0f, 1.0f, 0.0f,   1.0f, 1.0f, 1.0f, 0.0, 0.0}
};

u32 indices[6] = {
    0, 1, 2,
    0, 2, 3
};

game init_game(void)
{
    game self = { 0 };

    self.window = init_window(800, 600, "Hello, game", &self);
    self.gr = init_game_renderer(&self.window);

    self.world = init_world();
    self.gr.world = &self.world;

    return self;
}

void run_game(game* self)
{
    while (is_window_open(&self->window))
    {
        self->window.game = self;
        update_window(&self->window);

        // Move camera
        self->gr.camera.pos.x += ((float) self->keys.w - (float) self->keys.s) * self->delta_time * 8.0f * sinf(glm_rad(self->gr.camera.rot.x));
        self->gr.camera.pos.z += ((float) self->keys.w - (float) self->keys.s) * self->delta_time * 8.0f * cosf(glm_rad(self->gr.camera.rot.x));

        self->gr.camera.pos.x += ((float) self->keys.a - (float) self->keys.d) * self->delta_time * 8.0f * sinf(glm_rad(self->gr.camera.rot.x+90.0f));
        self->gr.camera.pos.z += ((float) self->keys.a - (float) self->keys.d) * self->delta_time * 8.0f * cosf(glm_rad(self->gr.camera.rot.x+90.0f));

        self->gr.camera.pos.y += ((float) self->keys.space - (float) self->keys.shift) * 9.0f * self->delta_time;

        if (glfwGetMouseButton(self->window.glfw_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
        {
            glfwSetInputMode(self->window.glfw_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

            double mx, my;
            glfwGetCursorPos(self->window.glfw_window, &mx, &my);
            double dw = (double) self->window.mode.width;
            double dh = (double) self->window.mode.height;

            self->gr.camera.rot.x -= (float)(mx - dw / 2.0) * 0.1f;
            self->gr.camera.rot.y += (float)(my - dh / 2.0) * 0.1f;

            self->gr.camera.rot.y = CLAMPF(self->gr.camera.rot.y, 0.1f, 179.0f);

            glfwSetCursorPos(self->window.glfw_window, dw / 2.0, dh / 2.0);
        }
        else if (glfwGetMouseButton(self->window.glfw_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
        {
            glfwSetInputMode(self->window.glfw_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        }

        glClearColor(0.6f, 0.8f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        render_game(&self->gr);

        swap_window(&self->window);

        self->delta_time = (float)glfwGetTime() - self->last_update;
        self->last_update = (float)glfwGetTime();
    }
}

void deinit_game(game* self)
{
    deinit_world(&self->world);
    deinit_game_renderer(&self->gr);
    deinit_window(&self->window);
}