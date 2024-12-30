#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<cmath>
#include<chrono>
#include<thread>

int main() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    gladLoadGL();

    glViewport(0, 0, 800, 600);

    // Loop to change the color of the window like a rainbow
    for (float i = 0.0f; i < 100.0f; i++) {
        // Use sine and cosine to create smooth rainbow transitions
        float r = (sin(i * 0.1f) + 1.0f) / 2.0f;  // Normalize to [0.0, 1.0]
        float g = (sin(i * 0.1f + 2.0f) + 1.0f) / 2.0f;
        float b = (sin(i * 0.1f + 4.0f) + 1.0f) / 2.0f;

        glClearColor(r, g, b, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);

		// Sleep for a short duration to see the color change
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
