#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
	int **matrizAdj;
	int qtdVertices; //qtdNos ou qtdNodos
	int qtdArestas;
} Grafo;

Grafo *inicializarGrafo(int vertices) {
	int i, j;

	Grafo *g = (Grafo *)malloc(sizeof(Grafo));

	g->qtdVertices = vertices;
	g->qtdArestas = 0;

	g->matrizAdj = malloc(vertices * sizeof(int *));

	for (i = 0; i < g->qtdVertices; i++)
		g->matrizAdj[i] = malloc(vertices * sizeof(int));

	for (i = 0; i < g->qtdVertices; i++)
		for (j = 0; j < g->qtdVertices; j++)
			g->matrizAdj[i][j] = 0;

	return g;
}

void inserirGrafo(int origem, int destino, Grafo *g) {
	if (origem < 0 || origem >= g->qtdVertices || destino < 0 ||
		destino >= g->qtdVertices || g->matrizAdj[origem][destino] != 0) {
		printf("Aresta nao cadastrada\n");
	} else {
		g->matrizAdj[origem][destino] = 1;
		g->qtdArestas++;
	}
}

void inserirGrafoSimetrico(int origem, int destino, Grafo *g) {
	if (origem < 0 || origem >= g->qtdVertices || destino < 0 ||
		destino >= g->qtdVertices || g->matrizAdj[origem][destino] != 0 ||
		origem == destino) {
		printf("Aresta nao cadastrada\n");
	} else {
		g->matrizAdj[origem][destino] = 1;
		g->matrizAdj[destino][origem] = 1;
		g->qtdArestas+=2;
	}
}

void exibirGrafo(Grafo *g) {
	if (!g) {
		printf("Grafo nao existe\n");
	} else {
		int i,j;
		for (i = 0; i < g->qtdVertices;i++) {
			printf("%d: ", i);
			for (j = 0; j < g->qtdVertices; j++) {
				if (g->matrizAdj[i][j] != 0)
					printf("%d   ", j);
			}
			printf("\n");
		}
	}
}

int grauVertice(int vertice, Grafo *g) {
    if (!g) return 0;
    int i;
    int conta = 0;
    for (i = 0; i < g->qtdVertices; i++) {
        if (g->matrizAdj[vertice][i] != 0) conta++;
        if (g->matrizAdj[i][vertice] != 0) conta++;
    }
    return conta;
}

int ehSimetrico(Grafo *g) {
    if (!g) return -27;
    int i, j;

    for (i = 0; i < g->qtdVertices; i++) {
        for (j = i; j < g->qtdVertices; j++) {
            if (g->matrizAdj[i][j] != g->matrizAdj[j][i])
                return 0;
        }
    }
    return 1;
}

int temCaminhoAmplitude(Grafo *g, int origem, int destino) {

}

void percorreAmplitude(Grafo *g, int origem) {

}