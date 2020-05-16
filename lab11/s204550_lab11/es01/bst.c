#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "bst.h"
typedef struct BSTnode *link;
struct BSTnode{Item item; link l;link r;};
struct albero{link head;int N; link z;};

link NEW(Item it, link l, link r)
{
    link x=malloc(sizeof *x);
    x->item= it;
    x->l=l;
    x->r=r;
    return x;
}
BST creabst()
{
    link t=NEW(NULLITEM(),NULL,NULL);
    BST bst=malloc(sizeof *bst);
    bst->N=0;
    bst->head=bst->z=t;
    return bst;
}
link ins_f(link h, Item x, link z)
{
    if(h == z)
        return (NEW(x,z,z));
    if(contr_key(x,h->item)==1)
        h->l= ins_f(h->l,x,z);
    if(contr_key(x,h->item)==2)
        h->r= ins_f(h->r,x,z);
    return h;

}
void ins_foglia(BST bst,Item x)
{
    bst->head = ins_f(bst->head,x,bst->z);
    return;
}
link rotL(link h)
{
    link x = h->r;
    h->r=x->l;
    x->l=h;
    return x;
}
link rotR(link h)
{
    link x = h->l;
    h->l=x->r;
    x->r=h;
    return x;
}
link ins_r(link h, Item x, link z)
{
    if(h == z)
        return (NEW(x,z,z));
    if(contr_key(x,h->item)==1)
        {h->l= ins_r(h->l,x,z);
        h=rotR(h);}
    if(contr_key(x,h->item)==2)
        {h->r= ins_r(h->r,x,z);
        h=rotL(h);}
    return h;

}
void ins_radice(BST bst, Item x)
{
    bst->head=ins_r(bst->head,x,bst->z);
    return;
}
Item cerca_e(link h,Item k , link z )
{
     if(h == z)
        return NULLITEM();
    if(contr_key(k,h->item)==0)
        return h->item;
    if(contr_key(k,h->item)==1)
        return cerca_e(h->l,k,z);
    else
    return cerca_e(h->r,k,z);
}
void cerca_elem(BST bst)
{
    Item t=malloc(sizeof(Item));
    Item k=malloc(sizeof(Item));
    k=salva_key();
    t=cerca_e(bst->head,k,bst->z);
    stampa_item(t);
    return;
}
Item max_e(link h,link z)
{
    if(h==z)
        return NULLITEM();
    if(h->r==z)
        return (h->item);
    return max_e(h->r,z);
}
void max_elem(BST bst)
{
    Item t=max_e(bst->head, bst->z);
    stampa_item(t);
    return;
}
Item min_e(link h,link z)
{
    if(h==z)
        return NULLITEM();
    if(h->l==z)
        return (h->item);
    return min_e(h->l,z);
}
void min_elem(BST bst)
{
    Item t=min_e(bst->head, bst->z);
    stampa_item(t);
    return;
}
void pre_o(link h, link z)
{
    if(h==z)
        return;
    stampa_item(h->item);
    pre_o(h->l,z);
    pre_o(h->r,z);
}
void pre_ordine(BST bst)
{
    pre_o(bst->head,bst->z);
    return;
}
void in_o(link h, link z)
{
    if(h==z)
        return;
    in_o(h->l,z);
    stampa_item(h->item);
    in_o(h->r,z);
}
void in_ordine(BST bst)
{
    in_o(bst->head,bst->z);
    return;
}
void post_o(link h, link z)
{
    if(h==z)
        return;
    post_o(h->l,z);
    post_o(h->r,z);
    stampa_item(h->item);
}
void post_ordine(BST bst)
{
    post_o(bst->head,bst->z);
    return;
}
int alt(link h, link z)
{
    int u,v;
    if(h==z)
    return -1;
    u=alt(h->l,z);
    v=alt(h->r,z);
    if(u>v)
        return u+1;
    else
        return v+1;
}
void altezza(BST bst)
{
    printf("\nAltezza = %d",alt(bst->head,bst->z));
    return;
}
int nodi_a(link h, link z)
{
    if(h==z)
        return 0;
    return nodi_a(h->l,z)+ nodi_a(h->r,z)+1;
}
void nodi_albero(BST bst)
{
     printf("\nNodi tot albero = %d",nodi_a(bst->head,bst->z));
    return;
}
int nodi_f(link h, link z, int c)
{
    if((h->l==z) && (h->r==z))
       return c+1;
    if(h->l==z)
        {c=nodi_f(h->r,z,c);
        return c;}
    if(h->r==z)
        {c=nodi_f(h->l,z,c);
        return c;}
    else
        {c=nodi_f(h->l,z,c);
        c=nodi_f(h->r,z,c);
        return c;}
}
void nodi_foglie(BST bst)
{
    int c=0;
    c=nodi_f(bst->head,bst->z,c);
     printf("\nNodi foglie = %d",c);
    return;
}
FILE* salv_in_o(link h, link z, FILE *fp)
{
    if(h==z)
        return fp;
    salv_in_o(h->l,z,fp);
    fp=salva_it_sufile(fp,h->item);
    salv_in_o(h->r,z,fp);
    return fp;
}
void salva_suf_in_ordine(BST bst)
{
    char nomefile[10];
    FILE *fp;
    printf("\nNome file su cui caricare:");
    scanf("%s",nomefile);
    fp=fopen(nomefile,"w");
    fp=salv_in_o(bst->head,bst->z,fp);
    fclose(fp);
    return;
}
void carica_daf(BST bst)
{
    char nomefile[10],st[50];
    FILE *fp;
    Item t;
    printf("\nNome file da cui caricare:");
    scanf("%s",nomefile);
    fp=fopen(nomefile,"r");
    while(fgets(st,50,fp)!=NULL)
    {
        t=salva_item(st);
        ins_foglia(bst,t);
    }
    fclose(fp);
    return;
}
