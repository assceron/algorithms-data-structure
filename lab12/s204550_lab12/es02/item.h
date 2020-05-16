#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define less(A, B) (Key(A) < Key(B))
#define greater(A, B) (Key(A) > Key(B))

typedef struct item *Item;
typedef int key;
Item leggi_tastiera();
void stampa_item(Item item);
key Key(Item item);
Item carica_item(char *str);
#endif // ITEM_H_INCLUDED
