#include <stdio.h>
#include <stdlib.h>

int main(){
  while(1){
	int n;
	int l = scanf("%d", &n);
	if(l == EOF){
	  break;
	}
	int r = n/100;

	float q = n%100;

	if(q > 0){
	  r++;
	}

	printf("%d\n", r);
  }

  return 0;
}


