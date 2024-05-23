#include <stdio.h>

void print_song(int song);

int main()
{
    int n;
    scanf("%d", &n);

    int song = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);
        print_song(a + b);
    }

    return 0;
}

void print_song(int song)
{
    switch (song)
    {
    case 0:
        printf("PROXYCITY");
        break;
    case 1:
        printf("P.Y.N.G.");
        break;
    case 2:
        printf("DNSUEY!");
        break;
    case 3:
        printf("SERVERS");
        break;
    case 4:
        printf("HOST!");
        break;
    case 5:
        printf("CRIPTONIZE");
        break;
    case 6:
        printf("OFFLINE DAY");
        break;
    case 7:
        printf("SALT");
        break;
    case 8:
        printf("ANSWER!");
        break;
    case 9:
        printf("RAR?");
        break;
    case 10:
        printf("WIFI ANTENNAS");
        break;
    }

    printf("\n");
}