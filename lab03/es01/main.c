#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct punto
{
    float x;
    float y;
    float dist_O;
    };
    struct punto *p;


void Bubblesort ( struct punto *p, int N){
int k,t;
struct punto temp;
for(k=0;k<N;k++)
{
    for(t=0;t<N-k-1;t++)
    {
        if((p[t].dist_O)>(p[t+1].dist_O))
        {

            temp.x=p[t].x;
            p[t].x=p[t+1].x;
            p[t+1].x=temp.x;
            temp.y=p[t].y;
            p[t].y=p[t+1].y;
            p[t+1].y=temp.y;
            temp.dist_O=p[t].dist_O;
            p[t].dist_O=p[t+1].dist_O;
            p[t+1].dist_O=temp.dist_O;
        }
    }
}
return;
}

int main()
{
    FILE *fin, *fout;
    int N=0,i,j,w;
    char ch[100];
    float dist;
    float min=1000,x_min[2],y_min[2], max=0,x_max[2], y_max[2], cont_d=0,d;
    struct punto *p;

    fin=fopen("Filein.txt","r");

   while(fgets(ch,100,fin)!=NULL)
    {

            N++;

    }
        p = malloc(N* sizeof(struct punto));
   if (p == NULL)
   {
       printf("Errore allocazione memoria.");
       exit(1);
   }

    rewind(fin);

    for(w=0;w<N;w++)
   {
       fscanf(fin,"%f %f",&p[w].x, &p[w].y);


   }

    fclose(fin);

    printf("Inserisci lunghezza limite: ");
    scanf("%f", &d);

    for(i=0;i<N;i++)
    {
        for(j=i+1;j<N;j++)
        {
            dist =sqrt( ((p[i].x - p[j].x)*(p[i].x - p[j].x)) +  ((p[i].y - p[j].y)*(p[i].y - p[j].y))  );
            if(dist<min)
            {
               x_min[0]=p[i].x;
               x_min[1]=p[j].x;
               y_min[0]=p[i].y;
               y_min[1]=p[j].y;
               min=dist;
            }

            if(dist>max)
            {
               x_max[0]=p[i].x;
               x_max[1]=p[j].x;
               y_max[0]=p[i].y;
               y_max[1]=p[j].y;
               max=dist;
            }

            if(dist< d)
                cont_d++;
        }
        p[i].dist_O= sqrt(  ((p[i].x)*(p[i].x)) + ( (p[i].y)*(p[i].y)));

    }
    printf("Coppia di punti piu' vicini: %.2f %.2f - %.2f %.2f\n", x_min[0],y_min[0],x_min[1],y_min[1]);
    printf("Coppia di punti piu' lontani: %.2f %.2f - %.2f %.2f\n",x_max[0],y_max[0],x_max[1],y_max[1]);
    printf("numero segmenti maggiori di %.2f :  %.2f\n", d, cont_d );
    fout=fopen("Fileout.txt","w");
     Bubblesort(p,N);
    for(i=0;i<N;i++)
        fprintf(fout,"%.2f %.2f\n", p[i].x, p[i].y);
    fclose(fout);
    free(p);
    return 0;
}
