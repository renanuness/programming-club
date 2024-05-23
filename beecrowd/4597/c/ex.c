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

        int result = (2*l*h) + (2*w*h) + (2*l*w);
        sum += result;

        sum += area_smallest_side(l,w,h);
    }


    printf("%d\n", sum);

    return 0;
}

int area_smallest_side(int l, int w, int h)
{
    int a1, a2, a3;
    a1 = l*h;
    a2 = l*w;
    a3= w*h;

    if(a1 < a2 && a1 < a3){
        return a1;
    }

    if(a2 < a1 && a2 < a3){
        return a2;
    }

    if(a3 < a1 && a3 < a2){
        return a3;
    }

    if((a1 < a2 && a1 == a3) ||(a1 < a3 && a1 == a2)){
        return a1;
    }else if((a2 < a3 && a2 == a1) || (a2 < a1 && a2 == a3)){
        return a2;
    }else{
        return a3;
    }
}