#include <stdio.h>
#include <malloc.h>

#define FALSE 0
#define TRUE 1

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
    //outros campos ...
} REGISTRO;

typedef struct tempResgistro {
    REGISTRO reg;
    struct temResgistro* prox;
} ELEMENTO;

typedef ELEMENTO* PONT; 

typedef struct {
    PONT cabeca;
} LISTA;

//INICIALIZAR LISTA 
void inicializarLista(LISTA* li){
    li->cabeca = (PONT) malloc(sizeof(ELEMENTO));
    li->cabeca->prox = li->cabeca;
}

//RETORNAR O NUMERO DE ELEMENTOS 
int tamanhoLista(LISTA* li){
    PONT i = li->cabeca->prox;
    int tam = 0;
    while (i != li->cabeca)
    {
        tam++;
        i = i->prox;
    }
    return tam;
}

//IMPRIMIR ELEMENTOS DA LISTA
void imprimirElementos(LISTA* li){
    PONT i = li->cabeca->prox;
    printf("Lista: \" ");
    while (i != li->cabeca){
        printf("%i ", i->reg.chave);
        i = i->prox;
    } 
    printf(" \"");
}

//BUSCAR POR UM ELEMENTO 
PONT buscaSentinela(LISTA* li, TIPOCHAVE chave){
    PONT pos = li->cabeca;
    li->cabeca->reg.chave = chave; //a cabeça da lista é usada como sentinela
    while (pos->reg.chave != chave) pos = pos->prox;
    if(pos != li->cabeca) return pos;
    return NULL;
}

//BUSCA SEQUENCIAL EM LISTAS ORDENADAS
PONT buscaSentinelaOrd(LISTA* li, TIPOCHAVE chave){
    PONT pos = li->cabeca;
    li->cabeca->reg.chave = chave;
    while(pos->reg.chave < chave) pos = pos->prox;
    if(pos != li->cabeca && pos->reg.chave == chave) return pos;
    return NULL;
}

//BUSCA AUXILIAR
PONT buscaSeqExc(LISTA* li, TIPOCHAVE chave, PONT* ant){
    *ant = li->cabeca;
    PONT atual = li->cabeca->prox;
    while (atual->reg.chave < chave)
    {
        *ant = atual;
        atual = atual->prox;
    }
    if(atual != li->cabeca && atual->reg.chave == chave) return atual;
    return NULL;
}

//INSERÇÃO DE UM ELEMENTO 
bool inserirElemento(LISTA* li, REGISTRO reg){
    PONT ant, i;
    i = buscaSeqExc(li, reg.chave, &ant);
    if(i != NULL) return FALSE;
    i = (PONT) malloc(sizeof(ELEMENTO));
    i->reg = reg;
    i->prox = ant->prox;
    ant->prox = i;
    return TRUE;
}

//EXCLUIR ELEMENTO
bool excluiElemento(LISTA* li, TIPOCHAVE chave){
    PONT ant, i;
    i = buscaSeqExc(li, chave, &ant);
    if(i == NULL) return FALSE;
    ant->prox = i->prox;
    free(i);
    return TRUE;
}

//REINICIALIZAR LISTA 
void reinicializa(LISTA* li){
    PONT i = li->cabeca->prox;
    while(i != li->cabeca) {
        PONT apagar = i;
        i = i->prox;
        free(apagar);
    }
    li->cabeca->prox = li->cabeca;
}

