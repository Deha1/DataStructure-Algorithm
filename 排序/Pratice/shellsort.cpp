#include<stdio.h>


void shellsort(int a[],int n);

int main(void)
{
        int a[]={3,2,5,8,4,7,6,9};
        int n=sizeof(a)/sizeof(*a);
        shellsort(a,n);
        for(int i=0;i<n;i++)
                printf("%d",a[i]);
}


void shellsort(int a[],int n)
{
        int i,j,gap,t;
        //增量gap，并逐步缩小增量
        for(gap=n/2;gap>0;gap/=2)
        {
               // printf("%d\t",gap);
                //从第gap个元素，逐个对其所在组进行直接插入排序操作
               // printf("\n");
                for(i=gap;i<n;i++)
                {
                       j=i;
                       // printf("%d\t",j);
                       while(j-gap>=0 && a[j]<a[j-gap])
                       {
                               t=a[j];
                               a[j]=a[j-gap];
                               a[j-gap]=t;

                               j-=gap;
                       }

                }

        }


}
