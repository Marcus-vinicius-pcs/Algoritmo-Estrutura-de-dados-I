#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux {
    TIPOCHAVE chave;
    struct aux *esq, *dir;
} NO;

typedef NO* PONT;

void exibirArvorePreOrdem(PONT raiz){
    if(raiz == NULL) return;
    printf("%i ", raiz->chave);
    exibirArvorePreOrdem(raiz->esq);
    exibirArvorePreOrdem(raiz->dir);
}

void exibirArvoreEmOrdem(PONT raiz){
    if(raiz == NULL) return;
    exibirArvoreEmOrdem(raiz->esq);
    printf("%i ", raiz->chave);
    exibirArvoreEmOrdem(raiz->dir);
}

void exibirArvorePosOrdem(PONT raiz){
    if(raiz == NULL) return;
    exibirArvorePosOrdem(raiz->esq);
    exibirArvorePosOrdem(raiz->dir);
    printf("%i ", raiz->chave);
}

void preOrdemNaoRecursivo(PONT raiz){
    if(!raiz) return;
    PILHA pi;
    inicializarPilha(&pi);
    PONT atual;
    while(!isEmpty(&pi)){
        atual = pop(&pi);
        printf("%i ", atual->chave);
        if(atual->dir) push(atual->dir, &pi);
        if(atual->esq) push(atual.esq, &pi);
    }
    printf("\n");
}

void exibirArvoreEmNivel(PONT raiz){
    if(!raiz) return;
    FILA f;
    inicializarFila(&f);
    entrarFila(raiz, &f);
    PONT atual;
    while(f.inicio){
        atual = sairFila(&f);
        printf("%i ", atual->chave);
        if(atual->esq)
            entrarFila(atual->esq, &f);
        if(atual->dir)
            entrarFila(atual.dir, &f);
    }
    printf("\n";)
}