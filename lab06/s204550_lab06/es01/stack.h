#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "stude.h"
int cardinalitastack(stud *s);
stud* creastudstack();
stud* creastack();
stud* push(stud *t);
stud* pop(stud *t);
void stampastack(stud *t);
void distrstack(stud *t);


#endif // STACK_H_INCLUDED
