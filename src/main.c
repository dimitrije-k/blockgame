#include "window.h"

int main(int argc, char** argv)
{
    window win = init_window(800, 600, "Window");

    while (is_window_open(&win))
    {
        update_window(&win);
        glClearColor(0.6f, 0.8f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        swap_window(&win);
    }

    deinit_window(&win);
    return 0;
}