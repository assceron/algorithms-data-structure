#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10
int main(int argc, char *argv[])
{
    FILE *fp,*fo;
    int R,i,j,l,flag,p,c, occ[100],pos[100][M];
    char filt[100][4+1],parola[100];
    if(argc!=3)
    {
        printf("Errore linea comando.");
        exit(1);
    }

    fp=fopen(argv[1],"r");
    fscanf(fp,"%d",&R);
    i=0;
    while(fscanf(fp,"%s",filt[i])!=EOF)
    {
        i++;
    }
    fclose(fp);

    for(i=0;i<R;i++)
    {
            occ[i]=0;
        for(j=0;j<M;j++)
            pos[i][j]=0;
    }

    fo=fopen(argv[2],"r");
    p=0;
    while(fscanf(fo,"%s",parola)!=EOF)
    {
        p++;
        for(i=0;i<R;i++)
        {
            l=strlen(filt[i]);
            flag=0;
            for(j=0;j<l && flag==0;j++)
            {
                if(filt[i][j]==parola[j])
                    flag=0;
                else
                    flag=1;
            }
            if(flag==0)
            {
                c=occ[i]=occ[i]+1;
                pos[i][c-1]=p;
            }
        }
    }
    fclose(fo);

    for(i=0;i<R;i++)
    {
        printf("%s - ",filt[i]);
        printf("%d occorrenza/e ", occ[i]);
        if(occ[i]!=0){
        printf("- posizione/i: ");
        for(j=0;j<occ[i];j++)
        printf("%d ",pos[i][j]);}
        printf("\n");
    }

    return 0;
}
