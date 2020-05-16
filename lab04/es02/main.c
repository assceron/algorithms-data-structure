#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10
typedef struct studente{
char *nome;
char *cognome;
char data[M+1];
char sesso;
}studenti;

int main(int argc, char *argv[])
{

    FILE *f_in, *f_out1, *f_out2;
    int N,i,j,gg1,mm1,aa1,gg2,mm2,aa2,n,c;
    char nom[36],cognom[36];
    studenti *stud ,t;

    if(argc!=4){
        printf("Errore linea di comando.");
        exit(1);
    }
    f_in=fopen(argv[1],"r");
    if(f_in==NULL)
    {
        printf("Errore apertura file input");
        exit(2);
    }
    fscanf(f_in,"%d", &N);
    stud=malloc(N*sizeof(studenti));
    for(i=0;i<N;i++)
    {
        fscanf(f_in,"%s %s %s %c",nom,cognom,stud[i].data, &stud[i].sesso);
        n=strlen(nom);
        c=strlen(cognom);
        stud[i].nome=malloc((n+1)*sizeof(char));
        stud[i].cognome=malloc((c+1)*sizeof(char));
        strcpy(stud[i].cognome,cognom);
        strcpy(stud[i].nome,nom);
        nom[0]='\0';
        cognom[0]='\0';
    }
    fclose(f_in);

    for(i=0;i<N;i++)
    {

        for(j=0;j<N-i-1;j++)
        {
            t=stud[j];
           sscanf(stud[j].data,"%d%*c%d%*c%d", &gg1,&mm1,&aa1);
            sscanf(stud[j+1].data,"%d%*c%d%*c%d", &gg2,&mm2,&aa2);
            if(aa1>aa2)
               {stud[j]=stud[j+1];
               stud[j+1]=t;}
            if(aa1==aa2)
            {
                if(mm1>mm2)
                    {stud[j]=stud[j+1];
                    stud[j+1]=t;}
                if(mm1==mm2)
                {
                    if(gg1>gg2)
                       {stud[j]=stud[j+1];
                        stud[j+1]=t;}
                }
            }
        }
    }


    f_out1=fopen(argv[2],"w");
    f_out2=fopen(argv[3],"w");
    if(f_out1==NULL || f_out2==NULL)
    {
        printf("Errore apertura file output");
        exit(3);
    }
    for(i=0;i<N;i++)
    {
        if(stud[i].sesso=='F')
            fprintf(f_out2,"%s %s %s %c\n",stud[i].nome,stud[i].cognome,stud[i].data, stud[i].sesso);
        if(stud[i].sesso=='M')
            fprintf(f_out1,"%s %s %s %c\n",stud[i].nome,stud[i].cognome,stud[i].data, stud[i].sesso);

    }
    fclose(f_out1);
    fclose(f_out2);
    free(stud);

    for(i=0;i<N;i++)
    {
        free(stud[i].nome);
        free(stud[i].cognome);
    }
    return 0;
}

