#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"
#include "st.h"


typedef struct node *link;
struct node { int v; int wt; link next; } ;
struct graph { int V; int E; link *adj; } ;

link NEW(int v, int wt, link next)
  { link x = malloc(sizeof *x);
    x->v = v; x->wt = wt; x->next = next;
    return x;
  }

Edge EDGE(int v, int w, int wt)
{
    Edge e;
    e.v = v;
    e.w = w;
    e.wt = wt;
    return e;
}

Graph GRAPHinit(int V)
{
    int v;
    Graph G = malloc(sizeof *G);
    G->V = V;
    G->E = 0;
    G->adj = malloc( V  * sizeof(link));
    for (v = 0; v < V; v++)
        G->adj[v] = NULL;
    return G;
}

void  GRAPHinsertE(Graph G, Edge e)
{
    int v = e.v, w = e.w, wt = e.wt;
    if (v == w) return;
    G->adj[v] = NEW(w, wt, G->adj[v]);
    G->adj[w] = NEW(v, wt, G->adj[w]);
    G->E++;
}

int   GRAPHedges(Edge a[], Graph G)
{
    int v, E = 0;
    link t;
    for (v=0; v < G->V; v++)
        for (t=G->adj[v]; t != NULL; t = t->next)
            if (v < t->v)
                a[E++] = EDGE(v, t->v, t->wt);
    return E;
}


void calcolaGrado(Graph G, int *vett){
    int v;
    link t;
    for (v=0; v < G->V; v++){
        for (t=G->adj[v]; t != NULL; t = t->next)
           vett[v]++;
    }
}

void stampaVertici(Graph G){
    printf("Numero di vertici=%d\n",G->V);

}

void elencoVertici(Graph G, int i, ST st){
    link t;
    for (t=G->adj[i]; t != NULL; t = t->next){
        search2(st,t->v);
    }
}

void matrice(Graph G){
    int **mat,i,j;
    Edge *ed;
    mat=malloc((G->V)*sizeof(int*));
    for(i=0;i<G->V;i++){
        mat[i]=malloc((G->V)*sizeof(int));
    }
    for(i=0;i<G->V;i++){
        for(j=0;j<G->V;j++){
            mat[i][j]=0;}}
    ed=malloc((G->E)*sizeof(Edge));
    i=GRAPHedges(ed,G);
    for(i=0;i<G->E;i++){
        mat[ed[i].v][ed[i].w]=ed[i].wt;
        mat[ed[i].w][ed[i].v]=ed[i].wt;
    }
    for(i=0;i<G->V;i++){
        for(j=0;j<G->V;j++){
            printf("%d  ",mat[i][j]);
        }
        printf("\n");
    }
}

void GRAPHshow(Graph g){
    int v;
    link t;
    printf("%d vertici %d archi\n", g->V,g->E);
    for(v=0;v<g->V;v++){
        printf("%2d:",v);
        for(t=g->adj[v]; t != NULL; t = t->next)
            printf("%2d",t->v);
        printf("\n");
    }
}

void flussi(Graph g, ST st){
    int v,w,i,intra=0,inter=0;
    Item i1, i2;
    Edge *ed=malloc((g->E)*sizeof(Edge));
    i=GRAPHedges(ed,g);
    for(i=0;i<g->E;i++){
        v=ed[i].v;
        w=ed[i].w;
        i1=regione(st,v);
        i2=regione(st,w);
        if(confronto(i1,i2)==0){
            intra+=ed[i].wt;
        }else{
            inter+=ed[i].wt;
        }
    }
    printf("Flusso intraregionale:%d\n",intra);
    printf("Flusso interregionale:%d\n",inter);
}
