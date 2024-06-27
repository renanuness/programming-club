#include <stdio.h>

void obterDigitos(long long int *digitos, int *digitosCont, long long int valor)
{
    if (valor < 10)
    {
        digitos[*digitosCont] = valor;
        (*digitosCont)++;
        return;
    }

    long long int resultado = valor / 10;
    long long int resto = valor % 10;

    digitos[*digitosCont] = resto;
    (*digitosCont)++;

    obterDigitos(digitos, digitosCont, resultado);
}

int main()
{
    long long int n;
    long long int digitos[17] = {-1};
    int digitosCont = 0;

    scanf("%lli", &n);

    obterDigitos(digitos, &digitosCont, n);

    int anteriorEhUm = 0;
    int ehMaSorte = 0;

    for (int i = digitosCont-1; i >= 0; i--)
    {
        if (anteriorEhUm == 0)
        {
            if (digitos[i] == 1)
            {
                anteriorEhUm = 1;
            }
        }
        else
        {
            if (digitos[i] == 3)
            {
                ehMaSorte = 1;
                break;
            }else{
                anteriorEhUm = 0;
            }
        }
    }

    if (ehMaSorte == 0)
    {
        printf("%lli NO es de Mala Suerte\n", n);
    }
    else
    {
        printf("%lli es de Mala Suerte\n", n);
    }

    return 0;
}