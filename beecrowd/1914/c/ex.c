#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[100];
    char choice[5];
    int value;
} player;

void read_player_input(player *p1, player *p2);
void start_match();

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        start_match();
    }
}

void start_match()
{

    player p1;
    player p2;
    int result = 0; // PAR
    player *winner = &p2;

    read_player_input(&p1, &p2);

    int sum = p1.value + p2.value;
    if (sum % 2 != 0)
    {
        result = 1;
    }
    
    if (strcmp(p1.choice, "PAR") == 0 && result == 0)
    {
        winner = &p1;
    }
    else if (strcmp(p1.choice, "IMPAR") == 0 && result == 1)
    {
        winner = &p1;
    }

    printf("%s\n", winner->name);
}

void read_player_input(player *p1, player *p2)
{
    scanf("%s", p1->name);
    scanf("%s", p1->choice);

    scanf("%s", p2->name);
    scanf("%s", p2->choice);

    scanf("%d", &(p1->value));
    scanf("%d", &(p2->value));
}
