#include "shape.h"
void Shape::genVertexArrays() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertdata.returnArray()), vertdata.returnArray(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Shape::draw() {
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, posdata.length(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Shape::useEBO() {
    needEBO = true;
}

void Shape::noEBO() {
    needEBO = false;
}

bool Shape::checkEBONEED() {
    return needEBO;
}