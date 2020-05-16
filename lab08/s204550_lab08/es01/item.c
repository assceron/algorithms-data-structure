#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include <string.h>
typedef struct item
{
    char codice[11];
    char nome[31];
    char cognome[31];
    char data[11];
}item;

ITEM salvaItemdafile(char str1[11], char str2[31], char str3[31], char str4[11])
{
    ITEM tmp=malloc(sizeof(item));
    strcpy(tmp->codice,str1);
    strcpy(tmp->nome,str2);
    strcpy(tmp->cognome,str3);
    strcpy(tmp->data,str4);
    return tmp;

};
void quicksort(ITEM vet[],int l, int r)
{
    int q;
    if(r<=l)
        return;
    q=partition(vet,l,r);
    quicksort(vet,l,q-1);
    quicksort(vet,q+1,r);
    return;
};
void swap(ITEM vet[],int n1, int n2 )
{
    ITEM tmp;
    tmp=vet[n1];
    vet[n1]=vet[n2];
    vet[n2]=tmp;
    return;
};
int partition(ITEM vet[], int l, int r)
{
    int i=l-1, j=r;
    ITEM x=vet[r];

    for( ; ; )
    {

        while(strcmp((vet[++i]->codice),(x->codice))<0);
        while(strcmp((vet[--j]->codice),(x->codice))>0);
        if(j==l)
            break;
        if(i>=j)
            break;
        swap(vet,i,j);
    }
    swap(vet,i,r);
    return i;
};
void stampaitem(ITEM tmp)
{

    printf("%s %s %s %s\n",tmp->codice,tmp->nome, tmp->cognome, tmp->data);
    return;
};
ITEM trovachiave(ITEM vet[],int dim, char key[])
{
    ITEM tmp=malloc(sizeof(item));
    strcpy(tmp->codice,"VUOTO");
    strcpy(tmp->nome,"VUOTO");
    strcpy(tmp->cognome,"VUOTO");
    strcpy(tmp->data,"VUOTO");
    int a=0,c;
    while(a<=dim)
    {
        c=a+(dim-a)/2;
        if(strcmp(vet[c]->codice,key)==0)
            return vet[c];
        if(strcmp(vet[c]->codice,key)<0)
            a=c+1;
        else dim=c-1;
    }
    return tmp;
};

