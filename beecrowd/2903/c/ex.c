#include<stdio.h>
#include<stdlib.h>

int main(){
    float raios;
    
    scanf("%f", &raios);
    int volta = 1;
    while(1==1){
        float times = (360*volta) / raios;
        int timesInt = (int)times;
        if( times - timesInt == 0){
            printf("%d\n", timesInt);
            break;
        }
        volta++;
    }
}
