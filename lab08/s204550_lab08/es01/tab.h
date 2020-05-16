#ifndef TAB_H_INCLUDED
#define TAB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct tab *TAB;
TAB creatab(int dim);
TAB salvatab(char nome[]);
void quick(TAB t);
void ricerca(TAB t);
void distr(TAB t);
#endif // TAB_H_INCLUDED
