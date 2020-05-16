#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "item.h"

typedef struct pqueue *PQ;

PQ      PQUEUEinit(int);
void    PQUEUEinsert(PQ, Item);
void    PQUEUEextractMax(PQ);
void    PQUEUE_file(PQ pq);

#endif // HEAP_H_INCLUDED
