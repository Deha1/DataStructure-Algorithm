#include<stdio.h>

long fac(int x);

int main(void)
{
        int n, x;
        printf("plz input(q to quit):");
        scanf("%d", &x);
        n = fac(x);
        if (n)
        {
                printf("%d", n);
        }
}

long fac(int x)
{
        long ans;
        if (x > 0)
        {
                ans = fac(x - 1) * x;
        }
        else
        {
                ans = 1;
        }
        return ans;
}
