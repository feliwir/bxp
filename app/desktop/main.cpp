#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include "Application.hpp"
#include "GLRenderer.hpp"

static void error_callback(int error, const char* description)
{
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(int argc, char** argv)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    auto app = std::make_unique<bxp::Application>(new bxp::GLRenderer());

    window = glfwCreateWindow(640, 480, "Bxp", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    app->OnInitialize();

    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(window)) {

        app->GetRenderer().Begin();
        app->GetRenderer().End();

        glfwSwapBuffers(window);
        glfwPollEvents();

        app->OnUpdate();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}