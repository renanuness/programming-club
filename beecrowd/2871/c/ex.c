#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,m;
	while(scanf("%d", &n) != EOF && scanf("%d", &m) != EOF){
	  int total = 0;
	  for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
		  int x;
		  scanf("%d",&x);
		  total += x;
		  lavoura[i][j] = x;
		}
	  }

	  int litros, sacas;
	  sacas = total/60;
	  litros = total %60;
	  printf("%d saca(s) e %d litro(s)\n",sacas,litros);
	}
}
