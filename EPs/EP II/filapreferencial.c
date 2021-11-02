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
	if(tam == 0) insereFilaVazia(f, novo);
	else {
		if(!ehPreferencial) insereNaoPreferencial(f, novo);
		else inserePreferencial(f, novo);
	}
	return true;
}


void atendeFilaComUma(PFILA f){
	f->cabeca->ant = f->cabeca;
	f->cabeca->prox = f->cabeca;
}

void atendePreferencial(PFILA f){
	f->cabeca->prox->prox->ant = f->cabeca;
	f->cabeca->prox = f->cabeca->prox->prox;
}

void atendeNaoPreferencial(PFILA f){
	f->cabeca->prox = f->inicioNaoPref->prox;
	f->inicioNaoPref->prox->ant = f->cabeca->prox;
}

void atendeNormal(PFILA f){
	f->cabeca->prox->prox->ant= f->cabeca;
	f->cabeca->prox = f->cabeca->prox->prox;
}

bool atenderPrimeiraDaFila(PFILA f, int* id){
	if(tamanho(f) == 0) return false;
	PONT el = f->cabeca->prox;
	*id = el->id;
	if(tamanho(f) == 1){
		if(f->inicioNaoPref == el)
			f->inicioNaoPref = f->cabeca;
		atendeFilaComUma(f);
	}
	if(f->inicioNaoPref == f->cabeca)
		atendePreferencial(f);
	if((f->inicioNaoPref != f->cabeca) && (f->inicioNaoPref != el))
		atendeNaoPreferencial(f);
	atendeNormal(f);
	return true;
}

bool desistirDaFila(PFILA f, int id){

	/* COMPLETE */


	return false;
}

	/*if(tamanho(f) == 1){
		f->cabeca->prox = f->cabeca;
		f->cabeca->ant = f->cabeca;
		f->inicioNaoPref = f->cabeca;
	} else {
	if(!el->ehPreferencial){
		f->inicioNaoPref = el->prox;
		f->cabeca->prox = f->inicioNaoPref;
		f->inicioNaoPref->ant = f->cabeca;
	}
	f->cabeca->prox = el->prox;
	el->prox->ant = f->cabeca;
	}
	free(el);*/