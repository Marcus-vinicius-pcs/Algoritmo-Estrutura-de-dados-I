#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Particao(int A[], int n){
    int pivo = A[n-1];
    int i = -1;
    int j, aux;
    for(j=0; j<n-1; j++){
        if(A[j]<=pivo){
            i = i+1;
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
        
    }
	aux = A[j];
    A[j] = A[i+1];
    A[i+1] = aux;
    return i+1;
}

void QuickSort(int A[], int n){
    int q;
    if(n > 0){
        q = Particao(A, n);
        QuickSort(A, q);
        QuickSort(&A[q+1], n-(q+1));
    }
}

int Selecao1(int A[], int i, int n){
	QuickSort(A, n);
	return A[i-1];
}

int Selecao2(int A[], int i, int n){
    int q = Particao(A, n);
    if(n == 1)
        return A[i-1];
    if(i < q){
        return Selecao2(A, i, q-1);
    } else if (i > q) {
        return Selecao2(&A[q+1], i-(q+1), n);
    }
    return A[q-1];
}
int cmp(const void *a,const void *b) {
  int* x = (int*) a;
  int* y = (int*) b;

  return *x - *y;
}

int main() {
    
  
  int size = 9 * 10000;

  int* array = (int*) malloc(sizeof(int)*size);

  srand(time(NULL));

  for(int i = 0; i < size; i++)
    array[i] = rand();


    time_t seconds, seconds2;
    
   // seconds = time(NULL);
   // int num = Selecao1(array, 3, size);
    //seconds2 = time(NULL);
   // printf("%d \n\n", ((int)seconds2-(int)seconds));
   // printf("%i ",num);
    
    QuickSort(array, size);

    seconds = time(NULL);
    int nber = Selecao2(array, 3, size);
    seconds2 = time(NULL);
    printf("%d \n\n", ((int)seconds2-(int)seconds));
    printf("%i ", nber);
    return 0;
}
