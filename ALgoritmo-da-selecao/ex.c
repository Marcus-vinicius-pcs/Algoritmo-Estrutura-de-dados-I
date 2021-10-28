#include <stdio.h>

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
	return A[i];
}

int main(){
    int A[6] = {1,4,7,54,3,0,9}; //n=7
    for (int i=0; i<7; i++)
        printf("%i ", A[i]);
    print("\n\n");
    QuickSort(A, 7);
    for (int i=0; i<7; i++)
        printf("%i ", A[i]);
    print("\n\n");
    return 0;
}