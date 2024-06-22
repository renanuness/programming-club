#include <stdio.h>

int main()
{
    int n, id;

    while (scanf("%d", &n) != EOF)
    {
        int count = 0;
        scanf("%d", &id);

        for (int i = 0; i < n; i++)
        {
            int j, g;

            scanf("%d", &j);
            scanf("%d", &g);

            if (j == id && g == 0)
            {
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}