#include <stdio.h>
#include <stdlib.h>
#include "item.h"
struct item
{
    char codice[5+1];
    int valore;
};
Item leggi_tastiera()
{
    Item it=malloc(sizeof(struct item));
    printf("\nInserisci codice e priorità:");
    scanf("%s %d",it->codice, &it->valore);
    return it;
}
void stampa_item(Item item)
{
    printf("\n%s",item->codice);
    return;
}
key Key(Item item)
{
    return item->valore;
}
Item carica_item(char *str)
{
    Item item=malloc(sizeof(struct item));
    sscanf(str,"%s %d", item->codice, &item->valore);
    return item;
}
