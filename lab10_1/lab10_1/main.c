#include <stdio.h>
#include <stdlib.h>
#define m 21
struct jo
{
    char job[10+1];
    int diff;
};
struct soluzione
{
    int **solu;
};
int controllo(struct soluzione sol, int n, int k)
{
    int i,j,num,flag=1;
    for(i=0;i<n && flag==1;i++)
    {
        num=0;
        for(j=0;j<k;j++)
        {
            if(sol.solu[j][i]==1)
                num++;
        }
        if(num!=1)
            flag=0;
    }



    return flag;
}
int differ(struct soluzione sol, struct jo jobs[],int n, int k)
{
    int min=100,max=0,s,d,i,j;
    for(i=0;i<k;i++)
    {
        s=0;
        for(j=0;j<n;j++)
        {
            if(sol.solu[i][j]==1)
                s+=jobs[j].diff;
        }
        if(s<min)
            min=s;
        if(s>max)
            max=s;
    }
    d=max-min;
    return d;
}


struct soluzione ott(int pos,int nRis,int j_res,struct jo jobs[], struct soluzione sol,struct soluzione bsol,int *bv, int n, int k)
{
    int i,j;
    if(nRis<k && pos>=n)
    {
        /*non ho ancora terminato di distribuire */
            for(i=0;i<n;i++)
            {
                if(sol.solu[nRis][i]==0)
                    j_res++;
            }
            if(j_res>=k-nRis-1 && j_res<n)
                {bsol=ott(0,nRis+1,0,jobs,sol,bsol,bv,n,k);
                return bsol;}
        else return bsol;
        }
    if(nRis>=k)/*ho terminato di distribuire*/
        {
            int d,contr;
            contr=controllo(sol,n,k);
            if(contr==1)
            {
            d=differ(sol,jobs,n,k);
            if(d<*bv)
            {
                for(i=0;i<k;i++)
                {
                    for(j=0;j<n;j++)
                        bsol.solu[i][j]=sol.solu[i][j];
                }
                *bv=d;
                }}
             return bsol;
                }

    sol.solu[nRis][pos]=0;
     bsol=ott(pos+1,nRis,j_res,jobs,sol,bsol,bv,n,k);
    sol.solu[nRis][pos]=1;
     bsol=ott(pos+1,nRis,j_res,jobs,sol,bsol,bv,n,k);
     return bsol;
}


int main(int argc,char *argv[])
{
    FILE *f_job,*f_ris;
    int n=0,k=0,i,j,*bv;
    char **ris,str[21];
    struct jo *jobs;
    struct soluzione sol,bsol;
    /*LETTURA FILE COMPITI*/
    f_job=fopen(argv[1],"r");
    while(fscanf(f_job,"%s%*d",str)!=EOF)
        n++;
    rewind(f_job);
    jobs=malloc(n*sizeof(struct jo));
    i=0;
    while(fscanf(f_job,"%s %d",jobs[i].job,&jobs[i].diff)!=EOF)
        i++;
    fclose(f_job);
    /*LETTURA FILE RISORSE*/
        f_ris=fopen(argv[2],"r");
    while(fscanf(f_ris,"%s",str)!=EOF)
        k++;
    rewind(f_ris);
    ris=malloc(k*sizeof(char*));
    for(i=0;i<k;i++)
    {
        ris[i]=malloc(m*sizeof(char));
        fscanf(f_ris,"%s",ris[i]);
    }
    fclose(f_ris);

    sol.solu=malloc(k*sizeof(int*));
    bsol.solu=malloc(k*sizeof(int*));
    for(i=0;i<k;i++)
        {
                sol.solu[i]=malloc(n*sizeof(int));
                bsol.solu[i]=malloc(n*sizeof(int));
        }

    bv=malloc(sizeof(int));
    *bv=100;

    bsol=ott(0,0,0,jobs,sol,bsol,bv,n,k);
    for(i=0;i<k;i++)
    {
        printf("\n %s :",ris[i]);
        for(j=0;j<n;j++)
        {
            if(bsol.solu[i][j]==1)
                printf("%s ,",jobs[j].job);
        }
        printf("}\n");
    }

    for(i=0;i<k;i++)
    {
        printf("\n %s :",ris[i]);
        for(j=0;j<n;j++)
        {
                printf("%d ,",bsol.solu[i][j]);
        }
        printf("\n");
    }
    return 0;
}
