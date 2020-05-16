#include <stdio.h>
#include <stdlib.h>
#include "tab.h"
#include "item.h"
typedef struct tab
{
    ITEM *vett;
    int N;
}tab;

TAB creatab(int dim)
{
    TAB t=malloc(sizeof(TAB));
    t->vett=malloc(dim*sizeof(ITEM));
    t->N=dim;
    return t;
};
TAB salvatab(char nome[])
{
    TAB t;
    int i,n;
    FILE *ff;
    ITEM temp;
    char str1[11], str2[31], str3[31], str4[11];
    ff=fopen(nome,"r");
    fscanf(ff,"%d",&n);
    t=creatab(n);
    for(i=0;i<n;i++)
    {
        fscanf(ff,"%s",str1);
        fscanf(ff,"%s",str2);
        fscanf(ff,"%s",str3);
        fscanf(ff,"%s",str4);
        temp=salvaItemdafile(str1,str2,str3,str4);
        t->vett[i]=temp;
    }

    quick(t);
    for(i=0;i<t->N;i++)
        stampaitem(t->vett[i]);


    return t;
};
void quick(TAB t)
{
    quicksort(t->vett,0,t->N-1);
    return;
};
void ricerca(TAB t)
{
    ITEM tmp;
    char chiave[31];
    printf("\nInserisci chiave da ricercare:");
    scanf("%s",chiave);
    tmp=trovachiave(t->vett,t->N-1,chiave);
    stampaitem(tmp);
    return;
};
void distr(TAB t)
{
    free(t);
    return;
};
