#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 80
int main()
{

    FILE *input,*dizi,*output;
    char str[MAX];
    char v[100][50];
    int i,j,l,k,m;
    char par[100][50];

   dizi=fopen("dizionario.txt","r");
    if(dizi==NULL){
        printf("Errore apertura file dizionario.txt.");
        exit(4);
    }

   i=0;
   while(fgets(str,55,dizi)!=NULL)
   {
       sscanf(str,"%s %s",v[i],par[i]);
       i++;
   }

   if(fclose(dizi)!=0){
    printf("Errore chiusura file dizi.");
    exit(1);
   }


     input=fopen("codificato.txt","r");
    if(input==NULL){
        printf("Errore apertura file codificato.txt.");
        exit(4);
    }
    output=fopen("decodificato.txt","w");
    if(output==NULL){
        printf("Errore apertura file decodificato.txt.");
        exit(4);
    }


    while(fgets(str,80,input)!=NULL)
    {
        l=strlen(str);/*l(lunghezza stringa del file 'input' )*/
        for(k=0;k<l;k++){
        if (str[k]=='$')
        {
            for(j=0;j<i;j++)
            {
                m=strlen(v[j]);/* m(lunghezza del numero del file 'dizi')*/
                if ((m==1)&&(str[k+1]==v[j][0]))
                {
                    fprintf(output,"%s",par[j]);
                    k++; /*salto la cifra successiva a'$'*/
                }
                else
                {
                    if((str[k+1]==v[j][0])&&(str[k+2]==v[j][1]))
                    {
                        fprintf(output,"%s",par[j]);
                        k+=2;/*salto le due cifre successive a '$' */
                    }
                }

            }
        }
        else
        {
            fprintf(output,"%c",str[k]);
        }

    }}

    if(fclose(input)!=0){
    printf("Errore chiusura file codificato.txt.");
    exit(2);
   }
   if(fclose(output)!=0){
    printf("Errore chiusura file decodificato.txt.");
    exit(3);
   }
    return 0;
}
