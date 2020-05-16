#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct albero *BST;

BST creabst();
void ins_foglia(BST bst,Item x);
void ins_radice(BST bst,Item x);
void cerca_elem(BST bst);
void max_elem(BST bst);
void min_elem(BST bst);
void pre_ordine(BST bst);
void in_ordine(BST bst);
void post_ordine(BST bst);
void altezza(BST bst);
void nodi_albero(BST bst);
void nodi_foglie(BST bst);
void salva_suf_in_ordine(BST bst);
void carica_daf(BST bst);


#endif // BST_H_INCLUDED
