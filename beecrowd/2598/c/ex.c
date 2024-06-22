#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int tamanhoAvenida;
        int areaRadar;

        scanf("%d", &tamanhoAvenida);
        scanf("%d", &areaRadar);

        int resto = tamanhoAvenida % areaRadar ? 1 : 0;
        int nRadares = tamanhoAvenida / areaRadar;

        if(resto == 1){
            nRadares++;
        }

        printf("%d\n", nRadares);
    }
}