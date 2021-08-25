#include <stdio.h>

//MODELAGEM

#define MAX 50
#define false 0
#define true 1


typedef int TIPOCHAVE;
typedef int bool;


typedef struct {
    TIPOCHAVE chave;
    //outros campos...
} REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int nroElem;
} LISTA;

//INICIALIZAÇÃO

void inicializarLista(LISTA* lista){
    lista->nroElem = 0;
}

//RETORNA NUMERO DE ELEMENTOS DA LISTA
int retornaNumeroDeElementos (LISTA* lista){
    return lista->nroElem;
}

//EXIBIÇÃO/IMPRESSÃO DOS ELEMENTOS DA LISTA
void imprimeLista(LISTA* lista){
    for (int i = 0; i<lista->nroElem; i++) 
        printf("elemento %i:\t conteudo: %i", i, lista->A[i].chave);
        printf("\n\n");
}

//BUSCAR POR UM ELEMENTO DA LISTA
int buscarPosicaoDoElemento(LISTA* lista, TIPOCHAVE chave){
    for (int i = 0; i < lista->nroElem; i++) {
        if(lista->A[i].chave == chave) return i;
    } 
    return -1;
}

//iNSERÇÃO DE UM ELEMENTO EM UMA POSIÇÃO INDICADA PELO USUÁRIO
bool insereElemento(LISTA* lista, REGISTRO registro, int posicao){
    REGISTRO aux;
    if((lista->nroElem == MAX) || (posicao < 0) || (posicao > lista->nroElem)) return false;
        for (int i = lista->nroElem; i > posicao; i--) lista->A[i] = lista->A[i-1];
        lista->A[posicao] = registro;
        lista->nroElem++;
        return true;
}

//EXCLUSAO DE UM ELEMENTO PELA CHAVE PASSADA PELO USUARIO
bool excluirElemento (LISTA* lista, TIPOCHAVE chave){
    int i, posicao;
    posicao = buscarPosicaoDoElemento(lista, chave);
    if(posicao == -1) return false;
    for(i=posicao; i<lista->nroElem; i++)
        lista->A[i] = lista->A[i+1];
    lista->nroElem--;
    return true;
}

//REINICIALIZAÇÃO DA ESTRUTURA
void reinicializarLista(LISTA* lista){
    lista->nroElem = 0;
}

