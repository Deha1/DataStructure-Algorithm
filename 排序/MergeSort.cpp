#include<stdio.h>


void mergeSort(int a[],int first, int last,int temp[]);
void mergeArray(int a[], int first, int mid, int last, int temp[]);


int main(void)
{
        int a[]={3,2,5,8,6,7,4};
        int temp[]={0,0,0,0,0,0,0};

        mergeSort(a,0,6,temp);
        //printf("1");
        for(int i=0;i<7;i++)
                printf("%d",a[i]);
        //printf("7");

}

void mergeSort(int a[],int first, int last,int temp[])
{
        if(first<last)
        {
                int mid = (first+last)/2;
                //printf("%d\t",mid);
               // printf("3");
                mergeSort(a,first,mid,temp);
                mergeSort(a,mid+1,last,temp);
                //printf("2");
                //printf("%d",first);
               // printf("%d 002 ",mid);
                //printf("%d",last);
                printf("\n");
                mergeArray(a, first, mid, last, temp);

                //printf("\n");
                //printf("4");
        }


}

void mergeArray(int a[], int first, int mid, int last, int temp[])
{
        int i=first,j=mid;
        int m=mid+1,n=last;
        int k=0;
   //     printf("5");
        while(i<=j&&m<=n)
        {
                if(a[i]<a[m])
                       temp[k++] = a[i++];
                else
                        temp[k++] = a[m++];
        }
        //printf("6");
        while(i<=j)
                temp[k++] = a[i++];
        while(m<=n)
                temp[k++] = a[m++];


                //整合到a数组
        for (i = 0; i < k; i++)
                a[first + i] = temp[i];
        printf("%d",i);
        printf("%d\t",first+i);


}
