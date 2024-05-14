#include "include/main.hpp"

int main()
{
    /* Initialisiere die Bibliothek */
    if (!glfwInit()) {
        return -1;
    }

    /* Erstelle ein Fenster im Fenstermodus und dessen OpenGL-Kontext */
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Hello, World!", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    /* Mache den Kontext des Fensters aktuell */
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    /* Lade alle OpenGL-Funktionszeiger */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Fehler beim Initialisieren von GLAD" << std::endl;
        return -1;
    }

    /* Definiere die Vertices für ein Dreieck */
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // links  
         0.5f, -0.5f, 0.0f, // rechts 
         0.0f,  0.5f, 0.0f  // oben   
    }; 

    /* Erstelle ein Vertex Buffer Object (VBO) */
    unsigned int VBO;
    glGenBuffers(1, &VBO);

    /* Binde den Vertex Buffer */
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    /* Sende die Vertex-Daten an die GPU */
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    /* Erstelle ein Vertex Array Object (VAO) */
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    /* Binde das Vertex Array Object */
    glBindVertexArray(VAO);

    /* Verknüpfe die Vertex-Daten und die Vertex-Attribute */
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    /* Render-Schleife */
    while (!glfwWindowShouldClose(window)) {
        /* Eingabe verarbeiten */
        processInput(window);

        /* Rendern */
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Zeichne das Dreieck */
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Tausche Vorder- und Rückpuffer */
        glfwSwapBuffers(window);

        /* Warte auf und verarbeite Events */
        glfwPollEvents();
    }

    /* Beende GLFW und räume alle von GLFW belegten Ressourcen auf */
    glfwTerminate();
    return 0;
}
