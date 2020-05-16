#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "stude.h"

int cardinalita(stud *s);
stud* creastud();
stud* crealista();
stud* instesta(stud *t);
stud* inscoda( stud *t);
void ricercanome(stud *t,char str[]);
void ricercacogn(stud *t,char str[]);
void ricercamatr(stud *t,char str[]);
stud* cancnome(stud *t, char str[]);
stud* canccogn(stud *t, char str[]);
stud* cancmatr(stud *t, char str[]);
void stampa(stud *t);
void distr(stud *t);

#endif // LISTA_H_INCLUDED
