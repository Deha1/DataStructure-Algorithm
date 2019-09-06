#include<stdio.h>

void selectsort(int a[],int n)
{
        int i,j,x;
        for(i=1;i<n;i++)
        {
                x=a[i];
                for(j=i-1;j>-1;j--)
                {
                        if(a[j]>x)

                                a[j+1]=a[j];
                        else
                                break;
                }
                a[j+1]=x;
                //j+1=0，第一趟a[0]=2；
                //从循环中跳出来才跑这条
        }
}



int main(void)
{
        int a[]={3,2,5,8,4,7,6};
        int i,n=7;
        for(i=0;i<n;i++)
                printf("%d ",a[i]);
                printf("\n");
        selectsort(a,7);
        for(i=0;i<n;i++)
                printf("%d ",a[i]);

}
