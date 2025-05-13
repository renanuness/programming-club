#include <stdio.h>
#include <stdlib.h>

int main(){
  char *x;
  x = malloc(sizeof(char)*4);
  while(1){
    int n = scanf("%s", x);
    if(n == EOF)
      break;

    if(x[2] == 'L'){
      printf("Esse eh o meu lugar\n");
    }else{
      printf("Oi, Leonard\n");
    }
  }

  return 0;
}
