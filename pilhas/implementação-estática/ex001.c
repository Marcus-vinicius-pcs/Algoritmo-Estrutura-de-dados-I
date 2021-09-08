#include <stdio.h>
 #define MAX 50
 
 #define true 1
 #define false 0
typedef int bool;

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int topo;
} PILHA;

//INICIALIZAÇÃO 

void inicializarPilha (PILHA* p){
    p->topo = -1;
}
//RETORNAR A QUANTIDADE DE ELEMENTOS
int retornarElementos(PILHA* p){
    return p->topo+1;
}

//IMPRIMIR OS ELEMENTOS VÁLIDOS
void imprimirPilha(PILHA* p){
    printf("PILHA: \"");
    for(int i = p->topo; i >= 0; i--)
        printf("%i ", p->A[i]);
    printf("\"\n");
}

//INSERÇÃO DE UM ELEMENTO (PUSH)
bool inserirElemento (PILHA* p, REGISTRO reg){
    if(p->topo == MAX-1) return false;
    p->topo++;
    p->A[p->topo] = reg;
    return true;
}

//EXCLUSÃO DE UM ELEMENTO (POP)
bool excluirElemento(PILHA* p, REGISTRO* reg){
    if(p->topo == -1) return false;
    *reg = p->A[p->topo];
    p->topo--;
    return true;
}

//REINICIALIZAÇÃO DA PILHA
void reinicializar(PILHA* p){
    p->topo = -1;
}