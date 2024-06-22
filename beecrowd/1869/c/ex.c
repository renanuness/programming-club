#include <stdio.h>

char obterChar(unsigned long long int x)
{
    if (x < 10)
    {
        return 48 + x;
    }
    else
    {
        return (x - 10) + 65;
    }
}

void recursividade(char *digitos, int* digitoCont, unsigned long long int x)
{
    if (x < 32)
    {
        digitos[(*digitoCont)++] = obterChar(x);
        return;
    }

    unsigned long long int resultado = x / 32;
    unsigned long long int resto = x % 32;

    digitos[(*digitoCont)++] = obterChar(resto);
    x = resultado;
    
    recursividade(digitos, digitoCont, resultado);
}

int main()
{
    unsigned long long int x;
    scanf("%llu", &x);
    char digitos[13] = {-1};
    int digitoCont = 0;

    while (x != 0)
    {
        recursividade(digitos, &digitoCont, x);
   
        // Imprime o resultado
        for (int i = digitoCont - 1; i >= 0; i--)
        {   
            printf("%c", digitos[i]);

            digitos[i] = -1;
        }

        digitoCont = 0;
        printf("\n");
        scanf("%llu", &x);
    }
    printf("0");
    printf("\n");
}