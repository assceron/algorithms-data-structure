#ifndef STUDE_H_INCLUDED
#define STUDE_H_INCLUDED

#define max 36
#include <stdio.h>
#include <stdlib.h>
struct carriere{
int crediti;
float media;
};

typedef struct Studente{
char nome[max];
char cognome[max];
char matricola[max];
struct carriere  carriera;
struct Studente *next;
}stud;

#endif // STUDE_H_INCLUDED
