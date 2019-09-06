#include<stdio.h>

long fibonacci(int n);

int main(void)
{
        int n;
        long x;
        scanf("%d",&n);
        x=fibonacci(n);
        printf("%d\n",x);
        return 0;
}

long fibonacci(int n)
{
        if(n>2)
                return fibonacci(n-1)+fibonacci(n-2);
        else
                return 1;
}
