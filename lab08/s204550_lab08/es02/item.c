#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
typedef struct item
{
    char codice[11];
    char nome[31];
    char cognome[31];
    char data[11];
}item;
ITEM itemnullo()
{
    ITEM tmp=malloc(sizeof(ITEM));
    tmp=NULL;
    return tmp;
};
ITEM new_item()
{
    ITEM tmp=malloc(sizeof(item));
    printf("\nInserirci elemento:");
    scanf("%s %s %s %s",tmp->codice,tmp->nome,tmp->cognome, tmp->data);
    return tmp;
};
int verificakey(ITEM item,char key[])
{
    if(strcmp(item->codice,key)==0)
        return 1;
    else
    return 0;
};
ITEM sostkey(ITEM item, char key[])
{
    strcpy(item->codice,key);
    return item;
};
void stampaitem(ITEM item)
{
    printf("\n%s %s %s %s",item->codice, item->nome,item->cognome,item->data);
    return;
};
