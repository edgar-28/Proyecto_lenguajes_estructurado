//
// Created by yerguerrero on 12/7/20.
//

#include "resolverLaberinto.h"
#include <stdio.h>
#include <stdlib.h>


struct queue {
    int items[SIZE];
    int front;
    int rear;
};

struct queue *createQueue();

void enqueue(struct queue *q, int);

int dequeue(struct queue *q);

int isEmpty(struct queue *q);

struct node {
    int vertex;
    struct node *next;
};

struct node *createNode(int);

struct Graph {
    int numVertices;
    struct node **adjLists;//[(a,b),(a,b)]
    int *visited;
};

//DFS
void dfs(struct Graph *graph, int start, int end) {
    struct node *adjList = graph->adjLists[start];
    struct node *temp = adjList;
    graph->visited[start] = 1;
    solucionDfs[contDfs] = start;
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0 && graph->visited[end] == 0) {
            contDfs++;
            dfs(graph, connectedVertex, end);
        }
        temp = temp->next;
    }
}

// BFS algorithm
void bfs(struct Graph *graph, int startVertex, int endVertex) {
    contBfs = 0;
    struct queue *q = createQueue();
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);
    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        solucionBfs[contBfs] = currentVertex;
        struct node *temp = graph->adjLists[currentVertex];

        while (temp && graph->visited[endVertex] == 0) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
        contBfs++;
    }
}

// Creating a node
struct node *createNode(int v) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Creating a graph
struct Graph *createGraph(int vertices) {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node *));
    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add edge
void addEdge(struct Graph *graph, int src, int dest) {
    // Add edge from src to dest
    struct node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Create a queue
struct queue *createQueue() {
    struct queue *q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
int isEmpty(struct queue *q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

// Adding elements into queue
void enqueue(struct queue *q, int value) {
    if (q->rear == SIZE - 1) {

    } else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Removing elements from queue
int dequeue(struct queue *q) {
    int item;
    if (isEmpty(q)) {
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

void crearMatriz() {
    int i = 0;
    int j = 0;
    while (scanf("%s\n", linea) == 1) {
        while (j < strlen(linea)) {
            lineas[i] = linea[j];
            i += 1;
            j += 1;
        }
        columnas = j;
        filas += 1;
        j = 0;
    }

    matriz[filas][columnas];

    for (int x = 0; x < filas; ++x) {
        for (int y = 0; y < columnas; ++y) {
            if (lineas[n] != '\n' & n <= (filas * columnas)) {
                matriz[x][y] = lineas[n] - 48;
                n++;
            } else {
                n++;
                y--;
            }
        }
    }
}


void imprimirMatriz(int arr[MAX][MAX], const int filas, const int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

void matrizDirecciones() {
    int nodo = 0;
    numNodos = filas * columnas;
    direcciones[numNodos][4];
    for (int m = 0; m < numNodos; ++m) {
        for (int k = 0; k < 4; ++k) {
            direcciones[m][k] = -1;
        }
    }
    for (int k = 0; k < filas; ++k) {//matriz
        for (int l = 0; l < columnas; ++l) {
            valor = matriz[k][l];
            if (valor == 0) {
                nodo++;
            } else if (valor == 1) {
                oeste = nodo - 1;
                direcciones[nodo][OESTE] = oeste;//oeste
                direcciones[oeste][ESTE] = nodo;//este
                nodo++;
            } else if (valor == 2) {
                norte = nodo - columnas;
                direcciones[nodo][NORTE] = norte;//norte
                direcciones[norte][SUR] = nodo;//sur
                nodo++;
            } else if (valor == 3) {
                oeste = nodo - 1;
                norte = nodo - columnas;
                direcciones[nodo][NORTE] = norte;//norte
                direcciones[norte][SUR] = nodo;//sur
                direcciones[nodo][OESTE] = oeste;//oeste
                direcciones[oeste][ESTE] = nodo;//este
                nodo++;
            }
        }
    }

}

void crearGrafo() {
    contadorG = 0;
    for (int i = 0; i < numNodos; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i < direcciones[i][j]) {
                if (direcciones[i][j] != -1) {
                    par.a = i;
                    par.b = direcciones[i][j];
                    grafo[contadorG] = par;
                    contadorG++;
                }
            }
        }
    }
}

void nodosMatriz() {
    int nodo = 0;
    for (int k = 0; k < filas; ++k) {
        for (int i = 0; i < columnas; ++i) {
            matrizOrig[k][i] = nodo;
            nodo++;
        }
    }
}

void direccionesSolucion(int contSol, int solucion[MAX]) {
    nodosiguiente = 1;
    bool primero = true;
    int i = 0;
    bool conectados = false;
    bool salir = false;
    contador = 0;
    while (i < contSol && !salir) {
        conectados = false;
        int nodo = solucion[i];
        for (int j = 0; j < 4 && !conectados; ++j) {
            if (direcciones[nodo][j] == solucion[nodosiguiente]) {
                par.a = nodo;//Origen
                par.b = j;//direccion
                sol[contador] = par;
                contador++;
                conectados = true;
            }
        }
        if (i == 0 && !primero && conectados == false) {
            i = nodosiguiente;
        }
        primero = false;

        if (solucion[nodosiguiente] == solucion[contSol]) {
            salir = true;
        }
        if (conectados == false) {
            i--;
        } else {
            nodosiguiente++;
            i++;
        }
    }
}

int main(int args, char *argsv[]) {
    int puntoAx = atoi(argsv[1]);
    int puntoAy = atoi(argsv[2]);
    int puntoBx = atoi(argsv[3]);
    int puntoBy = atoi(argsv[4]);
    //int casillas= atoi(argsv[5]);
    crearMatriz();
    //imprimirMatriz(matriz,filas,columnas);
    matrizDirecciones();
    imprimirMatriz(direcciones, numNodos, 4);
    crearGrafo();

    nodosMatriz();
    //imprimirMatriz(matrizOrig,filas,columnas);
    inicio = matrizOrig[puntoAx][puntoAy];
    final = matrizOrig[puntoBx][puntoBy];
    struct Graph *graph = createGraph(numNodos);

    for (int i = 0; i < numNodos; ++i) {
        addEdge(graph, grafo[i].a, grafo[i].b);
    }

    bfs(graph, inicio, final);
    for (int j = 0; j < contBfs; ++j) {
        printf("%d ", solucionBfs[j]);
    }
    printf("\nSolucion con direcciones\n");
    direccionesSolucion(contBfs, solucionBfs);
    for (int j = 0; j < contador; j++) {
        printf("(%d,%d) ", sol[j].a, sol[j].b);
    }

    for (int k = 0; k < contador; ++k) {
        int dir=sol[k].b;
        for (int i = 0; i <2 ; ++i) {
            (TEST(dir,i))? printf("1 "):printf("0 ");
        }
    }
    printf("\n");


    printf("\n DFS  \n");
    for (int j = 0; j < numNodos; ++j) {
        graph->visited[j] = 0;
    }
    dfs(graph, inicio, final);
    solucionDfs[contDfs + 1] = final;

    for (int j = 0; j <= contDfs; j++) {
        printf("%d ", solucionDfs[j]);
    }
    printf("\n Solucion con direcciones\n");

    direccionesSolucion(contDfs, solucionDfs);

    for (int j = 0; j < contador; j++) {
        printf("(%d,%d) ", sol[j].a, sol[j].b);
    }

    printf("\n");

    //par.a=0;
    //par.b=0;
    //sol[8]=par;
    int dir=0;
    for (int k = 0; k < contador; ++k) {
        printf(" d: %d ", sol[k].b);//10->01
        dir = sol[k].b;
        printf(" direccion: %d \n", dir);//10->01
        for (int i = 0; i < 2 ; ++i) {
            if (TEST(dir,i)) { //00       /10
                printf("1");
            } else { printf("0"); }
        }
    }

    printf("\n");


    return 0;
}