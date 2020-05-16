#include <stdio.h>
#include <stdlib.h>
#define N 20
int main(int argc, char *argv[])
{
    FILE *fi,*fo;
    int sum, nr, nc, i, j, k, t, n;
    float m[N][N];
    if(argc!=3){
        printf("Errore linea di comando.");
        exit(1);
    }

    fi=fopen(argv[1],"r");
    if(fi==NULL){
        printf("Errore apertura file1.");
        exit(2);
    }
        fscanf(fi,"%d %d", &nr, &nc);
        for(i=0;i<nr;i++){
            for(j=0;j<nc;j++){
                fscanf(fi,"%f",&m[i][j]);
        }}
    fclose(fi);
    /* nr(numero di righe); nc(numero di colonne);*/

        fo=fopen(argv[2],"w");
     if(fo==NULL){
        printf("Errore apertura file2.");
        exit(3);
    }
        for(i=0;i<nr;i++){
            for(j=0;j<nc;j++){
                    n=0;
                    sum=0;
               for(k=i-1;k<=i+1;k++){
                for(t=j-1;t<=j+1;t++){
                 if(k>=0 && k<nr && t>=0 && t<nc){
                        sum=sum + m[k][t];
                        n++;/* n(numero di cifre da cui è circondata la cifra presa in considerazione)*/
                }}}
                if(j==nc-1)/*m[i][j] si trova nell'ultima colonna ?? */
            fprintf(fo,"%.1f\n",(float)((sum-m[i][j])/(n-1)));
                else
            fprintf(fo,"%.1f ",(float)((sum-m[i][j])/(n-1)));
      }}
    if(fclose(fo)!=0)
    {
     printf("Errore chiusura file.");
     exit(4);
    }


    return 0;
}
