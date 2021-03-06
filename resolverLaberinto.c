//
// Created by yerguerrero on 12/7/20.
//

#include "resolverLaberinto.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include "laberinto.h"

bool terminar = false;

struct cola {
    int items[SIZE];
    int front;
    int rear;
};

struct cola *crearCola();

void encolar(struct cola *q, int value);

int desencolar(struct cola *q);

int estaVacio(struct cola *q);

struct node {
    int vertex;
    struct node *next;
};

struct node *crearNodo(int);

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
    struct cola *q = crearCola();
    graph->visited[startVertex] = 1;
    encolar(q, startVertex);
    while (!estaVacio(q)) {
        int currentVertex = desencolar(q);
        solucionBfs[contBfs] = currentVertex;
        struct node *temp = graph->adjLists[currentVertex];

        while (temp && graph->visited[endVertex] == 0) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                encolar(q, adjVertex);
            }
            temp = temp->next;
        }
        contBfs++;
    }
}

// Creating a node
struct node *crearNodo(int v) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Creating a graph
struct Graph *addGrafo(int vertices) {
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
void agergarVertice(struct Graph *graph, int src, int dest) {
    // Add edge from src to dest
    struct node *newNode = crearNodo(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = crearNodo(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Create a cola
struct cola *crearCola() {
    struct cola *q = malloc(sizeof(struct cola));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the cola is empty
int estaVacio(struct cola *q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

// Adding elements into cola
void encolar(struct cola *q, int value) {
    if (q->rear == SIZE - 1) {

    } else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Removing elements from cola
int desencolar(struct cola *q) {
    int item;
    if (estaVacio(q)) {
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

struct punto obtener_posicion(int);

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
                punto = obtener_posicion(nodo);
                par.a = nodo;//Origen
                par.b = j;//direccion
                sol[contador] = par;
                solucionXY[contador] = punto;
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

void generarBits() {
    for (int k = 0; k < contador; ++k) {
        dir = sol[k].b;
        for (int i = 1; i >= 0; --i) {
            if (TEST(dir, i)) { //00       /10
                if (i == 1) {
                    par.a = 1;
                } else if (i == 0) {
                    par.b = 1;
                }
            } else {
                if (i == 1) {
                    par.a = 0;
                } else if (i == 0) {
                    par.b = 0;
                }
            }
        }
        arregloBits[k] = par;
    }
}

void generarResultado() {
    int j = contador - 1;
    contReiniciar = 0;
    cant_pares = 0;
    resultado = 0;
    contPosicion = 0;
    contadorBits = 0;
    resultadosR[MAX];
    while (j >= 0) {
        if (contReiniciar <= 14 && contReiniciar < contador) {
            resultado += (arregloBits[j].b << contadorBits);
            contadorBits++;
            resultado += (arregloBits[j].a << contadorBits);
            contadorBits++;
            cant_pares = cant_pares + 2;
            if (contReiniciar == 14) {
                resultadosR[contPosicion] = resultado;
                contPosicion++;
                resultado = 0;
                cant_pares = 0;
            } else {
                resultadosR[contPosicion] = resultado;
            }
            j--;
            contReiniciar++;
        } else {
            contReiniciar = 0;
            resultado = 0;
            contadorBits = 0;
        }
    }
    int exponente = 0;
    if (cant_pares < 28) {
        exponente = 28 - cant_pares;
        int res = resultadosR[contPosicion] * (1 << exponente);
        resultadosR[contPosicion] = res;
    }
    printf("\n");
    printf("%d ", contador - 1);
    for (int l = contPosicion; l >= 0; --l) {
        printf("%d ", resultadosR[l]);
    }
    printf("\n");
}

void timer_callback();

void display_callback();

void reshape_callback(int, int);

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    initGrid(columnas, filas);
}

void display_callback() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    dibujar_laberinto();
    glutSwapBuffers();
    if(terminar){
        exit(0);
    }
}

void reshape_callback(int w, int h) {
    // Inicio
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, columnas, 0.0, filas, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

struct punto obtener_posicion(int numero) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (matrizOrig[i][j] == numero) {
                punto.x = j;
                punto.y = i;
                return punto;
            }
        }
    }
}

void timer_callback() {
    glutPostRedisplay();
    glutTimerFunc(1000 / casillas, timer_callback, 0);
}

double timeval_diff(struct timeval *a, struct timeval *b) {
    return
            (double) (a->tv_sec + (double) a->tv_usec / 1000000) -
            (double) (b->tv_sec + (double) b->tv_usec / 1000000);
}

void ventana(int args, char *argsv[]) {
    glutInit(&args, argsv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Laberinto");
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    glutTimerFunc(1000/casillas, timer_callback, 0);
    init();
    glutMainLoop();
}

int main(int args, char *argsv[]) {
    puntoAx = atoi(argsv[1]);
    puntoAy = atoi(argsv[2]);
    int puntoBx = atoi(argsv[3]);
    int puntoBy = atoi(argsv[4]);
    struct timeval t_ini, t_fin;
    double mlSecs;
    gettimeofday(&t_ini, NULL);
    casillas = atoi(argsv[5]);
    crearMatriz();
    matrizDirecciones();
    crearGrafo();
    nodosMatriz();
    inicio = matrizOrig[puntoAx][puntoAy];
    final = matrizOrig[puntoBx][puntoBy];

    struct Graph *graph = addGrafo(numNodos);
    for (int i = 0; i < numNodos; ++i) {
        agergarVertice(graph, grafo[i].a, grafo[i].b);
    }

    bfs(graph, inicio, final);
    direccionesSolucion(contBfs, solucionBfs);
    for (int j = 0; j < numNodos; ++j) {
        graph->visited[j] = 0;}
    generarBits();
    generarResultado();

    //dfs(graph, inicio, final);
    //solucionDfs[contDfs + 1] = final;
    //direccionesSolucion(contDfs, solucionDfs);
    //generarBits();
    //generarResultado();

    gettimeofday(&t_fin, NULL);
    mlSecs = timeval_diff(&t_fin, &t_ini);
    int segundos = mlSecs;
    mlSecs = mlSecs - segundos;
    int minutos = segundos / 60;
    segundos -= minutos * 60;
    printf("Tiempo: %d min, %d segundos %.16g ms\n", minutos, segundos, mlSecs);

    ventana(args,argsv);
    return 0;
}

// gcc resolverLaberinto.c laberinto.c -o progra -lglut -lGLU -lGL
// gcc resolverLaberinto.c laberinto.c -o progra -lglut -lGLU -lGL -pthread