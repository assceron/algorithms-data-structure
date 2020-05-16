#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

typedef struct item *Item;

FILE *creavet(FILE * f, int v, Item *it);
Item NULLitem();
char *key(Item i);
int full(Item i);
void stampaItem(Item it);
int confronto(Item i1, Item i2);
#endif // ITEM_H_INCLUDED
