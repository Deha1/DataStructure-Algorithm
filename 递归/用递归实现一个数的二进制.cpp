#include<stdio.h>

void bin(int x);

int main(void)
{
        int x;
        printf("plz input:");
        scanf("%d",&x);
        bin(x);
}

void bin(int x)
{
        if(x)
        {
                bin(x/2);    //先除以2，等跳出循环后再从最小的数逆向取余输出
        }
        printf("%d",x%2);
}
