#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Nó da lista de adjacência
typedef struct No {
    int vertice;
    struct No* prox;
} No;

// Estrutura do grafo
typedef struct {
    int numVertices;
    No* listaAdj[MAX];
} Grafo;

// Criar grafo
Grafo* criarGrafo(int vertices) {
    Grafo* g = (Grafo*) malloc(sizeof(Grafo));
    if (g == NULL) {
        printf("Erro de memoria\n");
        exit(1);
    }
    g->numVertices = vertices;

    // Inicializa listas como NULL
    for (int i = 0; i < vertices; i++) {
        g->listaAdj[i] = NULL;
    }
    return g;
}

// Criar novo nó
No* criarNo(int v) {
    No* novo = (No*) malloc(sizeof(No));
    novo->vertice = v;
    novo->prox = NULL;
    return novo;
}

// Adicionar aresta (orientado: só um sentido)
void adicionarAresta(Grafo* g, int v1, int v2) {
    if (v1 >= g->numVertices || v2 >= g->numVertices) {
        printf("Vertice invalido!\n");
        return;
    }
    No* novo = criarNo(v2);
    novo->prox = g->listaAdj[v1];
    g->listaAdj[v1] = novo;
}

// Imprimir grafo
void imprimirGrafo(Grafo* g) {
    printf("\nLista de Adjacencia:\n");
    for (int i = 0; i < g->numVertices; i++) {
        No* temp = g->listaAdj[i];
        printf("%d -> ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->vertice);
            temp = temp->prox;
        }
        printf("NULL\n");
    }
}

int main() {
    int vertices, arestas;
    int v1, v2;
    printf("Informar o numero de vertices: ");
    scanf("%d", &vertices);
    Grafo* g = criarGrafo(vertices);
    printf("Informar o numero de arestas: ");
    scanf("%d", &arestas);
    for (int i = 0; i < arestas; i++) {
        printf("Aresta %d (origem destino): ", i + 1);
        scanf("%d %d", &v1, &v2);
        adicionarAresta(g, v1, v2);
    }
    imprimirGrafo(g);
    // Nota: Para um código completo, seria ideal liberar a memória de cada nó aqui.
    free(g);
    return 0;
}