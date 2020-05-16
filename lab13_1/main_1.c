#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "st.h"
int main(int argc, char *argv[])
{
    FILE *f_in;
    int v,x,y,cont;
    char str1[10+1], str2[10+1];
    Graph grafo;
    Edge arco;
    ST st;
    f_in=fopen(argv[1],"r");
    fscanf(f_in, "%d", &v);
    grafo=GRAPHinit(v);
    st=STinit(v);
    while(fscanf(f_in,"%s %s", str1, str2)!=EOF)
    {
        if(STsearch(st,str1)==-1)
           arco.v=STinsert(st,str1);
        else
             arco.v=STsearch(st,str1);
        if(STsearch(st,str2)==-1)
           arco.w=STinsert(st,str2);
        else
             arco.w=STsearch(st,str2);
        GRAPHinsertE(grafo,arco);
    }
    fclose(f_in);
    printf("\nInserisici i nodi per cercarne il cammino: ");
    scanf("%s %s", str1, str2);
    x=STsearch(st,str1);
    y=STsearch(st,str2);
    GRAPHpathmin(grafo,x,y,st);
    GRAPHpathmax(grafo,x,y,st);
    cont=GRAPHpath(grafo,x,y);
    if (cont == 0)
        printf("\n Non ci sono cammini semplici!\n");
        else
            printf("\nCi sono %d cammini semplici\n", cont);
    GRAPHscc(grafo,st);
    GRAPHfort_conn(grafo,st);
    return 0;
}
