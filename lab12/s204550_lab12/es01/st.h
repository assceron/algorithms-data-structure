#ifndef ST_H_INCLUDED
#define ST_H_INCLUDED
#include "item.h"

typedef struct symbletable *ST;

ST STinit(int maxN);
int hasha(char *v, int M);
void STinsert(ST st, Item item);
int STsearch(ST st, char *c);
void stampa_gradi(ST st,int* vett);
void search2(ST st, int i);
Item regione(ST st, int i);
#endif // ST_H_INCLUDED
