#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fin1, *fin2, *fout;
    int r1,r2,c1,c2;
    int i,j,k;
    int **m1, **m2, **m3;

    fin1=fopen("filein1.txt","r");
    fscanf(fin1,"%d %d", &r1,&c1);
    m1 = malloc(r1*sizeof(int *));
    if(m1==NULL)
        return 1;
    for(i=0;i<r1;i++)
    {
        m1[i]= malloc(c1*sizeof(int));
        if(m1[i]==NULL)
            exit(3);
        for(j=0;j<c1;j++)
        {
            fscanf(fin1,"%d",&m1[i][j]);
        }
    }
    fclose(fin1);

    fin2=fopen("filein2.txt","r");
    fscanf(fin2,"%d %d", &r2,&c2);
    m2 = malloc(r2*sizeof(int*));
    if(m2==NULL)
    exit (2);
    for(i=0;i<r2;i++)
    {
          m2[i]= malloc(c2*sizeof(int));
        if(m2[i]==NULL)
            exit(4);
        for(j=0;j<c2;j++)
        {
            fscanf(fin2,"%d",&m2[i][j]);
        }
    }
    fclose(fin2);

    if(c1==r2)
    {
        m3= malloc(r1*(sizeof(int*)));
        if(m3==NULL)
         exit(6);
        for(i=0;i<r1;i++)
        {
              m3[i]= malloc(c2*sizeof(int));
        if(m3[i]==NULL)
            exit(5);
            for(j=0;j<c2;j++)
            {
                m3[i][j]=0;
                for(k=0;k<c1;k++)
                {
                    m3[i][j]+=m1[i][k]* m2[k][j];
                }
            }
        }

        fout=fopen("fileout.txt","w");
        fprintf(fout,"%d %d\n",r1, c2);
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                fprintf(fout,"%d ", m3[i][j]);

        }
            fprintf(fout, "\n");
        }
        fclose(fout);
    }

    else
    printf("Impossibile effettuare il prodotto.");

    return 0;
}
