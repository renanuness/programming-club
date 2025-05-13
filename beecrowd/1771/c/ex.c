#include <stdio.h>
#include <stdlib.h>

int main(){


  while(1){
	int colunaCount[5] = {0};
	int isOk = 1;
	for(int i = 0; i < 25; i++){
	  int x;
	  int r;
	  if(i == 12){
		x = 37;
	  }else{
		r = scanf("%d", &x);
		if(r == EOF){
		  return 0;
		}
	  }

	  
	  int col = i%5;// i=0 col = 0; i=5 col = 0

	  int limiteInferior = 15 * col;
	  int limiteSuperior = 15 + (15*col);

	  if(x > limiteSuperior || x <= limiteInferior){
		isOk = 0;
	  }

	  int resto = x % 15;
	  int divisao = x /15; // a divisão indica em qual grupo o número deveria ir
	  if(resto == 0) divisao--;

	  colunaCount[divisao]++;

	}

	int isReciclavel = 1;
	for(int i = 0; i < 5; i++){
	  if(colunaCount[i] != 5){
		isReciclavel = 0;
		break;
	  }
	}

	if(isOk == 1){
	  printf("OK\n");
	}else if (isReciclavel == 1){
	  printf("RECICLAVEL\n");
	}else{
	  printf("DESCARTAVEL\n");
	}
  }


  return 0;
}
