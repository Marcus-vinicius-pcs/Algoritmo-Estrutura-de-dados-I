#include <stdio.h>
#include <stdlib.h>

/*EXERCICIO 1
Escreva os comandos que definem uma estrutura (struct) chamada PESSOA que
possui trˆes campos: id do tipo inteiro; mae do tipo referˆencia para PESSOA; e
pai do tipo referˆencia para PESSOA.
*/

typedef struct aux {
    int id;
    struct aux* mae;
    struct aux* pai;
} PESSOA;

/*EXERCICIO 2
Implemente uma fun¸c˜ao para a inicializa¸c˜ao da estrutura do tipo PESSOA
(definida na quest˜ao anterior). A assinatura ´e apresenta a seguir. A fun¸c˜ao ter´a
um parˆametro de entrada chamado id do tipo inteiro e dever´a: alocar mem´oria
para uma PESSOA e preencher seus campos da seguinte forma: o campo id
dever´a receber o valor do parˆametro id; os campos mae e pai dever˜ao receber o
valor NULL. Por fim, a fun¸c˜ao dever´a retornar o endere¸co da mem´oria que foi
alocada para essa PESSOA.
PESSOA* inicializar(int id)
*/

PESSOA* inicializar(int id){
    PESSOA* nova_pessoa = (PESSOA*) malloc(sizeof(PESSOA));
    nova_pessoa->id = id;
    nova_pessoa->mae = NULL;
    nova_pessoa->pai = NULL;
    return nova_pessoa;
}

/*EXERCICIO 3
Implemente uma fun¸c˜ao que recebe como parˆametros os endere¸cos de mem´oria
(referˆencias) de trˆes PESSOAS (filho, mae e pai) e atribui o valor do parˆametro
mae no campo mae da PESSOA referenciada pelo parˆametro filho e atribui o
valor do parˆametro pai no campo pai da PESSOA referenciada pelo parˆametro
filho. A assinatura dessa fun¸c˜ao ´e apresentada a seguir:
void registrar(PESSOA* filho, PESSOA* mae, PESSOA* pai)
*/

void registrar(PESSOA* filho, PESSOA* mae, PESSOA* pai){
    filho->mae = mae;
    filho->pai = pai;
}

int main(){
  PESSOA* m = inicializar(1);   
  PESSOA* p = inicializar(2);
  PESSOA* f = inicializar(3);

  registrar(f, m, p);
  
  printf("%p %p %p\n", f, f->mae, f->pai);    

  return 0;
}