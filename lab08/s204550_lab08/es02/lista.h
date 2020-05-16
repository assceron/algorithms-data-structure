#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
typedef struct nodo *link;
typedef struct lista *LISTA;

link NEW(ITEM item, link next);
LISTA crealista();
void ins_lista(LISTA l);
void ricercachiave(LISTA l);
void cerca_sost(link h, char key[],char sost[],link t);
void canc(LISTA l);
link canc_k(link x, char key[]);
void stampa(LISTA l);
void distr_lista(LISTA l);
#endif // LISTA_H_INCLUDED
