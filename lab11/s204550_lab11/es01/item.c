#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include <string.h>
struct item {int x; char str[25+1];};

Item NULLITEM()
{
    Item t;
    t=malloc(sizeof *t);
    t->x=-1;
    strcpy(t->str,"\0");
    return t;
}
int contr_key(Item item1, Item item2)
{
    if(item1->x < item2->x)
        return 1;
    if(item1->x > item2->x)
        return 2;
    else
        return 0;
}
Item salva_item(char *s)
{
    Item t;
    t=malloc(sizeof *t);
    sscanf(s,"%d%s",&t->x,t->str);
    return t;
}
Item salva_it()
{
    Item t=malloc(sizeof *t);
    printf("\nIntroduci elemento: ");
    scanf("%d %s",&t->x,t->str );
    return t;
}
void stampa_item(Item t)
{
    printf("\n%d %s",t->x,t->str);
    return;
}
Item salva_key()
{
   Item t;
   t=malloc(sizeof *t);
    printf("\nIntroduci chiave: ");
    scanf("%d",&t->x);
    strcpy(t->str,"\0");
    return t;
}
FILE* salva_it_sufile(FILE *fp,Item t)
{
    fprintf(fp,"\n%d %s",t->x, t->str);
    return fp;
}
