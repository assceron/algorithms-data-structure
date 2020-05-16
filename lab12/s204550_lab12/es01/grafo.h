#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "st.h"
typedef struct { int v; int w; int wt;} Edge;
Edge EDGE(int, int, int);

typedef struct graph *Graph;

Graph GRAPHinit(int);
void  GRAPHinsertE(Graph, Edge);
int   GRAPHedges(Edge [], Graph G);
void calcolaGrado(Graph G, int *vett);
void stampaVertici(Graph G);
void elencoVertici(Graph G, int i, ST st);
void matrice(Graph G);
void GRAPHshow(Graph g);
void flussi(Graph g, ST st);
#endif // GRAFO_H_INCLUDED
