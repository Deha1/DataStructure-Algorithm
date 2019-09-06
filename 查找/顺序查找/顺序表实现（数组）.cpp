#include<stdio.h>

int search(int d[],int key,int n)
{
        int i;
        for(i=0;i<n&&d[i]!=key;i++);
                if(i==n)
                        return -1;
                else
                        return i;
}

int search1(int d[],int key,int n)
{
        int i,tag=-1;
        for(i=0;i<n;i++)
                if(d[i]==key)
        {
                tag=i;
                break;
        }
        return tag;
}

#define n 6

int main(void)
{
        int d[n]={5,17,28,34,65,12};
        int x,y;
        int key;
        scanf("%d",&key);
        x=search(d,key,6);
        y=search(d,key,6);
        printf("%d\n",x);
        printf("%d",y);
}

