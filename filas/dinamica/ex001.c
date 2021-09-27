#include <stdio.h>
#include <malloc.h>

#define true 1 
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
    //outros campos...
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox; 
} ELEMENTO, *PONT;

typedef struct {
    PONT inicio;
    PONT fim;
} FILA;

//INICIALIZAÇÃO
void inicializar(FILA* f){
    f->inicio = NULL;
    f->fim = NULL;
}
//RETORNAR NUMERO DE ELEMENTOS 
int retornarElementos(FILA* f){
    PONT aux = f->inicio;
    int tam = 0;
    while(aux!=NULL){
        tam++;
        aux = aux->prox;
    }
    return tam;
}
//EXIBIÇÃO
void imprimirFila(FILA* f){
    PONT aux = f->inicio;
    while(aux!=NULL){
        printf("%i ", aux->reg.chave);
        aux = aux->prox;
    }
}

//INSERÇÃO DE UM ELEMENTO 
bool inserirElementos(FILA* f, REGISTRO reg){
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = NULL;
    if(f->inicio == NULL) f->inicio = novo;
    else f->fim->prox = novo;
    f->fim = novo;
    return true;
}

//EXCLUSÃO DE UM ELEMENTO 
bool excluirElemento(FILA* f, REGISTRO* reg){
    if(f->inicio == NULL) return false;
    *reg = f->inicio->reg;
    PONT apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);
    if(f->inicio == NULL) f->fim = NULL;
    return true;
}

//REINICIALIZAR
void reinicializar(FILA*f){
    PONT aux = f->inicio;
    while(aux != NULL){
        PONT apagar = aux;
        aux = aux->prox;
        free(apagar);
    }
    f->inicio = NULL;
    f->fim = NULL;
}