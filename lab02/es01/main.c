#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define M 20
int main(int argc, char *argv[])
{
    FILE *fp;
    int cont[M],posi[M][10];
    char parola[M];
    int i,j,k,f,l;
    int p=0,N=0,c;

    if(argc!=2){
        printf("Errore linea di comando.");
        exit(1);
    }
    fp=fopen(argv[1],"r");

    for(j=0;j<M;j++){
        cont[j]=0;
        for(f=0;f<10;f++)
            posi[j][f]=0;
    }

    while(fscanf(fp,"%s", parola)!= EOF){
            p++;
        l=strlen(parola);

        if(isalnum(parola[l-1])==0)
            l--;
        cont[l]=cont[l]+1;
        c=cont[l];
        posi[l][c-1]=p;
        if(l>N)
            N=l;
    }
      printf("Lunghezza - Conteggio - Posizioni\n");
      for(i=0;i<=N;i++){
            if(cont[i]!=0){
                printf("%d - ",i);
                printf("%d - ", cont[i]);
            for(k=0;k<cont[i];k++)
                printf("%d ", posi[i][k]);
                printf("\n");
        }}
        fclose(fp);
    return 0;
}
