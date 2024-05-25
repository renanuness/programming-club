#include <stdio.h>

int area_smallest_side(int l, int w, int h);

int main()
{
    int n;
    scanf("%d", &n);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int l, w, h;

        scanf("%d", &l);
        scanf("%d", &w);
        scanf("%d", &h);

        int result = (2 * l * h) + (2 * w * h) + (2 * l * w);
        sum += result;

        sum += area_smallest_side(l, w, h);
    }

    printf("%d\n", sum);

    return 0;
}

int area_smallest_side(int l, int w, int h)
{
    int a1, a2, a3;
    a1 = l * h;
    a2 = l * w;
    a3 = w * h;

    if (l > w && l > h)
    {
        return w * h;
    }
    else
    {
        if (w > l && h < w)
        {
            return l * h;
        }
    }
    return l * w;
}