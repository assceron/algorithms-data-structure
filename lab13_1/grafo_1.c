#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"
#include "st.h"
#define maxV 100

struct graph {int V; int E; int **adj; int *visited; int *scc;};
static int time0, time1, post[maxV], postR[maxV];

Edge EDGE(int v, int w)
{
    Edge e;
    e.v = v;
    e.w = w;
    return e;
}
int **MATRIXint(int r, int c, int val)
{
    int i, j;
    int **t = malloc(r * sizeof(int *));
    for (i=0; i < r; i++)
        t[i] = malloc(c * sizeof(int));
    for (i=0; i < r; i++)
        for (j=0; j < c; j++)
            t[i][j] = val;
    return t;
}

Graph GRAPHinit(int V)
{
    Graph G = malloc(sizeof *G);
    G->V = V;
    G->E = 0;
    G->adj = MATRIXint(V, V, 0);
    G->scc=malloc(G->V*sizeof(int));
    G->visited = malloc(G->V * sizeof(int));
    return G;
}

void  GRAPHinsertE(Graph G, Edge e)
{
    int v = e.v, w = e.w;
    if (G->adj[v][w] == 0)
        G->E++;
    G->adj[v][w] = 1;
}


int pathRnum(Graph G, int v, int w, int cont)
{
    int t;
    if (v == w)
        return ++cont;

    for ( t = 0 ; t < G->V ; t++)
        if (G->adj[v][t] == 1)
            if (G->visited[t] == 0)
              {
                  G->visited[t] = 1;
                  cont=pathRnum(G, t, w,cont);
                  G->visited[t] = 0;
              }

     return cont;
}
int GRAPHpath(Graph G, int v, int w)
{
    int t,cont=0;
    for ( t = 0 ; t < G->V ; t++)
        G->visited[t] = 0;
    cont = pathRnum(G, v, w,cont);

    return cont;
}
Edge* pathRmin(Graph G, int v, int w,Edge *edge, int *b_lung, Edge *b_edge,int i)
{
    int t,j,l=0;
    if (v == w)
    {
       for(j=0;j<G->V;j++)
        if(G->visited[j]==1)
            l++;
       if(l<*b_lung)
       {
           *b_lung=l;
            for(j=0;j<G->V;j++)
            {
                b_edge[j].v=edge[j].v;
                b_edge[j].w=edge[j].w;
            }
       }
       return b_edge;
    }

    for ( t = 0 ; t < G->V ; t++)
        if (G->adj[v][t] == 1)
            if (G->visited[t] == 0)
              {
                  G->visited[t] = 1;
                  edge[i].v=v;
                  edge[i].w=t;
                      i++;
                  b_edge=pathRmin(G, t, w,edge,b_lung,b_edge,i);
                  G->visited[t] = 0;
                  i--;
                  edge[i].v=-1;
                  edge[i].w=-1;
              }

     return b_edge;
}
void GRAPHpathmin(Graph G, int v, int w,ST st)
{
    int t,j,b_lung,x;
    for ( t = 0 ; t < G->V ; t++)
        G->visited[t] = 0;
        G->visited[v]=1;
    Edge *edge=malloc(G->V*sizeof(Edge));
    Edge *b_edge=malloc(G->V*sizeof(Edge));
    for(j=0;j<G->V;j++)
    {
        b_edge[j].v=-1;
        b_edge[j].w=-1;
        edge[j].v=-1;
        edge[j].w=-1;
    }
    b_lung=1000;
    b_edge = pathRmin(G, v, w,edge,&b_lung,b_edge,0);
    printf("Lunghezza minima: %d\n", b_lung);
    x=b_edge[0].v;
    printf("%s - ",STsearch_str(st,x));
        for(j=0;j<G->V;j++)
            {
                if(b_edge[j].w!=-1)
                {
                    x=b_edge[j].w;
                     printf("%s - ",STsearch_str(st,x));
                }
            }
    printf("\n");
    return;
}
Edge* pathRmax(Graph G, int v, int w,Edge *edge, int *b_lung, Edge *b_edge,int i)
{
    int t,j,l=0;
    if (v == w)
    {
       for(j=0;j<G->V;j++)
        if(G->visited[j]==1)
            l++;
       if(l>*b_lung)
       {
           *b_lung=l;
            for(j=0;j<G->V;j++)
            {
                b_edge[j].v=edge[j].v;
                b_edge[j].w=edge[j].w;
            }
       }
       return b_edge;
    }

    for ( t = 0 ; t < G->V ; t++)
        if (G->adj[v][t] == 1)
            if (G->visited[t] == 0)
              {
                  G->visited[t] = 1;
                  edge[i].v=v;
                  edge[i].w=t;
                      i++;
                  b_edge=pathRmax(G, t, w,edge,b_lung,b_edge,i);
                  G->visited[t] = 0;
                  i--;
                  edge[i].v=-1;
                  edge[i].w=-1;
              }

     return b_edge;
}
void GRAPHpathmax(Graph G, int v, int w,ST st)
{
    int t,j,b_lung,x;
    for ( t = 0 ; t < G->V ; t++)
        G->visited[t] = 0;
        G->visited[v]=1;
    Edge *edge=malloc(G->V*sizeof(Edge));
    Edge *b_edge=malloc(G->V*sizeof(Edge));
    for(j=0;j<G->V;j++)
    {
        b_edge[j].v=-1;
        b_edge[j].w=-1;
        edge[j].v=-1;
        edge[j].w=-1;
    }
    b_lung=0;
    b_edge = pathRmax(G, v, w,edge,&b_lung,b_edge,0);
    printf("\nLunghezza massima: %d\n", b_lung);
    x=b_edge[0].v;
    printf("%s - ",STsearch_str(st,x));
        for(j=0;j<G->V;j++)
            {
                if(b_edge[j].w!=-1)
                {
                    x=b_edge[j].w;
                     printf("%s - ",STsearch_str(st,x));
                }
            }
    printf("\n");
    return;
}
void SCCdfsr(Graph G, int w){
    int t;
    G->scc[w]=time1;
    for(t=0;t<G->V;t++)
        if(G->adj[w][t]==1)
            if(G->scc[t]==-1)
                SCCdfsr(G,t);
    post[time0++]=w;
}
Graph GRAPHreverse(Graph G){
    int v,t;
    Graph R=GRAPHinit(G->V);
    for(v=0;v<G->V;v++)
        for(t=0;t<G->V;t++)
            if((G->adj[v][t])==1)
                GRAPHinsertE(R,EDGE(t,v));
    return R;
}


int GRAPHscc(Graph G,ST st){
    int v;
    Graph R;
    R=GRAPHreverse(G);
    R->scc=malloc( G->V*sizeof(int));
    time0=0;
    time1=0;
    for(v=0;v<G->V;v++)
        R->scc[v]=-1;
    for(v=0;v<G->V;v++)
        if(R->scc[v]==-1)
            SCCdfsr(R,v);
    time0=0; time1=0;
    for(v=0;v<G->V;v++)
        G->scc[v]=-1;
    for(v=0;v<G->V;v++)
        postR[v]=post[v];
    for(v=G->V-1;v>=0;v--)
    if(G->scc[postR[v]]==-1){
        SCCdfsr(G,postR[v]);
        time1++;
    }
    printf("Componenti fortemente connesse\n");
    for(v=0;v<G->V;v++)
        printf(" %s in scc %d \n",STsearch_str(st,v),G->scc[v]);
    return time1;
    }
void GRAPHfort_conn(Graph G,ST st)
{
    int i,j,k=0,x,y,found;
    Edge edge[10];
    for(i=0;i<G->V;i++)
    {
        for(j=0;j<G->V;j++)
        {
            if(i!=j)
            {
                found=GRAPHpath(G,i,j);
                if(found==0)
                {
                        edge[k].v=i;
                        edge[k].w=j;
                        k++;
                        G->adj[i][j]=1;
                }
            }
        }
    }
    for(i=0;i<k;i++)
    {
        x=edge[i].v;
        y=edge[i].w;
        printf("\n%s %s\n",STsearch_str(st,x), STsearch_str(st,y));
    }
    return;
}
