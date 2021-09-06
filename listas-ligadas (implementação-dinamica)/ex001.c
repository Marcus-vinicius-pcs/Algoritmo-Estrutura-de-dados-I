#include <stdio.h>
#include <malloc.h>
#define false 0
#define true 1

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
    //outros campos...
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT inicio;
} LISTA;

//INICIALIZAÇÃO DA LISTA 
void inicializarLista(LISTA* li){
    li->inicio = NULL;
}
//RETORNAR NUMERO DE ELEMENTOS DA LISTA
int retornarElementos(LISTA* li){
    PONT end = li->inicio;
    int tam = 0;
    while(end != NULL){
        tam++;
        end = end->prox;
    }
    return tam;
}
//IMPRIMIR ELEMENTOS DA LISTA 
void imprimirLista(LISTA* li){
    PONT end = li->inicio;
    printf("Lista:\n\n");
    while(end != NULL) {
        printf("%i \n", end->reg.chave);
        end = end->prox;
    }
}
//BUSCAR POR UM ELEMENTO DA LISTA 
PONT buscaSequencial(LISTA* li, TIPOCHAVE chave){
    PONT pos = li->inicio;
    while(pos != NULL){
        if(pos->reg.chave == chave) return pos;
        pos = pos->prox;
    }
    return NULL;
}
PONT buscaSeqOrd(LISTA* li, TIPOCHAVE chave){
    PONT pos = li->inicio;
    while(pos!= NULL && pos->reg.chave < chave)
        pos = pos->prox;
    if(pos != NULL && pos->reg.chave == chave) return pos;
    return NULL;
}
//BUSCA- AUXILIAR
PONT buscaSequencialExc(LISTA* li, TIPOCHAVE chave, PONT* ant){
    *ant = NULL;
    PONT atual = li->inicio;
    while(atual != NULL && atual->reg.chave < chave){
        *ant = atual;
        atual = atual->prox;
    }
    if((atual != NULL) && (atual->reg.chave == chave)) return atual;
    return NULL;
}
//INSERÇÃO DE UM ELEMENTO 
bool inserirElem(LISTA* li, REGISTRO reg){
    PONT ant, i;
    TIPOCHAVE chave = reg.chave;
    i = buscaSequencialExc(li, reg.chave, &ant);
    if(i != NULL) return false; //isso significa que esse registro já existe na lista 
    i = (PONT) malloc(sizeof(ELEMENTO));
    i->reg = reg;
    if(ant == NULL){
        i->prox = li->inicio;
        li->inicio = i;
    }
    i->prox = ant->prox;
    ant->prox = i;
    return true;
}
//EXCLUIR UM ELEMENTO 
bool excluirElemento(LISTA* li, TIPOCHAVE chave){
    PONT ant, i;
    i = buscaSequencialExc(li, chave, &ant);
    if(i == NULL) return false;
    if(ant == NULL)
        li->inicio = i->prox;
    else ant->prox = i->prox;
    free(i);
    return true;
}
//REINICIALIZAR LISTA 
void reinicializarLista(LISTA* li){
    PONT end = li->inicio;
    while(end != NULL){
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    li->inicio = NULL;
}