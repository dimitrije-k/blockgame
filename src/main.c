#include "window.h"
#include "mesh.h"
#include "shader.h"

struct vertex vertices[] = {
    {-0.5f, -0.5f, 0.0f},
    { 0.5f, -0.5f, 0.0f},
    { 0.0f,  0.5f, 0.0f}
};

u32 indices[] = {
    0, 1, 2
};

int main(int argc, char** argv)
{
    window win = init_window(800, 600, "Window");
    mesh m = init_mesh(vertices, 3, indices, 3);
    shader sh = load_shader("res/base.vs", "res/base.fs");

    while (is_window_open(&win))
    {
        update_window(&win);

        glClearColor(0.6f, 0.8f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        use_shader(&sh);
        render_mesh(&m);

        swap_window(&win);
    }

    unload_shader(&sh);
    deinit_mesh(&m);
    deinit_window(&win);
    return 0;
}