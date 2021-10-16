#include <stdio.h>
#define MAX 50
#define false 0
#define true 1

typedef int TIPOCHAVE;
typedef int bool;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int topo1;
    int topo2;
} PILHADUPLA;

void inicializarPilha (PILHADUPLA* p){
    p->topo1 = -1;
    p->topo2 = MAX;
}

int retornaNumeroElementos(PILHADUPLA* p){
    int tamanho = p->topo1+1 + MAX - p->topo2;
    return tamanho;
}

bool imprimirPilha(PILHADUPLA* p, int pilha){
    if(pilha < 1 || pilha > 2) return false;
    int i;
    if(pilha == 1)
        for (i = p->topo1; i>=0; i--)
            printf("%i ", p->A[i].chave);
    else 
        for(i = p->topo2; i < MAX; i++)
            printf("%i ", p->A[i].chave);
    return true;
}

bool insereElemento(PILHADUPLA* p, REGISTRO reg, int pilha){
    if(pilha < 1 || pilha > 2) return false;
    if(p->topo1 + 1 == p->topo2) return false;
    if(pilha == 1){
        p->topo1 = p->topo1 + 1;
        p->A[p->topo1] = reg;
    }
    else {
        p->topo2 = p->topo2 - 1;
        p->A[p->topo2] = reg;
    }
    return true;
}

bool excluiElemento(PILHADUPLA* p, REGISTRO* reg, int pilha) {
    if(pilha < 1 || pilha > 2) return false;
    if(pilha == 1) {
        if(p->topo1 == -1) return false;
        *reg = p->A[p->topo1];
        p->topo1 = p->topo1 - 1;
    }
    else {
        if(p->topo2 == MAX) return false;
        *reg = p->A[p->topo2];
        p->topo2 = p->topo2 + 1;
    }
    return true;
}

void reinicializarPilha(PILHADUPLA* p){
    inicializarPilha(p);
}

