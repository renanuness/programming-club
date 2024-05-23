#include <stdio.h>

int main()
{
    int a, n;
    scanf("%d", &a);

    do
    {
        scanf("%d", &n);

    } while (n <= 0);

    int sum = 0;
    for(int i = a; i < a+n; i++){
        sum += i;
    }

    printf("%d\n", sum);

    return 0;
}