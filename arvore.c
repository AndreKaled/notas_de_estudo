#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore
{
    int dado;
    struct Arvore *dir;
    struct Arvore *esq;
}Arvore;

Arvore* iniciaArvore(){
    return NULL;
}

Arvore* insereDado(Arvore *no, int dado){
    if(no == NULL){
        no = (Arvore*) malloc(sizeof(Arvore));
        no->dir = NULL;
        no->esq = NULL;
        no->dado = dado;
    }else if(no->dado <= dado)
        no->esq = insereDado(no->esq, dado);
    else
        no->dir = insereDado(no->dir, dado);
    return no;
}

Arvore* inserePorVetor(Arvore *a, int *v, int tam){
    for(int i = 0; i < tam; i++){
        a = insereDado(a, v[i]);
    }
    return a;
}

void preOrdem(Arvore* no){
    if(no != NULL){ 
        printf("%d ", no->dado);
        preOrdem(no->esq);
        preOrdem(no->dir);
    }
}

#define TAM 7
void main(){
    Arvore *arvore;
    int v[TAM] = {5,6,4,9,2,8,1};
    arvore = iniciaArvore();
    arvore = inserePorVetor(arvore, v, TAM);
    preOrdem(arvore);
    printf("\n");
}