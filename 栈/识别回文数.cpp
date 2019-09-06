#include<stdio.h>
#include<stdlib.h>
#define size 100

void palindromenumber(int*s,char x);

int main(void)
{
        int*s;
        int top;
        char x;
        s=(int*)malloc(size*sizeof(int));
        printf("plz input：\n");
        scanf("%c",&x);
        palindromenumber(s,x);
        top=-1;
        free(s);
}

void palindromenumber(int*s,char x)
{
        int top=-1;
        int p=0;
        while(x)
        {
                if(top!=size-1)
                {
                        if(s[p]=s[top])//建立一个栈底的识别器p，和栈顶top一起跑，比较其是否相同
                                top--;
                                p++;
                                if(p>top)//当p大于top跳出循环，是回文数，我尝试用break跳出，但是做不对。。然后就无限printf
                                        printf("\nthis is palindromenumber");
                        else{
                                printf("\nthis is not pailndromenumber");
                        }
                }
                else{
                        printf("I AM FULL\n");
                }
        }

}
