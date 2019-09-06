#include <stdio.h>

int main()
{
   int book[1001],i,j,t,n;
   int a[]={3,2,5,6,8,4,7,9,1,0};
   n=sizeof(a)/sizeof(a[0]);


for(i=1;i<=n;i++)
{
    scanf("%d",&t);  //把每一个数读到变量t中
    book[t]++;
}
for(i=1000;i>=0;i--)
{
    for(j=1;j<=book[i];j++)
         printf("%d ",i);
}

}
