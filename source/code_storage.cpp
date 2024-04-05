#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>
#include <counter.h>
#include "../math_lib/include/math_cpp.h"
#include <fstream>



int main(void)
{
    
    counter(2, "output1");
    std::ofstream out2;
    out2.open("output2.log");
    mth::Matrix matrix{2, 2, {1, 2, 3, 4}};
    out2 << matrix.ToString();
    out2.close();

    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(640, 480, "draw collisions", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        GLfloat vertices[] = {
            -.5f, -.5f, .0f,
            .5f, -.5f, .0f,
            .0f, .5f, .0f
        };
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}