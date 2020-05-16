#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "heap.h"
int main()
{
    int comando,maxN;
    PQ pq;
    Item item;
    printf("\nNumero massimo di clienti da gestire in coda?");
    scanf("%d", &maxN);
    pq=PQUEUEinit(maxN);

    printf("\nInserisci 1 per aggiungere un cliente:");
    printf("\nInserisci 2 se hai terminato con un cliente:");
    printf("\nInserisci 3 per leggere coda da file:");
    scanf("%d", &comando);
    while(comando!=0)
    {
        switch(comando)
        {
        case 1:
            item=leggi_tastiera();
            PQUEUEinsert(pq,item);
            break;
        case 2:
            PQUEUEextractMax(pq);
            break;
        case 3:
            PQUEUE_file(pq);
            break;
        }
    printf("\nPremere 0 per chiudere!");
    printf("\nInserisci 1 per aggiungere un cliente:");
    printf("\nInserisci 2 se hai terminato con un cliente:");
    printf("\nInserisci 3 per leggere coda da file:");
    scanf("%d", &comando);
    }
    return 0;
}
