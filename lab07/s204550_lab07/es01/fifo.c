#include "item.h"
#include "fifo.h"
#include <stdio.h>
#include <stdlib.h>
struct coda
{
    Item *q;
    int N,head,tail,cont;
};

CODA creaCODA(int maxN)
{
  CODA p=malloc(sizeof *p);
  p->q=malloc(maxN* sizeof(Item));
  p->N=maxN;
  p->head=maxN-1;
  p->tail=0;
  p->cont=0;
  return p;
};
void stampaNum(CODA p)
{
  printf("\n%d",p->cont);
  return;
};
void putCODA(CODA p, Item dato)
{
    p->q[p->tail]=dato;
    p->tail=((p->tail)+1)%p->N;
    p->cont++;

    return;
};
int pienaCODA(CODA p)
{
    if(p->cont==p->N)
        return (p->N);
    else return -1;
};
int vuotaCODA(CODA p)
{
    if(p->cont==0)
        return (p->cont);
    else return -1;
};
Item getCODA(CODA p)
{

        p->head=(p->head +1)%p->N;
        p->cont--;
    return p->q[p->head];

};
void stampaCODA(CODA p)
{
   int i,d;
   /*for(i=((p->head +1)%(p->N));i!=(p->tail);(i+1)%(p->N))*/
    i=((p->head +1)%(p->N));
    d=i+p->cont;
   while(i<d)
    {   stampaItem(p->q[i]);
        i=i+1;
    }
   return;
};
void caricaCODA(CODA p)
{
    Item t;
    FILE *ff;
    char nomefile2[10], str[30];
    int dimf,i;
    printf("\nNome file da cui caricare dati:");
    scanf("%s",nomefile2);
    dimf=dimfile(nomefile2);
    printf("\n--->>%d\n",dimf);
    ff=fopen(nomefile2, "r");
    if((p->cont + dimf)<=p->N)
       {
            for(i=0;i<dimf;i++){
            fgets(str,31,ff);
            t=caricadafile(str);
            putCODA(p,t);}

       }
       else
        printf("\nContenuto del file troppo grande.");
    return;
};
void salvaCODA(CODA p)
{
    int i,d;
    FILE *fo;
    char nomefile[10];
    printf("\nNome file su cui salvare:");
    scanf("%s",nomefile);
    fo=fopen(nomefile,"w");
    /*for(i=(p->head +1)%p->N;i!=p->tail;(i++)%p->N)*/
        i=((p->head +1)%(p->N));
        d=i+p->cont;
   while(i<d)
    {
        salvasufile(fo,p->q[i]);
        i=i+1;
    }
    fclose(fo);
    return;
};
