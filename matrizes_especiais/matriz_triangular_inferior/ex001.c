#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 0
typedef int bool;

typedef struct {
    int ordem;
    int* A;
} MTI;
/*

Vai ficar como um arranjo com os elementos zerados

*/
void inicializarMatriz(int n, MTI* matriz){
    matriz->ordem = n;
    int numeroDeElementos = (n + n*n)/2;
    matriz->A = (int*) malloc(sizeof(int)*numeroDeElementos);
    for(int i = 0; i<numeroDeElementos; i++)
        matriz->A[i] = 0;
}

int retornaPosicao(int lin, int col){
    return (lin*lin-lin)/2 + col;
}

bool AtribuiMatriz(int lin, int col, int val, MTI* mat){
    if ((lin<1) || (lin>mat->ordem) || (col < 1) || (col > mat->ordem) || (lin < col)) return false;
    int posicao = retornaPosicao(lin, col);
    mat->A[posicao] = val;
    return true;
}

int acessaValor(int lin, int col, MTI* matriz){
    if((lin<1) || (lin>matriz->ordem) || (col < 1) || (col > matriz->ordem) || (lin < col)) return -1;
    if(lin< col) return 0;
    return matriz->A[retornaPosicao(lin, col)];
}

