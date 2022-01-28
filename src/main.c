#include <GLFW/glfw3.h>

int main(int argc, char** argv)
{
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(800, 600, "Hello, window", NULL, NULL);
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}