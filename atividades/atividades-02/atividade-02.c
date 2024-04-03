#include <stdio.h>

int main() {
  //Faça um programa usando a linguagem C que realiza a seguinte tarefa:
//1) Use uma estrutura de repetição para mostrar na saída números inteiros pares entre 1 e 50.

  int n;

  for (n = 2; n <= 50; n++) {
    int rest = n %2;
    if (rest == 0) {
      printf("%d\n", n);
    }
    
  }
  return 0;
}

