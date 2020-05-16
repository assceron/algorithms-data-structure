#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct item *Item;
Item acquisizione();
/*void salvaItem(Item v[],Item dato,int indice);*/
void stampaItem(Item dato);
void salvasufile(FILE *fo,Item dato);
int dimfile(char nome[]);
Item caricadafile();
#endif // ITEM_H_INCLUDED
