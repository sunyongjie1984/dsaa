#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int maxsubset(int* a, int len)
{
    int summax = INT_MIN;
    int i, j, k;
    for(i = 0; i < len; i++)
    {
        for(j = i; j < len; j++)
        {
            int temp = 0;
            for(k = i; k <= j; k++)
                temp += a[k];
            if(temp > summax)
                summax = temp;
        }
    }
    return summax;
}

int main()
{
    int a[] = { 1, -10, 2, 4, 6, -15, 6, 1, 9, -8 };
    printf("the maxsubset:%d\n", maxsubset(a, sizeof(a) / sizeof(int)));
    getchar();
    return 0;
}
