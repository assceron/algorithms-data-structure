#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "grafo.h"
#include "st.h"

int main(int argc, char *argv[])
{
    FILE *fp;
    int v,i,j,wt,*vett, comando,n1,n2;
    char str1[11], str2[11];
    Item *it;
    ST st;
    Graph g;
    Edge e;

    fp=fopen(argv[1],"r");
    fscanf(fp,"%d",&v);
    it=malloc(v*sizeof(Item));
    fp=creavet(fp,v,it);

    st=STinit(v);
    for(i=0;i<v;i++){
        STinsert(st,it[i]);}

    g=GRAPHinit(v);
    while(fscanf(fp,"%s %s %d",str1,str2,&wt)!=EOF){
        n1=STsearch(st,str1);
        n2=STsearch(st,str2);
        e=EDGE(n1,n2,wt);
        GRAPHinsertE(g,e);
    }

    fclose(fp);
    vett=malloc(v*sizeof(int));
    for(i=0;i<v;i++)
        vett[i]=0;
    calcolaGrado(g,vett);
    printf("Inserire 0 per calcolare e visualizzare il grado di ogni nodo\n");
    printf("Inserire 1 per stampare il numero totale di vertici ed elencarli esplicitamente per nome della città\n");
    printf("Inserire 2 per stampare il numero di archi incidenti su un nodo e l'elenco di vertici ad esso connessi\n");
    printf("Inserire 3 per stampare la matrice di adiacenza\n");
    printf("Inserire 4 per i flussi\n");
    scanf("%d",&comando);

    switch(comando){

    case 0: stampa_gradi(st,vett);
        break;

    case 1: stampaVertici(g);
            for(j=0;j<v;j++){
                stampaItem(it[j]);
            }
        break;

    case 2: printf("Inserire nodo");
            scanf("%s",str1);
            i=STsearch(st,str1);
            printf("Numero archi incidenti=%d", vett[i]);
            elencoVertici(g,i,st);
        break;

    case 3: matrice(g);
        break;

    case 4:flussi(g,st);

        break;
    }
    return 0;
}
