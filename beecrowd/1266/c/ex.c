#include <stdio.h>
#include <stdlib.h>

int halfCeil(int value){
  int r = value/2;

  if(value % 2 != 0)
	r++;

  return r;
}

int main(){
  while(1){
	int n;
	scanf("%d", &n);
	if(n == 0){
	  break;
	}

	int sequenciaQuebrados[n/2];
	int cont = 0;
	
	int postes = 0;
	int quebradosAnteriores = 0;

	int comecaQuebrado = 0;
	int terminaQuebrado = 0;
	
	for(int i = 0; i < n; i++){
	  int x;
	  scanf("%d", &x);

	  if(x==0){
		quebradosAnteriores++;
		if(i == 0){
		  comecaQuebrado = 1;
		}else if(i == n-1 && cont > 0){
		  terminaQuebrado = 1;
		}

	  }else{
		if(quebradosAnteriores > 0){
		  sequenciaQuebrados[cont] = quebradosAnteriores;
		  quebradosAnteriores = 0;
		  cont++;
		}
	  }	    
	}

	if(cont == 1){
	  postes = halfCeil(sequenciaQuebrados[0]);
	}else{
	  for(int i = 0; i<cont; i++){
		int quebrados = sequenciaQuebrados[i];
		if(i == 0 && comecaQuebrado == 1 && terminaQuebrado == 1 ){
		  quebrados += sequenciaQuebrados[cont-1];
		  cont--;
		}

		postes += halfCeil(quebrados);

	  }
	}
	
	printf("%d\n", postes);
  }
  return 0;
}
