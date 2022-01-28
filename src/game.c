#include "game.h"

game init_game(void)
{
    game self = { 0 };

    self.window = init_window(800, 600, "Hello, game");
    self.gr = init_game_renderer(&self.window);

    return self;
}

void run_game(game* self)
{
    while (is_window_open(&self->window))
    {
        update_window(&self->window);

        glClearColor(0.6f, 0.8f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        render_game(&self->gr);

        swap_window(&self->window);
    }
}

void deinit_game(game* self)
{
    deinit_game_renderer(&self->gr);
    deinit_window(&self->window);
}