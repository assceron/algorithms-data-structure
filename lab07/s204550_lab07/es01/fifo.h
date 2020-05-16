#ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED
#include "item.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct coda *CODA;
CODA creaCODA(int maxN);
void stampaNum(CODA p);
void putCODA(CODA p,Item dato);
int pienaCODA(CODA p);
Item getCODA(CODA p);
int vuotaCODA(CODA p);
void stampaCODA(CODA p);
void caricaCODA(CODA p);
/*void salvaCODA(CODA p);*/
#endif // FIFO_H_INCLUDED
