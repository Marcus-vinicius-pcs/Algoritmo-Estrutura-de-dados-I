/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2021                           **/
/**   <turma> - Prof. Luciano Antonio Digiampietri                  **/
/**                                                                 **/
/**   EP 2 - Fila Preferencial                                      **/
/**                                                                 **/
/**   <nome do(a) aluno(a)>                   <numero USP>          **/
/**                                                                 **/
/*********************************************************************/

#include "filapreferencial.h"

PFILA criarFila(){
    PFILA res = (PFILA) malloc(sizeof(FILAPREFERENCIAL));
    res->cabeca = (PONT) malloc(sizeof(ELEMENTO));
    res->inicioNaoPref = res->cabeca;
    res->cabeca->id = -1;
    res->cabeca->ehPreferencial = false;
    res->cabeca->ant = res->cabeca;
    res->cabeca->prox = res->cabeca;
    return res;
}

int tamanho(PFILA f){
	PONT atual = f->cabeca->prox;
	int tam = 0;
	while (atual != f->cabeca) {
		atual = atual->prox;
		tam++;
	}
	return tam;
}

PONT buscarID(PFILA f, int id){
	PONT atual = f->cabeca->prox;
	while (atual != f->cabeca) {
		if (atual->id == id) return atual;
		atual = atual->prox;
	}
	return NULL;
}

void exibirLog(PFILA f){
	int numElementos = tamanho(f);
	printf("\nLog fila [elementos: %i]\t- Inicio:", numElementos);
	PONT atual = f->cabeca->prox;
	while (atual != f->cabeca) {
		printf(" [%i;%i]", atual->id, atual->ehPreferencial);
		atual = atual->prox;
	}
	printf("\n                       \t-    Fim:");
	atual = f->cabeca->ant;
	while (atual != f->cabeca) {
		printf(" [%i;%i]", atual->id, atual->ehPreferencial);
		atual = atual->ant;
	}
	printf("\n\n");
}


bool consultarPreferencial(PFILA f, int id){
	PONT atual = f->cabeca->prox;
	while (atual != f->cabeca) {
		if (atual->id == id) return atual->ehPreferencial;
		atual = atual->prox;
	}
	return -1;
}

void insereFilaVazia(PFILA f, PONT el){
	if(!el->ehPreferencial) f->inicioNaoPref = el;
	el->prox = f->cabeca;
	el->ant = f->cabeca;
	f->cabeca->prox = el;
	f->cabeca->ant = el;
}

void inserePreferencial(PFILA f, PONT el){
	PONT atual = f->cabeca;
	if(f->inicioNaoPref!=f->cabeca){
		while(atual->prox != f->inicioNaoPref)
			atual = atual->prox;
		el->ant = atual;
		el->prox = f->inicioNaoPref;
		atual->prox = el;
		f->inicioNaoPref->ant = el;
	} else {
		while(atual->prox != f->cabeca)
			atual = atual->prox;
		el->ant = atual;
		el->prox = f->cabeca;
		atual->prox = el;
		f->cabeca->ant = el;
	}
}

void insereNaoPreferencial(PFILA f, PONT el){
	PONT atual = f->inicioNaoPref;
	while(atual->prox != f->cabeca)
		atual = atual->prox;
	el->ant = atual;
	el->prox = f->cabeca;
	atual->prox = el;
	f->cabeca->ant = el;
}

bool inserirPessoaNaFila(PFILA f, int id, bool ehPreferencial){
	if((id < 0) || buscarID(f, id)!=NULL) return false;
	PONT novo = (PONT) malloc(sizeof(ELEMENTO));
	novo->id = id;
	novo->ehPreferencial = ehPreferencial;
	int tam = tamanho(f);
	/*
	Caso 1: Fila esta vazia
	Caso 2: Fila contém apenas pessoas não preferenciais 
			- É preferencial --> será o primeiro da fila 
			- Não é preferencial --> será o último
	Caso 3: Fila contém apenas pessoas preferenciais
			- É preferencial --> será o último da fila 
			- Não é preferencial --> será o último da fila
	Caso 4: Fila contém preferenciais e não preferenciais
			- É preferencial --> será o último dos preferenciais
			-Não é preferencial --> será o último da fila 
	*/
//Caso 1 
	if(tam == 0) insereFilaVazia(f, novo);
	else {
		if(!ehPreferencial) insereNaoPreferencial(f, novo);
		else inserePreferencial(f, novo);
	}
	return true;
}

bool atenderPrimeiraDaFila(PFILA f, int* id){

	/* COMPLETE */


	return false;
}


bool desistirDaFila(PFILA f, int id){

	/* COMPLETE */


	return false;
}
