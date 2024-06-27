#include <stdio.h>

int main()
{
    int r, n;
    scanf("%d", &r);
    scanf("%d", &n);

    int casoCont = 0;
    while (r != 0 && n != 0)
    {
        casoCont++;
        if (r > (n+(26 * n)))
        {
            printf("Case %d: impossible\n", casoCont);
        }
        else if(n > r){
            printf("Case %d: 0\n", casoCont);
        }
        else
        {
            int resultado = r / n;
            int resto = r % n;

            int vezes = resultado - 1;
            if (resto > 0)
            {
                vezes++;
            }
            printf("Case %d: %d\n", casoCont, vezes);
        }

        scanf("%d", &r);
        scanf("%d", &n);
    }

    return 0;
}