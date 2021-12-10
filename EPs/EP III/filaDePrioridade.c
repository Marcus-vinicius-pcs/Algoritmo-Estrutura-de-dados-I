/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2021                           **/
/**   <294> - Prof. Luciano Antonio Digiampietri                    **/
/**                                                                 **/
/**   EP3 - Fila de Prioridade (utilizando heap)                    **/
/**                                                                 **/
/**   <Marcus Vinicius Pizzo Cognolatto Santos>      <12543478>     **/
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
int esq(PFILA f, PONT atual){
    return 2*atual->posicao + 1;
}

int dir(PFILA f, PONT atual){
    return 2*atual->posicao + 2;
}

int pai(PFILA f, PONT atual){
    return (atual->posicao - 1)/2;
}

void refazHeapMaximo(PFILA f, PONT atual){
    int tam = tamanho(f);
    int max = atual->posicao;
    int l = esq(f, atual);
    int r = dir(f, atual);
    if((f->heap[l]->prioridade > f->heap[max]->prioridade) && (l < tam))
      max = l;
    if((f->heap[r]->prioridade > f->heap[max]->prioridade) && (r < tam))
      max = r;
    if(max != atual){
      PONT swap = f->heap[atual->posicao];
      f->heap[atual->posicao] = f->heap[max];
      f->heap[max] = swap;
    }
    refazHeapMaximo(f, max);
}

bool inserirElemento(PFILA f, int id, float prioridade){
  if((id >= MAX) || (id < 0)) return false;
  if(buscaId(f, id)) return false;
  int tam = tamanho(f);
  PONT novo = (PONT) malloc(sizeof(ELEMENTO));
  novo->id = id;
  novo->prioridade = prioridade;
  if(f->elementosNoHeap == 0){
      novo->posicao = 0;
      f->heap[0] = novo;
      f->referencias[MAX-2] = novo;
  } else {
      f->heap[tam] = novo;
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
