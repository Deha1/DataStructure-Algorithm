#include<stdio.h>


void quickSort(int a[],int left,int right)
{
        int i,j,temp,t;
        if(left>right)
                return;
        temp=a[left];
        i=left;
        j=right;
        while(i<j)
        {
                while(temp<=a[j]&&i<j)
                {
                        j--;
                }
                while(temp>=a[i]&&i<j)
                {
                        i++;
                }
                if(i<j)
                {    t=a[j];
                     a[j]=a[i];
                     a[i]=t;
                }
        }
        a[left]=a[i];
        a[i]=temp;
        quickSort(a,left,i-1);
        quickSort(a,i+1,right);


}


int main(void)
{
        int a[] = {3,2,5,8,4,7,6};
        int n=7;
       quickSort(a,0,6);
       for(int i=0;i<n;i++)
                printf("%d",a[i]);
}

