#include <stdio.h>
#include <stdlib.h>
typedef struct vet{
int indice;
int valore;
}vett_;
int main(int argc, char *argv[])
{
    FILE *f_in;
    int **vett, nr, nc,i,j,*n,k,flag,r,c;
    vett_ **vett_p;

    if(argc!=2)
    {
        printf("Errore linea di comando.");
        exit(1);
    }
    f_in=fopen(argv[1], "r");
    if(f_in==NULL)
    {
        printf("Errore apertura file input.");
        exit(2);
    }

    fscanf(f_in,"%d %d", &nr,&nc);
    vett=malloc(nr*sizeof(int*));
    for(i=0;i<nr;i++)
    {
        vett[i]=malloc(nc*sizeof(int));
        for(j=0;j<nc;j++)
            fscanf(f_in,"%d",&vett[i][j]);
    }
    fclose(f_in);

 /*1 rappresentazione*/
    for(i=0;i<nr;i++)
    {
        for(j=0;j<nc;j++)
            printf("%d ", vett[i][j]);
        printf("\n");
    }
    flag=0;
     for(i=0;i<nr && flag==0;i++)
    {
        for(j=0;j<nc && flag==0;j++)
        {

            if(vett[i][j]!=vett[j][i])
                flag=1;
        }
    }
    if(flag==1)
        printf("Matrice non simmetrica verificata con 1a rappresentazione.");
    else
             printf("Matrice simmetrica verificata con 1a rappresentazione.");



 /********************************************/
    vett_p=malloc(nr*sizeof(vett_*));
    n=malloc(nr*sizeof(int));
    for(i=0;i<nr;i++)
        n[i]=0;
    for(i=0;i<nr;i++)
    {
        for(j=0;j<nc;j++)
        {
            if(vett[i][j]!=0)
                n[i]++;
        }
        vett_p[i]=malloc(n[i]*sizeof(vett_));
        k=0;
        for(j=0;j<nc;j++)
        {
            if(vett[i][j]!=0)
                {
                    vett_p[i][k].valore=vett[i][j];
                    vett_p[i][k].indice=j;
                    k++;
                }
        }

        }

    /* 2 rappresentazione */

    for(i=0;i<nr;i++)
    {
        printf("\n-->");
        for(j=0;j<n[i];j++)
            printf(" # %d %d ", vett_p[i][j].indice, vett_p[i][j].valore);
        printf("\n");
    }
    flag=0;
    for(i=0;i<nr && flag==0;i++)
    {
        for(j=0;j<n[i] && flag==0;j++)
          {
              if(i!=vett_p[i][j].indice) /*non si trova sulla diagonale*/
              {
                  for(k=0;k<n[(vett_p[i][j].indice)];)
                  {
                      if((vett_p[vett_p[i][j].indice][k].indice==i) && (vett_p[vett_p[i][j].indice][k].valore== vett_p[i][j].valore))
                        {flag=0;
                        break;}
                    else
                    {
                        flag=1;
                        k++;
                    }
                  }
              }
          }
    }
        if(flag==1)
        printf("\nMatrice non simmetrica verificata con 2a rappresentazione.");
        else
             printf("\nMatrice simmetrica verificata con 2a rappresentazione.");

            /* ricerca elemento*/

        printf("\nInserisci riga e colonna dell'elemento da ricercare:");
        scanf("%d %d",&r,&c);

             /* 1a rappr */

             printf("\n(1a rapp)Elemento = %d", vett[r-1][c-1]);
             /*2a rappres*/
             flag=0;
                 for(j=0;j<n[r-1] && flag==0;j++)
                   {

                   if((c-1)==vett_p[r-1][j].indice)
                     {
                          printf("\n(2a rapp)Elemnto in posizione %d %d ha valore %d", r,c,vett_p[r-1][j].valore);
                            flag=1;
                     }
                 }

             if(flag==0)
              printf("\n(2a rapp)Elemnto in posizione %d %d ha valore 0", r,c);
    return 0;
}
