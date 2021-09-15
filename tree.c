#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#define TRUE 1
#define FALSE 0



//TAD Tree

typedef struct _t_node_ {
    void *data;
    char stat;
    struct t_node_ *left;
    struct t_node_ *right;
} TNode;

typedef struct _tree_{
  TNode *root;
}Tree;

typedef struct _aluno_{
  char nome[30];
  int matricula;
  float media;
}Aluno;

//criando arvore binária de busca
Tree * abpCreate(){
    Tree *t;
    t = (Tree *)malloc(sizeof(TNode));
    if (t!=NULL){
        t->root=NULL;
        return (t);
    }
    return NULL;
}


//inserir elemento na arvore binária de pesquisa
// TNode *abpInsert(TNode *t, void *key, int (*cmp)(void *, void *)){
//     TNode *newnode;
//     if (t == NULL){
//         newnode = (TNode *)malloc(sizeof(TNode));
//         if(newnode != NULL){
//             newnode->data = key;
//             newnode->left = newnode->right = NULL;
//             return newnode;
//         }else{
//             return NULL;
//         }
//     }else{
//         if(cmp(key, t->data) < 0){
//             t->left = abpInsert(t->left, key, cmp);
//         }
//         if(cmp(key, t->data) > 0){
//             t->right = abpInsert(t->right, key, cmp);
//         }
//         return t;
//     }
// }

TNode *treeInsert(TNode *t, void *key, int (*cmp)(void *, void *)){
    TNode *newnode;
    if (t == NULL){
        newnode = (TNode *)malloc(sizeof(TNode));
        if(newnode != NULL){
            newnode->data = key;
            newnode->left = newnode->right = NULL;
            return newnode;
        }else{
            return NULL;
        }
    }else{
        if(cmp(key, t->data) < 0){
            t->left = treeInsert(t->left, key, cmp);
        }
        if(cmp(key, t->data) > 0){
            t->right = treeInsert(t->right, key, cmp);
        }
        return t;
    }
}
//consultar um nó dentro de uma arvore binária de pesquisa
// void * abpQueryNode (TNode *t, int (*cmp)(void*, void*), void *key){
//     int stat;
//     if (t!=NULL){
//         stat=cmp(key, t->data);
//         if (stat==0){
//             return t->data;
//         }
//         else{
//             if (stat==-1){
//                 return (abpQueryNode(t->left, cmp, key));
//             }
//             else{
//                 return (abpQueryNode(t->right,cmp, key));
//             }
//         }
//     }
//     return NULL;
// }
TNode *treeQuery(TNode *t, void *key, int(*cmp)(void*, void*)){
    if (t == NULL){
        return NULL;
    }
    if(cmp(key,t->data) == 0){
        return t->data;
    }
    if(cmp(key,t->data) < 0){
        return treeQuery(t->left, key, cmp);
    }else{
        return treeQuery(t->right, key, cmp);
    }
}

//visitar a arvore (listar)
void simetrico(TNode *t, void (*visit)(void *)){
    if (t != NULL){
        simetrico(t->left, visit);
        visit(t->data);
        simetrico(t->right, visit);
    }
}



//remover um nó

TNode *treeRemove(TNode *t, void *key, int (*cmp)(void *, void *), void **data){
    TNode *aux;
    void **data2;

    if(t != NULL){
        if (cmp(key, t->data) < 0){
            t->left = treeRemove(t->left, key, cmp, &data);
            return t;
        }else{
            if(cmp(key, t->data) > 0){
                t->right = treeRemove(t->right, key, cmp, &data);
                return t;
            }else{
                if(t->left == NULL && t->right == NULL){
                    *data = t->data;
                    free(t);
                    return NULL;
                }else{
                    if(t->left == NULL){
                        *data = t->data;
                        aux = t->right;
                        free(t);
                        return aux;
                    }else{
                        if(t->right == NULL){
                            *data = t->data;
                            aux = t->left;
                            free(t);
                            return aux;
                        }else{
                            *data = t->data;
                            t->right = abpRemoveMenor(t->right, &data2);
                            t->data = data2;
                            return t;
                        }
                    }
                }
            }
        }
    }
    *data = NULL;
    return NULL;
}

void *abpRemoveMenor(TNode *t, void **data){
    if(t->left == NULL){
        *data = t->data;
        return NULL;
    }else{
        return abpRemoveMenor(t->left, &data);
    }
}

TNode *abpEsvaziar(TNode *t){
    if(t != NULL)
    {
        t->left = abpEsvaziar(t->left);
        t->right = abpEsvaziar(t->right);
        free(t);
        t = NULL;
    }
    return NULL;
}