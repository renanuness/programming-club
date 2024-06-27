#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d", &m); // linhas
    scanf("%d", &n); // colunas
    short matriz[m][n];

    // Array para salvar as coordenadas dos valores 42

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            short x;  
            scanf("%hi", &x);
            matriz[i][j] = x;
        }
    }
    int encontrou = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int valor = matriz[i][j];
            if (valor == 42)
            {
                int x = i;
                int y = j;
                int leftUp = matriz[x - 1][y - 1];
                int up = matriz[x - 1][y];
                int rightUp = matriz[x - 1][y + 1];
                int left = matriz[x][y - 1];
                int right = matriz[x][y + 1];
                int leftDown = matriz[x + 1][y - 1];
                int down = matriz[x + 1][y];
                int rightDown = matriz[x + 1][y + 1];

                if (leftUp == 7 &&
                    up == 7 &&
                    rightUp == 7 &&
                    left == 7 &&
                    right == 7 &&
                    leftDown == 7 &&
                    down == 7 &&
                    rightDown == 7)
                {
                    printf("%d %d\n", x + 1, y + 1);
                    encontrou = 1;
                    break;
                }
            }
        }
    }

    if(encontrou == 0){
        printf("0 0\n");
    }
}