#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "st.h"

int main(int argc, char *argv[])
{
    FILE *f_in1, *f_in2, *f_out1,*f_out2,*f_out3;
    int cont1=0,i,cont2=0,n_cat=0,kb;
    char str[105];
    ST st;
    Item item;
    accessi *traccia;
    kate *categ;

    f_in1=fopen(argv[1],"r");
    while(fgets(str,105,f_in1)!=NULL)
        cont1++;
    rewind(f_in1);
    st=crea(cont1);
    for(i=0;i<cont1;i++)
    {
        fgets(str,105,f_in1);
        item=salva_item(str);
        inserisci(st,item);
    }
    fclose(f_in1);

    f_in2=fopen(argv[2],"r");
    while(fgets(str,105,f_in2)!=NULL)
        cont2++;
    rewind(f_in2);
    traccia=malloc(sizeof *traccia);
    traccia=salva_acc(f_in2,traccia,cont2);

    categ=malloc(sizeof *categ);
    categ=ini_cat(categ,cont1);

    for(i=0;i<cont2;i++)
    {
        item=cerca(st,traccia[i]);
        kb=estrai_kb(traccia[i]);
        n_cat=salva_cat(item,categ,n_cat,kb);
    }

    f_out1=fopen(argv[3],"w");
    for(i=0;i<n_cat;i++)
    {
        f_out1=stampa_kb_cat(f_out1,categ[i]);
    }
    fclose(f_out1);

    f_out2=fopen(argv[4],"w");
    for(i=0;i<n_cat;i++)
    {
        f_out2=stampa_cat(f_out2,categ[i]);
        f_out2=stampa_clienti(f_out2,categ[i]);

    }
    fclose(f_out2);

    f_out3=fopen(argv[5],"w");
    f_out3=elenca(st,traccia,cont2,f_out3);
    fclose(f_out3);
    return 0;
}
