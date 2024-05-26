#include <stdio.h>
#include <string.h>

int area_smallest_side(int l, int w, int h);
int calculate_decimal_value(char s[]);
int myPow(int base, int p);

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        char lS[5] = {'\0'};
        char wS[5] = {'\0'};
        char hS[5] = {'\0'};
        char s[15];
        int n;
        int varRead = 0;
        scanf("%s", s);
        char tempS[5] = {0};
        int saveValue = 0;
        int currentCount = 0;
        int lastExecution = 0;
        for (int i = 0; lastExecution == 0; i++)
        {
            if (s[i] == '\0')
            {
                lastExecution = 1;
                strcpy(hS, tempS);
                continue;
            }

            if (s[i] != 'x')
            {
                tempS[currentCount] = s[i];
                currentCount++;
            }
            else
            {
                saveValue = 1;
            }
            if (saveValue == 1)
            {
                if (varRead == 0)
                {
                    strcpy(lS, tempS);
                }
                else if (varRead == 1)
                {
                    strcpy(wS, tempS);
                }

                saveValue = 0;
                currentCount = 0;
                varRead++;
                tempS[0] = '\0';
                tempS[1] = '\0';
                tempS[2] = '\0';
                tempS[3] = '\0';
            }
        }
        int l = calculate_decimal_value(lS);
        int w = calculate_decimal_value(wS);
        int h = calculate_decimal_value(hS);

        int result = (2 * l * h) + (2 * w * h) + (2 * l * w);
        result += area_smallest_side(l, w, h);
        sum += result;
    }

    printf("%d\n", sum);

    return 0;
}

int area_smallest_side(int l, int w, int h)
{
    if (l > w && l > h)
    {
        return w * h;
    }
    else if (w > l && w > h)
    {
        return l * h;
    }
    else if (h > l && h > w)
    {
        return l * w;
    }

    if (l == w && h > l)
    {
        return l * w;
    }
    else if (h == l && w > l)
    {
        return h * l;
    }
    else if (w == h && l > w)
    {
        return w * h;
    }

    if (l == w && l > h)
    {
        return l * h;
    }
    else if (h == l && l > w)
    {
        return h * w;
    }
    else if (w == h && w > l)
    {
        return w * l;
    }

    return w * h;
}

int calculate_decimal_value(char s[])
{
    int position=0;
    int value = 0;

    for (int i = 4; i >= 0; i--)
    {
        if (s[i] == '\0')
        {
            continue;
        }

        int intValue = (int)s[i] - '0';
        
        value += myPow(10, position) * intValue;
        position++;
    }

    return value;
}

int myPow(int base, int p)
{
    if (p == 0)
    {
        return 1;
    }

    return base * myPow(base, p - 1);
}