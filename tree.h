/*------------------------------------------------
tree.h
Arquivo com a especificação para o TAD Colecao,
tipo de dado para uma árvore binária de pesquisa.
Exemplo do curso: Estrutura de Dados
---------------------------------------------------
Autores: João Mateus e Paulo Victor
Setembro/2021
-------------------------------------------------*/
#ifndef TREE_H
#define TREE_H

#define true 1
#define false 0

/*-------------------------------------------------
Definicoes locais
-------------------------------------------------*/
typedef struct _t_node_ 
TNode;

typedef struct _aluno_
Aluno;

typedef struct _tree_ 
Tree;

/*-------------------------------------------------
Funcoes que implementam as operacoes do
TAD TREE
*/

Tree * abpCreate();

TNode *treeInsert(TNode *t, void *key, int (*cmp)(void *, void *));
TNode *treeRemove(TNode* t, void *key, int(*cmp)(void*, void*), void **data);
TNode *treeQuery(TNode *t, void *key, int(*cmp)(void*, void*));
void *abpRemoveMenor(TNode *t, void **data);
TNode *abpEsvaziar(TNode *t);
int treeDestroy(TNode *t);

#endif
