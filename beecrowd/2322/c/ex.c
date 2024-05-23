#include <stdio.h>

int main(){
    int somaPecasPresentes=0;
    int somaPecasTotal = 0;
    int numeroPecas;

    scanf("%d", &numeroPecas);

    for(int i = 1; i <= numeroPecas; i++){
        int peca;

        if(i < numeroPecas){
            scanf("%d", &peca);
            somaPecasPresentes += peca;
        }
        somaPecasTotal+= i;
    }

    int pecaFaltante = somaPecasTotal - somaPecasPresentes;
    printf("%d\n", pecaFaltante);
    return 0;
}