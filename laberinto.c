//
// Created by edgar on 16/7/20.
//

#include "laberinto.h"
#include "resolverLaberinto.h"
#include <GL/glut.h>

int gridX, gridY;

void initGrid(int x, int y) {
    gridX = x;
    gridY = y;
}

void unit(int, int, int, int);

void drawGrid() {
    int posNodo = 0;
    for (int y = gridY-1; y >=0; --y) {
        for (int x = 0; x < gridX; ++x) {
            for (int l = 0; l < 4; ++l) {
                unit(x, y, l, posNodo);
            }
            posNodo ++;
        }
    }
}

void unit(int x, int y, int l, int nodo) {
    glLineWidth(3.0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    if (direcciones[nodo][l] == -1 && l == 0) {
        glVertex2f(x, y + 1);
        glVertex2f(x + 1, y + 1);
    } else if (direcciones[nodo][l] == -1 && l == 1) {
        glVertex2f(x, y);
        glVertex2f(x, y + 1);
    } else if (direcciones[nodo][l] == -1 && l == 2) {
        glVertex2f(x, y);
        glVertex2f(x + 1, y);
    } else if (direcciones[nodo][l] == -1 && l == 3) {
        glVertex2f(x + 1, y);
        glVertex2f(x + 1, y + 1);
    }
    glEnd();
}













/*
void initGrid(int x, int y) {
    gridX = x;
    gridY = y;
}

void unit(int, int, int);

void drawGrid() {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            for (int l = 0; l < 4; ++l) {
                unit(i,j,l);
            }
        }
    }
}

void unit(int i ,int j, int l) {

    glLineWidth(1.0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        if (direcciones[((i * columnas) - 1) + j][l] == -1 && l == 0) {
            glColor3f(1.0, 0.0, 0.0);
            printf("Fila: %d\n", i);
            printf("Columna: %d\n", j);
            printf("L: %d\n", l);
            glVertex2f(i, j);
            glVertex2f(i + 1, j);
            glEnd();
        }
        else if (direcciones[((i * columnas) - 1) + j][l] == -1 && l == 1) {
            glColor3f(0.0, 1.0, 0.0);
            printf("Fila: %d\n", i);
            printf("Columna: %d\n", j);
            printf("L: %d\n", l);
            glVertex2f(i, j);
            glVertex2f(i, j + 1);
            glEnd();
        }
        else if (direcciones[((i * columnas) - 1) + j][l] == -1 && l == 2) {
            glColor3f(0.0, 0.0, 1.0);
            printf("Fila: %d\n", i);
            printf("Columna: %d\n", j);
            printf("L: %d\n", l);
            glVertex2f(i, j + 1);
            glVertex2f(i + 1, j + 1);
            glEnd();
        }
        else if (direcciones[((i * columnas) - 1) + j][l] == -1 && l == 3) {
            glColor3f(0.0, 1.0, 1.0);
            printf("Fila: %d\n", i);
            printf("Columna: %d\n", j);
            printf("L: %d\n", l);
            glVertex2f(i + 1, j);
            glVertex2f(i + 1, j + 1);
            glEnd();
        }
    glEnd();
}
*/
