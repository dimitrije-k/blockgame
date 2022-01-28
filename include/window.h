#ifndef _window_h
#define _window_h

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "utils.h"

struct _window
{
    GLFWwindow* glfw_window;
    struct {
        s32 width, height;
    } mode;
};

typedef struct _window window;

window init_window(s32 width, s32 height, const char* title);

bool is_window_open(window* self);

void update_window(window* self);

void swap_window(window* self);

void deinit_window(window* self);

#endif