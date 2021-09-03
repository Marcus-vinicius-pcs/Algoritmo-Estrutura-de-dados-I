//IMPLEMENTAÇÃO DE UMA LISTA LIGADA ESTÁTICA

#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define INVALIDO -1
#define false 0
#define true 1

typedef int bool;

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
    //outros campos...
} REGISTRO;

typedef struct {
    REGISTRO reg;
    int prox;
} ELEMENTO;

typedef struct {
    ELEMENTO A[MAX];
    int inicio;
    int dispo; //primeiro elemento disponivel
} LISTA;

/* INICIALIZAÇÃO 
- Colocar todos os elementos na "lista de disponiveis";
        - para isso, fazer com que todos os elementos apontem para um proximo. 
        - e que o ultimo elemento aponte para um invalido 
- variável dispo = 0
- variável inicio = INVALIDO 
*/
void iniciaizar_lista(LISTA* li){
    int i;
    for(i=0; i<MAX-1; i++)
    li->A[i].prox = i + 1;
    li->A[MAX-1].prox = INVALIDO;
    li->inicio = INVALIDO;
    li->dispo = 0;
}

//retornar a quantidade de elementos

int retornarNumElementos(LISTA* li){
    int i = li->inicio;
    int tam = 0;
    while(i != INVALIDO) {
        tam++;
        i = li->A[i].prox;
    }
    return tam;
}

//exibir os elementos
void imprimirElementos(LISTA* li){
    int i = li->inicio;
    printf("Lista: \" ");
    while(i != INVALIDO){
        printf("%i ", li->A[i].reg.chave);
        i = li->A[i].prox;
    }
    printf("\"\n");
}

//buscar por um elemento 
/*
receber uma chave do usuário
retornar a posição que este elemento se encontra no arranjo(se encontrado)
retornar invalido caso não haja um registro com essa chave 
*/

int busca(LISTA* li, TIPOCHAVE chave){
    int pos = INVALIDO;
    for(int i = 0; i<retornarNumElementos(li); i++){
        if(li->A[i].reg.chave == chave) pos = i;
    }
    return pos;
}

//busca elemento lista ordenada
/*
enquanto o a chave buscada for maior que chave do elemento passado por i, i vai apontando para o próximo
*/
int buscaSequencialOrd(LISTA* li, TIPOCHAVE chave){
    int i = li->inicio;
    while(i != INVALIDO && li->A[i].reg.chave < chave)
        i = li->A[i].prox;
    if(i != INVALIDO && li->A[i].reg.chave == chave)
    return i;
    else return INVALIDO;
}

/*
INSERÇÃO DE UM ELEMENTO 
- o usuário passa como parâmetro um registro a ser inserido na lista 
- a inserção será ordenada pelo valor da chave do registro parrado e não será permitido elementos repetidos
- será necessário identificar entre quais elementos o novo elemento será inserido;
- o novo elemento será inserido no lugar do primeiro que estiver na lista de disponíveis
*/
int obterDisponivel(LISTA* li) {
    int resultado = li->dispo;
    if(li->dispo != INVALIDO)
        li->dispo = li->A[li->dispo].prox;
    return resultado;
}

bool inserirElemListaOrd (LISTA* li, REGISTRO reg){
    if(li->dispo == INVALIDO) return false;
    int ant = INVALIDO, i = li->inicio;
    TIPOCHAVE chave = reg.chave;
    while ((i != INVALIDO) && (li->A[i].reg.chave < chave)) {
        ant = i;
        i = li->A[i].prox;
    }
    if(i != INVALIDO && li->A[i].reg.chave == chave) return false;
    i = obterDisponivel (li);
    li->A[i].reg = reg;
    if(ant == INVALIDO){
        li->A[i].prox = li->inicio;
        li->inicio = i;
    } else {
        li->A[i].prox = li->A[ant].prox;
        li->A[ant].prox = i;
    }
    return true;
}

/*
EXCLUSÃO DE UM ELEMENTO 

O usuário passa a chave do elemento que ele quer excluir 
Se houver um elemento com esta chave na lista, "exclui este elemento" da lista de elementos válidos e o insere na lista de disponíveis 
Adicionalmente, acerte os ponteiros envolvidos e retorna true
Caso contrário, retorna false
*/

void devolverNo (LISTA* li, int j){
    li->A[j].prox = li->dispo;
    li->dispo = j;
}

bool excluirElemento (LISTA* li, TIPOCHAVE chave){
    int ant = INVALIDO;
    int i = li->inicio;
    while ((i != INVALIDO) && (li->A[i].reg.chave < chave)){
        ant = i;
        i = li->A[i].prox;
    }
    if (i == INVALIDO || li->A[i].reg.chave != chave) return false;
    if (ant == INVALIDO) li->inicio = li->A[i].prox;
    else li->A[ant].prox = li->A[i].prox;
    devolverNo(li, i);
    return true;
}

//Reinicialização da lista
void reinicializarLista (LISTA* li){
    iniciaizar_lista(li);
}