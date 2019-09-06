#include<stdio.h>

int halfsearch(int a[],int low,int high,int key);

int main(void)
{
        int a[]={5,13,17,42,46,55,70,94};
        int key,x;
        int low,high;
        scanf("%5d",&key);
        x=halfsearch(a,0,7,key);
        if(x>-1)
                printf("%d",a[x]);
        else
                printf("not found!");

}

int halfsearch(int a[],int low,int high,int key)
{
        int mid;
        while(low<=high)
        {
                mid=(low+high)/2;
                if(a[mid]==key)
                        return mid;
                else if(a[mid]<key)
                        low=mid+1;
                else
                        high=mid-1;
        }
        return -1;
}
