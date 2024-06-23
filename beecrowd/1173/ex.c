#include <stdio.h>

int main(){
    int v;
    scanf("%d", &v);

    for(int i = 0; i < 10; i++){
        printf("N[%d] = %d\n", i, v);
        v *= 2;
    }
}