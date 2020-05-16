#ifndef ST_H_INCLUDED
#define ST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
typedef struct symboltable *ST;
typedef struct ac *accessi;
ST crea(int maxN);
Item cerca(ST st, accessi traccia);
int hash2(char *v,int M);
FILE* elenca(ST st, accessi *traccia, int cont2,FILE *fp);
void inserisci(ST st,Item item);
accessi* salva_acc(FILE *fp, accessi *traccia,int cont2);
int estrai_kb(accessi traccia);
#endif // ST_H_INCLUDED
