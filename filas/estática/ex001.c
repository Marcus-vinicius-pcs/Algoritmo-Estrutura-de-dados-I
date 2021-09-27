#include <stdio.h>

#define MAX 50
#define false 0
#define true 1

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int inicio;
    int nroElem; 
} FILA;

void inicializar(FILA* f){
    f->nroElem = 0;
    f->inicio = 0;
}

//retorna numero de elementos
int retornaElementos(FILA* f){
    return f->nroElem;
}

//EXIBIR FILA
void imprimirFila(FILA* f){
    int i = f->inicio;
    for(int temp = 0; temp < f->nroElem; temp++){
        printf("%i ", f->A[i].chave);
        i = (i + 1) % MAX;
    }
}

//INSERIR ELEMENTOS
bool inserirElementos(FILA* f, REGISTRO reg){
    if(f->nroElem >= MAX) return false;
    int posicao = (f->inicio + f->nroElem) % MAX;
    f->A[posicao] = reg;
    f->nroElem++;
    return true;
}

//EXCLUSÃO DE UM ELEMENTO 
bool excluirElemento (FILA* f, REGISTRO* reg){
    if(f->nroElem == 0) return false;
    *reg = f->A[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->nroElem--;
    return true;
}

//REINICIALIZAR FILA
void reinicializar(FILA* f){
    inicializar(f);
}