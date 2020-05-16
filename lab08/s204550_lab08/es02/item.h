#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct item *ITEM;
ITEM itemnullo();
ITEM new_item();
int verificakey(ITEM item,char key[]);
ITEM sostkey(ITEM item, char key[]);
void stampaitem(ITEM item);
#endif // ITEM_H_INCLUDED
