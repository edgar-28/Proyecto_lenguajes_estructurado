
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
int n = 0;
char linea[MAX];
int lineas[MAX];

int oeste;
int norte;
int valor=0;
struct pair {
    int a;
    int b;
}par;
int filas = 0;
int columnas = 0;
int matriz[MAX][MAX];
int matrizOrig[MAX][MAX];
struct pair grafo[MAX];
int numNodos = 0;
int direcciones[MAX][MAX];
int contadorG=0;
int solucionBfs[MAX];
struct pair sol[MAX];
int solucionDfs[MAX];
int contador;
int contBfs;
int contDfs;
int inicio;
int final;
int nodosiguiente;
struct queue *createQueue();
void enqueue(struct queue *q, int);
void printQueue(struct queue* q);
int dequeue(struct queue *q);
int isEmpty(struct queue *q);
#endif //RESOLVERLABERINTOS_RESOLVERLABERINTO_H

