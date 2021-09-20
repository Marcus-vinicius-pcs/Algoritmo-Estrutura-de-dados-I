#include <stdio.h>
#include <malloc.h>

#define false 0 
#define true 1
typedef int bool;

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
    //outros campos...
} REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
    PONT topo;
} PILHA;

//INCIALIZAÇÃO DA PILHA
void inicializarLista(PILHA* p){
    p->topo = NULL;
}
//CONTAR NUMERO DE ELEMENTOS DA PILHA
int tamanho(PILHA* p){
    PONT aux = p->topo;
    int tam = 0;
    while(aux!=NULL){
        tam++;
        aux = aux->prox;
    }
    return tam;
}
//VERIFICAR SE A PILHA ESTÁ VAZIA
bool verificar(PILHA* p){
    if(p->topo == NULL) return true;
    return false;
}

//IMPRIMIR PILHA
void imprimirPilha(PILHA* p){
    PONT aux = p->topo;
    printf("Pilha: \"");
    while(aux != NULL){
        printf("%i ", aux->reg.chave);
        aux  =aux->prox;
    }
    printf("\"\n");
}

//INSERÇÃO DE UM ELEMENTO (PUSH)
bool inserirElemento(PILHA* p, REGISTRO reg){
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

//EXCLUIR ELEMENTO (POP)
bool excluirElemento(PILHA* p, REGISTRO* reg){
    if(verificar(p)) return false;
    *reg = p->topo->reg;
    PONT apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);
    return true;
}

//REINICIALIZAR PILHA 
void reinicializar(PILHA* p){
    PONT aux = p->topo, apagar;
    while(aux!=NULL){
        apagar = aux;
        aux = aux->prox;
        free(apagar);
    }
    p->topo = NULL;
}

