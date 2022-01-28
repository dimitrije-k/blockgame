#include "window.h"

int main(int argc, char** argv)
{
    window win = init_window(800, 600, "Window");

    while (is_window_open(&win))
    {
        update_window(&win);
        swap_window(&win);
    }

    deinit_window(&win);
    return 0;
}