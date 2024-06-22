#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, v;
    scanf("%d", &a);
    scanf("%d", &v);
    int caso = 1;
    while (a != 0 && v != 0)
    {
        int *voos = calloc(a + 1, sizeof(int));
        int *maximos = calloc(a, sizeof(int)); // 10000 * 4 bytes = 40k bytes
        int maxCont = 0;

        int max = 0;

        // 1 3
        // 1 2
        // 3 2
        // 1 2
        // 2 1
        for (int i = 0; i < v; i++)
        {
            int x, y;
            scanf("%d", &x);
            scanf("%d", &y);

            voos[x]++;
            voos[y]++;
        }

        for (int i = 1; i <= a; i++)
        {
            if (voos[i] > max)
            {
                maxCont = 0;
                maximos[maxCont] = i;
                max = voos[i];
                maxCont++;
            }
            else if (voos[i] == max)
            {
                maximos[maxCont] = i;
                maxCont++;
            }
        }

        printf("Teste %d\n", caso++);
        for (int j = 0; j < maxCont; j++)
        {
            printf("%d ", maximos[j]);
        }

        max = 0;
        maxCont = 0;
        printf("\n");
        scanf("%d", &a);
        scanf("%d", &v);
        if (a != 0 && v != 0)
            printf("\n");
    }
    printf("\n");
}