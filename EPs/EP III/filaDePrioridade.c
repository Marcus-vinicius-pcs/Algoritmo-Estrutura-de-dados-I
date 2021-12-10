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
  return f->elementosNoHeap;
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
    printf("dir\n");
}

int pai(PFILA f, PONT atual){
    return (atual->posicao - 1)/2;
}

void swapStruct(PONT a, PONT b){
  ELEMENTO temp;
  temp.id = a->id;
  temp.posicao = a->posicao;
  temp.prioridade = a->prioridade;
  a->id = b->id;
  a->posicao = b->posicao;
  a->prioridade = b->prioridade;
  b->id = temp.id;
  b->posicao = temp.posicao;
  b->prioridade = temp.prioridade;
}

void refazHeapMaximo(PFILA f, PONT atual){
    int p = pai(f, atual);
    if(f->heap[p]->prioridade > 0){
      if(f->heap[atual->posicao]->prioridade > f->heap[p]->prioridade){
        swapStruct(f->heap[p], f->heap[atual->posicao]);
        refazHeapMaximo(f, atual);
      }
    }
}

bool inserirElemento(PFILA f, int id, float prioridade){
  if((id >= MAX) || (id < 0)) return false;
  if(buscaId(f, id)) return false;
  PONT novo = (PONT) malloc(sizeof(ELEMENTO));
  novo->id = id;
  novo->prioridade = prioridade;
  novo->posicao = f->elementosNoHeap;
  f->heap[novo->posicao] = novo;
  f->referencias[MAX-f->elementosNoHeap] = novo;
  refazHeapMaximo(f, f->heap[novo->posicao]);
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
