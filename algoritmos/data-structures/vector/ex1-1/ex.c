//[Sedgewick 3.11]  Diga (sem usar o computador) qual o conteúdo do vetor  v  depois das seguintes instruções:
//int v[99];
//for (i = 0; i < 99; ++i) v[i] = 98 - i;
//for (i = 0; i < 99; ++i) v[i] = v[v[i]];

//R.
// O valor final do array será 0-49-0. O primeiro for preenche o array com o valores de
// 98-97-96-95-94...1-0 o segundo for copia os valores do final do array para o começo invertendo a
// ordem (...5-4-3-2-1-0) no fim do array, vira (0-1-2-3-4-5...) no início do array
// ao chegar na metade do for e começar a acessar a primeira metado do array para preencher a
// segunda metade, aquela já foi modificada contendo 0-1-2-3-4...-49.

#include <stdio.h>
#include <stdlib.h>


void printVector(int *v, int n){
  for(int i = 0; i<n; ++i){
	printf("%d\n", v[i]);
  }
}

int main(){
  int v[99];

  for(int i = 0; i < 99; ++i){
	v[i] = 98-i;
  }

  printVector(v, 99);

  for(int i = 0; i < 99; ++i){
	v[i] = v[v[i]];
  }

  printVector(v, 99);
  return 0;
}
