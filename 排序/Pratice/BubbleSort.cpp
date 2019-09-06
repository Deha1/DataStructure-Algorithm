#include<stdio.h>


void BubbleSort(int a[],int n)
{
        int i,j,t;
        for(i=0;i<n-1;i++)
                for(j=n-1;j>i;j--)
        {
                if(a[j]>a[j-1])
                {
                        t=a[j];
                        a[j]=a[j-1];
                        a[j-1]=t;
                }

        }

}




int main(void)
{
        int a[]={3,2,5,8,6,7,4};
        int n=7;
        BubbleSort(a,n);
        for(int i=0;i<n;i++)
                printf("%d",a[i]);
}
