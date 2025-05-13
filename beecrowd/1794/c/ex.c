#include <stdio.h>
#include <stdlib.h>

int main(){
  int n;
  int la, lb;
  int sa, sb;

  scanf("%d", &n);
  scanf("%d", &la);
  scanf("%d", &lb);
  scanf("%d", &sa);
  scanf("%d", &sb);

  int possivel = 1;
  if(n < la || n > lb || n < sa || n > sb){
    possivel = 0;
  }

  if(possivel ==1){
    printf("possivel\n");
  }else{
    printf("impossivel\n");
  }
  
  return 0; 
}
