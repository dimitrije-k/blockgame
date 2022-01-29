#include "window.h"
#include "game.h"

static void _key_callback(GLFWwindow* window, s32 key, s32 scancode, s32 action, s32 mods)
{
    game* game = glfwGetWindowUserPointer(window);

    switch (key)
    {
        case GLFW_KEY_A:
            game->keys.a = action == 2 ? 1 : action;
            break;
        case GLFW_KEY_D:
            game->keys.d = action == 2 ? 1 : action;
            break;
        case GLFW_KEY_S:
            game->keys.s = action == 2 ? 1 : action;
            break;
        case GLFW_KEY_W:
            game->keys.w = action == 2 ? 1 : action;
            break;
        case GLFW_KEY_LEFT_SHIFT:
            game->keys.shift = action == 2 ? 1 : action;
            break;
        case GLFW_KEY_SPACE:
            game->keys.space = action == 2 ? 1 : action;
            break;
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(game->window.glfw_window, 1);
            break;
    }
}

window init_window(s32 width, s32 height, const char* title, void* game)
{
    window self = { 0 };
    
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_RESIZABLE, false);

    self.glfw_window = glfwCreateWindow(width, height, title, NULL, NULL);
    self.mode.width = width;
    self.mode.height = height;
    self.game = game;

    glfwSetWindowUserPointer(self.glfw_window, game);

    glfwSetKeyCallback(self.glfw_window, _key_callback);

    glfwMakeContextCurrent(self.glfw_window);
    gladLoadGL();

    return self;
}

bool is_window_open(window* self)
{
    return !glfwWindowShouldClose(self->glfw_window);
}

void update_window(window* self)
{
    glfwSetWindowUserPointer(self->glfw_window, self->game);
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