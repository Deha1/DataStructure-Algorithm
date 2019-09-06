#include<stdio.h>

void bubblesort(int a[],int n);

int main(void)
{
        int a[]={25,16,34,27,18,26,35,21};
        int i,n=8;
        for(i=0;i<n;i++)
                printf("%d ",a[i]);
                printf("\n");
        bubblesort(a,8);
        for(i=0;i<n;i++)
                printf("%d ",a[i]);
}

void bubblesort(int a[],int n)
{
        int i,j,t,tag;
        for(i=0;i<n-1;i++)//j的一次大循环，i就+1，表示一个数已经排序完毕，成为有序区间，不需再次排序，最多排n-1次
        {
                tag=0;  //tag为标记，记录j的循环中是否真正实现交换
                for(j=n-1;j>i;j--)  //交换排序的过程，一次大循环就能完成一个数字的排序
                {
                        if(a[j-1]>a[j])//当前一个数字小于后一个数字，则i--
                        {
                                t=a[j-1];
                                a[j-1]=a[j];
                                a[j]=t;
                                tag=1;
                        }
                }
                if(!tag)
                        break;
        }
          printf("%d",i+1);
                printf("\n");
}
