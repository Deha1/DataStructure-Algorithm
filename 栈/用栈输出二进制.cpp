#include<stdio.h>
#include<stdlib.h>
#define size 100

int exchangebin(int*s,int x);
void printbin(int*s,int top);

int main(void)
{
        int*s;
        int x, top;
        s=(int*)malloc(size*sizeof(int));
        printf("plz input a integer\n");
        scanf("%d",&x);
        exchangebin(s,x);
        printbin(s,top);
        top=-1;
        free(s);

}

int exchangebin(int*s,int x)
{
        int top=-1;
        while(x)
        {
                if(top!=size-1)
                {
                        s[++top]=x%2;
                        x=x/2;
                }
                else
                        printf("I AM FULL\n");
        }
        return top;
}

void printbin(int*s,int top)
{
        while(top!=-1)
        {
                printf("%5d",s[top--]);
        }
}
