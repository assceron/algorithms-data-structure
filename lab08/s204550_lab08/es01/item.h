#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct item *ITEM;
ITEM salvaItemdafile(char *str1, char *str2, char*str3, char*str4);
void quicksort(ITEM vet[],int l, int r);
void swap(ITEM vet[],int n1, int n2 );
int partition(ITEM vet[], int l, int r);
void stampaitem(ITEM tmp);
ITEM trovachiave(ITEM vet[],int dim,char key[]);
#endif // ITEM_H_INCLUDED
