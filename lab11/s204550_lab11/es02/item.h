#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct item *Item;
typedef struct ka *kate;
Item NULLITEM();
int hash(Item item, int M);
int eq(Item item1, char str[]);
Item salva_item(char *s);
int salva_cat(Item item, kate *categ, int n_cat,int KB);
FILE* stampa_cliente(FILE *fp,Item item);
kate* ini_cat(kate *categ,int cont1);
FILE* stampa_kb_cat(FILE *fp, kate categ);
FILE* stampa_cat(FILE *fp, kate categ);
FILE* stampa_clienti(FILE *fp,kate categ);

#endif // ITEM_H_INCLUDED
