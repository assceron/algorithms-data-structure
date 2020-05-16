#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "heap.h"
#define LEFT(i)   	((i*2) + 1)
#define RIGHT(i)	((i*2) + 2)
#define PARENT(i)	((i-1) / 2)

struct pqueue { Item *array; int heapsize; int maxN;};

PQ PQUEUEinit(int maxN)
{
    PQ pq;
    pq = malloc(sizeof(*pq));
    pq->array = (Item *)malloc(maxN*sizeof(Item));
    pq->heapsize = 0;
    pq->maxN=maxN;
    return pq;
}

void PQUEUEinsert (PQ pq, Item item)
{
    int i;
    if(pq->heapsize==pq->maxN)
    {
        stampa_item(item);
        printf("  non inserito!\nCoda piena!Attendere...");
        return;
    }
    i  = pq->heapsize++;
	while (i>=1 && less(pq->array[PARENT(i)], item))
    {
        pq->array[i] = pq->array[PARENT(i)];
		i = (i-1)/2;
    }
	pq->array[i] = item;
	return;
}

void Swap(PQ pq, int n1, int n2)
{
	Item temp;

	temp  = pq->array[n1];
	pq->array[n1] = pq->array[n2];
	pq->array[n2] = temp;
	return;
}

void Heapify(PQ pq, int i)
{
    int l, r, largest;
    l = LEFT(i);
    r = RIGHT(i);
    if (l < pq->heapsize && greater(pq->array[l], pq->array[i]))
        largest = l;
    else
        largest = i;
    if (r < pq->heapsize && greater(pq->array[r], pq->array[largest]))
        largest = r;
    if (largest != i)
    {
		Swap(pq, i,largest);
		Heapify(pq, largest);
    }
    return;
}

void PQUEUEextractMax(PQ pq)
{
    if(pq->heapsize==0)
    {
        printf("\nCoda vuota!");
        return;

    }
    Item item;
    Swap (pq, 0,pq->heapsize-1);
    item = pq->array[pq->heapsize-1];
    stampa_item(item);
    printf(" cliente terminato.");
    pq->heapsize--;
    Heapify(pq, 0);
	return;
}
void PQUEUE_file(PQ pq)
{
    char nomefile[10],str[10];
    FILE *fp;
    Item item;
    printf("\nInserire nome file:");
    scanf("%s",nomefile);
    fp=fopen(nomefile,"r");
    while(fgets(str,10,fp)!=NULL)
    {
        item=carica_item(str);
        PQUEUEinsert(pq,item);
    }
    fclose(fp);
    return;

}
