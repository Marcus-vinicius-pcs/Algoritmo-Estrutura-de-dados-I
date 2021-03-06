/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2021                           **/
/**   <294> - Prof. Luciano Antonio Digiampietri                    **/
/**                                                                 **/
/**   EP 1 - Lista Ligada de Produtos                               **/
/**                                                                 **/
/**   <Marcus Vinicius Pizzo Cognolatto Santos>        <12543478>   **/
/**                                                                 **/
/*********************************************************************/
#include "listadeprodutos.h"

PLISTA criarLista(){
  PLISTA res = (PLISTA) malloc(sizeof(LISTADEPRODUTOS));
  int x;
  for (x=0;x<NUMTIPOS;x++){
    res->LISTADELISTAS[x]=(PONT) malloc(sizeof(REGISTRO));
    res->LISTADELISTAS[x]->id=-1;
    res->LISTADELISTAS[x]->quantidade=0;
    res->LISTADELISTAS[x]->valorUnitario=0;
    res->LISTADELISTAS[x]->proxProd=NULL;
  }
  return res;
}


int tamanho(PLISTA l){
  int tam = 0;
  int x;
  PONT atual;
  for (x=0;x<NUMTIPOS;x++){
    atual = l->LISTADELISTAS[x]->proxProd;
    while (atual) {
      atual = atual->proxProd;
      tam++;
    }
  }
  return tam;
}

PONT buscarID(PLISTA l, int id){
  int x;
  PONT atual;
  for (x=0;x<NUMTIPOS;x++){
    atual = l->LISTADELISTAS[x]->proxProd;
    while (atual) {
      if (atual->id == id) return atual;
      atual = atual->proxProd;
    }
  }
  return NULL;
}

PONT buscarIDTipo(PLISTA l, int id, int tipo){
  if (tipo<0 || tipo>=NUMTIPOS) return NULL;
  PONT atual = l->LISTADELISTAS[tipo]->proxProd;
  while (atual) {
    if (atual->id == id) return atual;
    atual = atual->proxProd;
  }
  return NULL;
}

void exibirLog(PLISTA f){
  int numElementos = tamanho(f);
  printf("Log lista [elementos: %i]\n", numElementos);
  int x;
  PONT atual;
  for (x=0;x<NUMTIPOS;x++){
    printf("  #TIPO: %i -> ", x);
    atual = f->LISTADELISTAS[x]->proxProd;
    while (atual){
      printf(" [%i;%i;%i;$%i]", atual->id, atual->quantidade, atual->valorUnitario, atual->quantidade*atual->valorUnitario);
      atual = atual->proxProd;
    }
    printf("\n");
  }
  printf("\n");
}

int consultarValorUnitario(PLISTA l, int id){
  int x;
  PONT atual;
  for (x=0;x<NUMTIPOS;x++){
    atual = l->LISTADELISTAS[x]->proxProd;
    while (atual) {
      if (atual->id == id) return atual->valorUnitario;
      atual = atual->proxProd;
    }
  }
  return 0;
}
// RETORNAR O TIPO DE UM PRODUTO COM BASE NO SEU ID
int retornarTipo(PLISTA l, int id){
    int x;
    PONT atual;
    for(x=0; x<NUMTIPOS; x++){
        atual = l->LISTADELISTAS[x]->proxProd;
    while (atual) {
      if (atual->id == id) return x;
      atual = atual->proxProd;
    }
    }
}

int retornaValorTotal(PLISTA l, int id){
  int tipo = retornarTipo(l, id);
  int valorTotal;
  PONT atual = buscarID(l, id);
  if(atual != NULL)
    valorTotal = atual->quantidade * atual->valorUnitario;
  return valorTotal;
}

PONT buscaAnt(PLISTA l, int valorTotal, PONT* ant, int tipo, int id){
    *ant = l->LISTADELISTAS[tipo];
    PONT atual = l->LISTADELISTAS[tipo]->proxProd;
    while ((atual!=NULL) && (atual->quantidade*atual->valorUnitario < valorTotal))
    {
        *ant = atual;
        atual = atual->proxProd;
    } 
    if((atual!=NULL) && (atual->id == id)) return atual;
    return NULL;
}


bool inserirNovoProduto(PLISTA l, int id, int tipo, int quantidade, int valor){
  if((id < 0) || (quantidade < 0) || (valor < 0) || (tipo < 0) || (tipo >= NUMTIPOS)) return false;
  PONT novo, ant;
  novo = buscaAnt(l, quantidade*valor, &ant, tipo, id);
  if(novo != NULL) return false;
  novo = (PONT) malloc(sizeof(REGISTRO));
  novo->id = id;
  novo->quantidade = quantidade;
  novo->valorUnitario = valor;
  novo->proxProd = ant->proxProd;
  ant->proxProd = novo;
  return true;
}

void passarDados(PONT i, PONT j){
  REGISTRO aux;
  aux.id = i->id;
  aux.quantidade = i->quantidade;
  aux.valorUnitario = i->valorUnitario;
  i->id = j->id;
  i->quantidade = j->quantidade;
  i->valorUnitario = j->valorUnitario;
  j->id = aux.id;
  j->quantidade = aux.quantidade;
  j->valorUnitario = aux.valorUnitario;
}

void reorganizarLista(PLISTA l, int tipo){
  PONT i = l->LISTADELISTAS[tipo];
  while(i){
    PONT posicaoMenor = i;
    PONT aux = i->proxProd;
    while(aux){
      if(posicaoMenor->quantidade*posicaoMenor->valorUnitario > aux->valorUnitario*aux->quantidade) 
        posicaoMenor = aux;
      aux = aux->proxProd;
    }
  passarDados(i, posicaoMenor);
  i = i->proxProd;
  }
}

bool removerItensDeUmProduto(PLISTA l, int id, int quantidade){
   if((id < 0) || (quantidade <= 0)) return false;
   PONT ant, i, aux;
   int tipo = retornarTipo(l, id);
   int valorTotal = retornaValorTotal(l, id);
   i = buscarID(l, id);
   buscaAnt(l, valorTotal, &ant, tipo, id);
   if((i == NULL) || (quantidade > i->quantidade)) return false;
   i->quantidade = i->quantidade - quantidade;
   if(i->quantidade == 0){
     ant->proxProd = i->proxProd;
     free(i);
   } 
   else {
     reorganizarLista(l, tipo);
   }
   return true;
}


bool atualizarValorDoProduto(PLISTA l, int id, int valor){
  PONT i = buscarID(l, id);
  int tipo = retornarTipo(l, id);
  if((i == NULL) || (valor<=0)) return false;
  i->valorUnitario = valor;
  reorganizarLista(l, tipo);
  return true;
}