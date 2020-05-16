#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "tab.h"
int main(int argc, char *argv[])
{
    TAB tabella;
    char nome[10];
    if(argc!=2)
    {
        printf("Errore linea cmd.");
        exit(1);
    }

    strcpy(nome,argv[1]);
    tabella=salvatab(nome);
    ricerca(tabella);
    distr(tabella);
    return 0;
}
