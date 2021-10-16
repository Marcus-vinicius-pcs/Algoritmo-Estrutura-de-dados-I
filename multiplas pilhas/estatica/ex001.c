#include <stdio.h>
#define true 1
#define false 0 
#define ERRO -1
#define MAX 8
#define NP 4

typedef int TIPOCHAVE;

typedef int bool;

typedef struct {
    TIPOCHAVE A[MAX];
    int base[NP+1];
    int topo[NP+1];
} PILHAMULTIPLA;

void inicializar(PILHAMULTIPLA* p){
    int i;
    for(i = 0; i <= NP; i++){
        p->base[i] = (i * (MAX / NP));
        p->topo[i] = p->base[i] - i;
    }
}

int tamanhoPilha(PILHAMULTIPLA* p, int k){
    if(k<0 || k>=NP) return ERRO;
    return p->topo[k] - p->base[k] + 1;
}

int tamanhoTotalPilhas(PILHAMULTIPLA* p){
    int tamanho = 0;
    int i;
    for(i=0;i<NP;i++) tamanho += tamanhoPilha(p, i);
    return tamanho;
}

bool pilhaKcheia(PILHAMULTIPLA* p, int k){
    if(p->topo[k] == p->base[k + 1] - 1) return true;
    else return false;
}

bool excluirElemento(PILHAMULTIPLA* p, TIPOCHAVE* ch, int k){
    if(k<0 || k>=NP) return false;
    if(p->topo[k] >= p->base[k]) {
        *ch = p->A[p->topo[k]];
        p->topo[k]--;
        return true;
    }
    return false;
}

bool paraDireita(PILHAMULTIPLA* p, int k){
    if(k < 1 ||(k > NP-1)) return false;
    int i;
    if(p->topo[k] < p->base[k+1] - 1){
        for(i = p->topo[k]; i >= p->base[k]; i--)
            p->A[i+1] = p->A[i];
        p->topo[k]++;
        p->base[k]++;
        return true;
    }
    return false;
}

bool paraEsquerda(PILHAMULTIPLA* p, int k){
    if(k < 1 ||(k > NP-1)) return false;
    int i;
    if(p->topo[k-1] < p->base[k] - 1){
        for(i = p->base[k]; i <= p->topo[k]; i++)
            p->A[i-1] = p->A[i];
        p->topo[k]--;
        p->base[k]--;
        return true;
    }
    return false;
}

bool pushK(TIPOCHAVE ch, PILHAMULTIPLA* p, int k){
    if(k < 0 || k >= NP) return false;
    int j;
    if(pilhaKcheia(p, k)) {
        for(j = NP-1; j > k; j--) paraDireita(p, j);
        if(pilhaKcheia(p, k)){
            for(j = 1; j<= k; j++) paraEsquerda(p, j);
            if(pilhaKcheia(p, k)) return false;
        }
    }
    p->topo[k]++;
    p->A[p->topo[k]] = ch;
    return true;
}