#include "include/main.hpp"

int main()
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Hello, World!", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    /* Load all OpenGL function pointers */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    /* Define vertices for a triangle */
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top   
    }; 

    /* Create a Vertex Buffer Object (VBO) */
    unsigned int VBO;
    glGenBuffers(1, &VBO);

    /* Bind the Vertex Buffer */
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    /* Send the vertices data to the GPU */
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    /* Create a Vertex Array Object (VAO) */
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    /* Bind the Vertex Array Object */
    glBindVertexArray(VAO);

    /* Link the vertex data and the vertex attributes */
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    /* Render loop */
    while (!glfwWindowShouldClose(window))
    {
        /* Input */
        processInput(window);

        /* Render here */
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Draw the triangle */
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    /* Terminate GLFW, clearing any resources allocated by GLFW */
    glfwTerminate();
    return 0;
}