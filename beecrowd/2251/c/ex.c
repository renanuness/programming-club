#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n;

    scanf("%d", &n);
    int teste = 1;
    while (n != 0)
    {
        int movimentos = 1;
        int m = 1;

        if (n > 1)
        {
            movimentos = m << n;
            movimentos--;
        }

        printf("Teste %d\n", teste++);
        printf("%d\n", movimentos);
        printf("\n");
        scanf("%d", &n);
    }

    return 0;
}