#include<stdio.h>

void selectsort(int a[],int n);


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

void selectsort(int a[],int n)
{
        int i,kmin,t,j;
        for(i=0;i<n-1;i++)
        {
                kmin=i;
                for(j=i+1;j<n;j++){
                        if(a[j]<a[kmin])
                                kmin=j;
                }
                        if(i-kmin)   // 查看kmin最小值是否为头元素；
                        {
                                t=a[i];
                                a[i]=a[kmin];
                                a[kmin]=t;
                        }

        }
}
