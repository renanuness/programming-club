#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int t;
  scanf("%d", &t);

  while(t-- > 0){
	char a[10001];
	char b[10001];

	scanf("%s", a);
	scanf("%s", b);

	int ops = 0;
	int i = 0;
	while(a[i] != '\0'){
	  int dif = b[i] - a[i];

	  if(dif < 0){
		dif = 26+dif;
	  }

	  ops += dif;
	  i++;
	}

	printf("%d\n", ops);
  }
}