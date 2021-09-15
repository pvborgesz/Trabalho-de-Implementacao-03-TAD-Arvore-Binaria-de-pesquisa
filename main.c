#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

typedef struct _aluno_{
    char nome[30];
    int matricula;
    float media;
}Aluno;

int cmp(void *elm, void *key){
    char *pelm = (char *)elm;
    Aluno *pkey = (Aluno *)key;
    return strcmp(pelm, pkey->nome);
}


void visit(void *objeto){
    Aluno *produto = (Aluno *)objeto;
    printf("\nNome: %s\n",produto->nome);
    printf("Matricula: %d\n",produto->matricula);
    printf("Media: %.2f \n",produto->media);
}

int main(){
    TNode *t = NULL;
    Aluno *aluno;
    int op;
    void **data;
    int codigo;
    char procura;
    int qtdAlunos=0;
    do{
        printf("\n-----FILA DO RU-----");
        printf("\n1 - Inserir Aluno");
        printf("\n2 - Remover Aluno");
        printf("\n3 - Consultar Aluno");
        printf("\n4 - Listar Aluno");
        printf("\n5 - Esvaziar fila do RU");
        printf("\n0 - Sair\n");
        printf("--------------------\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            //Inserir produto na arvore
            aluno = (Aluno *)malloc(sizeof(Aluno));
            printf("\nQual o nome do Aluno?\n");
            scanf("%s",&aluno->nome);
            printf("Qual o codigo do Aluno?\n");
            scanf("%d",&aluno->matricula);
            printf("Qual a media do Aluno?\n");
            scanf("%f",&aluno->media);
            qtdAlunos++;

            if(t==NULL){
                t = treeInsert(NULL, aluno, cmp);
                if(t){
                    printf("\n Aluno inserido!\n");
                }else{
                    printf("\Aluno nao inserido!\n");
                }
            }else{
                if(treeInsert(t, aluno, cmp)){
                    printf("Aluno inserido!\n");
                }else{
                    printf("Aluno nao inserido!\n");
                }
            }

            break;
        case 2:
            //Remover produto da arvore
            aluno = (Aluno *)malloc(sizeof(Aluno));
            printf("\nInsira o nome do aluno que voce quer remover:\n");
            scanf("%s",&aluno->nome);

            treeRemove(t,(void*)&aluno->nome,cmp,&data);
            if(data!=NULL){
                printf("\nAluno removido com sucesso!!!\n");
            }else{
                printf("\nFalha ao remover item!!\n");
            }

            break;
        case 3:
            //Procura aluno na fila 
            aluno = (Aluno *)malloc(sizeof(Aluno));
            printf("\nInsira o nome do aluno que voce quer procurar:\n");
            scanf("%s",&aluno->nome);

            aluno = treeQuery(t,&aluno->nome,cmp);

            if(aluno == NULL){
                printf("\nNao existe esse aluno na fila do RU!!!\n");
            }else{
                printf("\nNome: %s\n",aluno->nome);
                printf("matricula: %d\n",aluno->matricula);
                printf("media: %.2f \n",aluno->media);
            }
            break;
        case 4:
            //lista com o metodo simetrica
            if(t==NULL){
                printf("\nNao temos alunos na fila do RU no momento!!!\n");
              }else{
            printf("\n--------ALUNOS NA FILA---------");
            simetrico(t,visit);
              }
            break;
        case 5:
          t = abpEsvaziar(t);
          if(qtdAlunos==0){
            printf("nao tem ninguem na fila do RU! \n");
          }else{
            qtdAlunos=0;
            printf("Fila esvaziada!\n");
          }
          break;    

        case 0:
          printf("Obrigado por usar nosso programa!!\n");
          printf("Autores: João Mateus e Paulo Victor\n");
          break;
        
        default:
            printf("\nopcao invalida.\n");
            break;
        }

    }
    while (op != 0);    

    return 0;
}