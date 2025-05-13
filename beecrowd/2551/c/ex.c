cd #include <stdio.h>
#include <stdlib.h>

int main(){

  while(1){
	int n;
	int l = scanf("%d", &n);
	if(l == EOF){
	  break;
	}
	float r = 0;
	for(int i = 0; i<n; i++){
	  int t, d;
	  scanf("%d", &t);
	  scanf("%d", &d);

	  float p = (float)d/t;
	  if(p > r){
		r = p;
		printf("%d\n", i+1);
	  }
	}
  }

  return 0;
}
