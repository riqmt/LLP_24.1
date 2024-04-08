#include <stdio.h>

int main(void) {
   
  int x ;
  printf(" digite a pontuação do jogador:\n");

  
  
  scanf("%d",&x);
  printf( "Resultado:\n");
  //scanf("%d",'&x');
  
  
  if( x>=0 && x<=10) {
  printf("insuficiente \n");
  }
  
  if(x>=11 && x<=40) {
  printf(" regular\n");
  }
  
  if (x>=41 && x<=70) {
  printf("bom\n");
  }
  
  if(x>=71 && x<=90) {
  printf("otimo\n");
  }
  
  if(x>=91 && x<=100) {
  printf("excelente\n");
  }

  return 0; 
}
