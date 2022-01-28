#include "window.h"

window init_window(s32 width, s32 height, const char* title)
{
    window self = { 0 };
    
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    self.glfw_window = glfwCreateWindow(width, height, title, NULL, NULL);
    self.mode.width = width;
    self.mode.height = height;

    glfwMakeContextCurrent(self.glfw_window);

    return self;
}

bool is_window_open(window* self)
{
    return !glfwWindowShouldClose(self->glfw_window);
}

void update_window(window* self)
{
    glfwPollEvents();
}

void swap_window(window* self)
{
    glfwSwapBuffers(self->glfw_window);
}

void deinit_window(window* self)
{
    glfwDestroyWindow(self->glfw_window);
    glfwTerminate();
}