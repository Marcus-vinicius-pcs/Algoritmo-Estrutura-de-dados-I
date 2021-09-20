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

typedef struct auxElem{
    REGISTRO reg;
    struct auxElem* ant;
    struct auxElem* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT cabeça;
} DEQUE;

//INICIALIZAÇÃO DO DEQUE
void inicializar(DEQUE* d){
    PONT no = (PONT) malloc(sizeof(ELEMENTO));
    d->cabeça = no;
    no->prox = no;
    no->ant = no;
}

//RETORNAR NUMERO DE ELEMENTOS 
int tamanho(DEQUE* d){
    PONT aux = d->cabeça->prox;
    int tam = 0;
    while(aux!=d->cabeça){
        tam++;
        aux = aux->prox;
    }
    return tam;
}

//IMPRIMIR ELEMENTOS
void imprimir(DEQUE* d){
    PONT aux = d->cabeça->prox;
    while(aux!=d->cabeça){
        print("%i ", aux->reg.chave);
        aux = aux->prox;
    }
}

void exibirFim(DEQUE* d){
    PONT aux = d->cabeça->ant;
    while(aux!=d->cabeça){
        printf("%i ", aux->reg.chave);
        aux = aux->ant;
    }
}

//INSERIR ELEMENTOS 
bool inserirElementosNoFim(DEQUE* d, REGISTRO reg){
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = d->cabeça;
    novo->ant = d->cabeça->ant;
    d->cabeça->ant = novo;
    novo->ant->prox = novo;
    return true;
}

//EXCLUSÃO DE ELEMENTO 
bool excluirElementoNoInicio(DEQUE* d, REGISTRO* reg){
    if(d->cabeça->prox == d->cabeça) return false;
    PONT apagar = d->cabeça->prox;
    *reg = apagar->reg;
    d->cabeça->prox = apagar->prox;
    apagar->prox->ant = d->cabeça;
    free(apagar);
    return true;
}

//REINICIALIZAÇÃO DO DEQUE
void reinicializar(DEQUE* d){
    PONT end = d->cabeça->prox;
    while(end!=d->cabeça){
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    d->cabeça->prox = d->cabeça;
    d->cabeça->ant = d->cabeça;
}
