#include <stdlib.h>
#include <stdio.h>
#include "item.h"
#include <string.h>


struct item{
    char citta[11];
    char regione[11];
};

FILE *creavet(FILE * f, int v, Item *it){
    int i;
    for(i=0;i<v;i++){
        it[i]=malloc(sizeof(struct item));
        fscanf(f,"%s %s",it[i]->citta, it[i]->regione);
    }
    return f;
}

Item NULLitem(){
    Item i;
    i=malloc(sizeof(struct item));
    strcpy(i->citta,"\0");
    strcpy(i->regione,"\0");
    return i;
}

char *key(Item i){
    return i->citta;
}

int full(Item i){
    if(strcmp(i->citta,"\0")==0)
        return 1;
    else
        return 0;
}

void stampaItem(Item it){
    printf("%s %s\n", it->citta, it->regione);
}

int confronto(Item i1, Item i2){
    return(strcmp(i1->regione, i2->regione));
}
