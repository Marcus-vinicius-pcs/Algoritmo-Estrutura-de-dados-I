/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2021                           **/
/**   <turma> - Prof. Luciano Antonio Digiampietri                  **/
/**                                                                 **/
/**   EP3 - Fila de Prioridade (utilizando heap)                    **/
/**                                                                 **/
/**   <nome do(a) aluno(a)>                   <numero USP>          **/
/**                                                                 **/
/*********************************************************************/

#include "filaDePrioridade.h"
#define MAX 5

PFILA criarFila(){
  PFILA res = (PFILA) malloc(sizeof(FILADEPRIORIDADE));
  res->referencias = (PONT*) malloc(sizeof(PONT)*MAX);
  res->heap = (PONT*) malloc(sizeof(PONT)*MAX);
  int i;
  for (i=0;i<MAX;i++) {
    res->referencias[i] = NULL;
    res->heap[i] = NULL;
  }
  res->elementosNoHeap = 0;
  return res;
}


bool exibirLog(PFILA f){
  printf("Log [elementos: %i]\n", f->elementosNoHeap);
  PONT atual;
  int i;
  for (i=0;i<f->elementosNoHeap;i++){
    atual = f->heap[i];
    printf("[%i;%f;%i] ", atual->id, atual->prioridade, atual->posicao);
  }
  printf("\n\n");
}

int tamanho(PFILA f){
  int tam = 0;
  
  tam = f->elementosNoHeap;
  
  return tam;
}

bool buscaId(PFILA f, int id){
    PONT atual;
    int i;
    for(i=0; i<f->elementosNoHeap; i++){
        if(id == f->heap[i]->id)
            return true;
    }
    return false;
}
PONT esq(PFILA f, PONT atual){
    return f->heap[2*atual->posicao];
}

PONT dir(PFILA f, PONT atual){
    return f->heap[2*atual->posicao - 1];
}

PONT pai(PFILA f, PONT atual){
    return f->heap[atual->posicao/2];
}

void passaDados(PONT i, PONT j){
    PONT aux;
    aux->id = i->id;
    aux->prioridade = i->prioridade;
    aux->posicao = i->posicao;
    i->id = j->id;
    i->prioridade = j->prioridade;
    i->posicao = j->posicao;
    j->id = aux->id;
    j->prioridade = aux->prioridade;
    j->posicao = i->posicao;
}

void refazHeapMaximo(PFILA f, PONT atual){
    PONT l = esq(f, atual);
    PONT r = dir(f, atual);
    PONT maior = atual;
    if((l <= tamanho(f)) && (l->prioridade > maior->prioridade))
        maior = l;
    if((r <= tamanho(f)) && (r->prioridade > maior->prioridade))
        maior = r;
    if(maior != atual){
        passaDados(atual, maior);
    }
    refazHeapMaximo(f, maior);
}

bool inserirElemento(PFILA f, int id, float prioridade){
  if((id >= MAX) || (id < 0)) return false;
  if(buscaId(f, id)) return false;
  PONT novo = (PONT) malloc(sizeof(ELEMENTO));
  novo->id = id;
  novo->prioridade = prioridade;
  if(f->elementosNoHeap == 0){
      novo->posicao = 0;
      f->heap[0] = novo;
      f->referencias[MAX-2] = novo;
  } else {
      refazHeapMaximo(f, novo);
  }
  f->elementosNoHeap++;
  return true;
}

bool aumentarPrioridade(PFILA f, int id, float novaPrioridade){
  bool res = false;
  
  /* COMPLETAR */
  
  return res;
}

bool reduzirPrioridade(PFILA f, int id, float novaPrioridade){
  bool res = false;
  
  /* COMPLETAR */
  
  return res;
}

PONT removerElemento(PFILA f){
  PONT res = NULL;
  
  /* COMPLETAR */
  
  return res;
}

bool consultarPrioridade(PFILA f, int id, float* resposta){
  bool res = false;
  
  /* COMPLETAR */
  
  return res;
}
