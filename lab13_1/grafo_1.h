#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "st.h"

typedef struct { int v; int w; } Edge;
Edge EDGE(int, int);

typedef struct graph *Graph;

Graph GRAPHinit(int);
void  GRAPHinsertE(Graph, Edge);
void  GRAPHdestroy(Graph);
void   GRAPHpathmin(Graph G, int v, int w,ST st);
void GRAPHpathmax(Graph G, int v, int w,ST st);
int GRAPHpath(Graph G, int v, int w);
int GRAPHscc(Graph G,ST st);
void GRAPHfort_conn(Graph G,ST st);
#endif // GRAFO_H_INCLUDED
