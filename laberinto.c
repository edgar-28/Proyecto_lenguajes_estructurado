//
// Created by edgar on 16/7/20.
//

#include "laberinto.h"
#include "resolverLaberinto.h"
#include <GL/glut.h>

int gridX, gridY;

extern bool terminar;

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
    glLineWidth(2.0);
    glColor3f(0.5, 0.5, 0.5);
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

int i =1;
void dibujar_laberinto(){
    glColor3f(0.0, 1.0, 1.0);
    glPointSize(4.0);
    glBegin(GL_POINTS);
    i ++;
    if(i >= contador){
        terminar = true;
    }

    for (int j = 0; j < i && i < contador; ++j) {
        glVertex2f(solucionXY[j].x + 0.5, ((filas - 1) - solucionXY[j].y) + 0.5);
    }
    /*
    for (int j = 0; j < contador; ++j) {
        glVertex2f(solucionXY[j].x + 0.5, ((filas - 1) - solucionXY[j].y) + 0.5);
    }
    */
    glEnd();
}

