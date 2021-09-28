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



bool inserirPessoaNaFila(PFILA f, int id, bool ehPreferencial){
	if((id < 0) || buscarID(f, id)!=NULL) return false;
	PONT novo = (PONT) malloc(sizeof(ELEMENTO));
	novo->id = id;
	novo->ehPreferencial = ehPreferencial;
	int tam = tamanho(f);
	if(tam == 0){
		f->cabeca->prox = novo;
		novo->ant = f->cabeca;
		novo->prox = f->cabeca;
		if(!(ehPreferencial)) f->inicioNaoPref = novo;
	} else {
		if(f->inicioNaoPref == f->cabeca){
			if(ehPreferencial){
				novo->prox = f->cabeca->prox;
				f->cabeca->prox->ant = novo;
				novo->ant = f->cabeca;
				f->cabeca->prox = novo;
				f->inicioNaoPref = novo->prox;
			} else {
				novo->prox = f->cabeca;
				f->cabeca->prox->prox = novo;
				novo->ant = f->cabeca->prox;
			}
		}
		
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
