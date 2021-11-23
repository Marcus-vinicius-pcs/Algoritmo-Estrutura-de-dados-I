#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0 

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux {
    TIPOCHAVE chave;
    //dados
    struct aux *esq, *dir;
} NO;

typedef NO* PONT;

PONT criaNovoNo(TIPOCHAVE ch){
    PONT novoNo = (PONT) malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    return novoNo;
}

bool inserirNo(PONT* raiz, TIPOCHAVE ch){
    if(*raiz == NULL){
        *raiz = criarNovoNO(ch);
        return true;
    } else{
        if((*raiz)->chave >= ch)
            return inserirNo(&(*raiz)->esq, ch);
        else return inserirNo(&(*raiz)->dir, ch);
    }
}

bool excluirNo(PONT* raiz, TIPOCHAVE ch){
    PONT atual = *raiz;
    if(!atual) return false;
    if(atual->chave == ch){
        PONT substituto, pai_substituto;
        if(!atual->esq || !atual->dir){
            if(atual->esq) substituto = atual->esq;
            else substituto = atual->dir;
            *raiz = substituto;
            free(atual);
            return true;
        } else {
            substituto = maiorAEsquerda(atual, &pai_substituto);
            atual->chave = substituto->chave;
            ch = substituto->chave;
        }
    }
    if(ch > atual->chave) return excluirNo(&(atual->dir), ch);
    else return excluirNo(&(atual->esq), ch);
}