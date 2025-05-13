//Inversão.  Suponha que um vetor v[1..n] contém uma permutação de 1..n. Escreva uma função que inver//ta essa permutação:  se v[i] == j no vetor original, queremos ter v[j] == i no fim da execução da //função.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverter(int *v, int N){
  int t[N];

  memcpy(t, v, N* sizeof(int));


  for(int i = 0; i < N; i++){
	v[t[i]] = i;
  }
}

int main(int argc, char* argv[]){
  int N;
  int v[N];

  scanf("%d", &N);
  
  for(int i = 0; i < N; i++){
	int x;
	scanf("%d", &x);
	v[i] = x;
  }

  inverter(v, N);


  for(int i = 0; i < N; i++){
	printf("%d ", v[i]);
  }

  printf("\n");
  return 0;
}
