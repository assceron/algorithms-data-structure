#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct item *Item;
Item copia(Item item1, Item item2);
Item NULLITEM();
int contr_key(Item item1, Item item2);
Item salva_item(char *s);
Item salva_it();
void stampa_item(Item t);
Item salva_key();
FILE* salva_it_sufile(FILE *fp,Item t);
#endif // ITEM_H_INCLUDED
