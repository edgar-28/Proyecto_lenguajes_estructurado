
//
// Created by yerguerrero on 12/7/20.
//

#ifndef RESOLVERLABERINTOS_RESOLVERLABERINTO_H
#define RESOLVERLABERINTOS_RESOLVERLABERINTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 10000
#define MAX 10000
#define NORTE 0
#define OESTE 1
#define SUR 2
#define ESTE 3
#define TEST(a,b) ((a) & (1<<(b)))// 10 10
#define FPS 10
int n;
char linea[MAX];
int lineas[MAX];

int oeste;
int norte;
int valor;
struct pair {
    int a;
    int b;
}par;
struct punto {
    int x;
    int y;
}punto;
int puntoAx;
int puntoAy;
int filas;
int columnas;
int matriz[MAX][MAX];
int matrizOrig[MAX][MAX];
struct pair grafo[MAX];
int numNodos;
int direcciones[MAX][MAX];
int contadorG;
int solucionBfs[MAX];
struct pair sol[MAX];
struct punto solucionXY[MAX];
int solucionDfs[MAX];
struct pair arregloBits[MAX];
int resultadosR [MAX];
int contador;
int contBfs;
int contDfs;
int inicio;
int final;
int nodosiguiente;
int contadorBits;
int contReiniciar;
int contPosicion;
int resultado;
int cant_pares;
int dir;
struct queue *createQueue();
void enqueue(struct queue *q, int);
void printQueue(struct queue* q);
int dequeue(struct queue *q);
int isEmpty(struct queue *q);
#endif //RESOLVERLABERINTOS_RESOLVERLABERINTO_H

