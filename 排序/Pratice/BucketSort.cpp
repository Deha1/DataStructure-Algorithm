#include<stdio.h>

bucketSort(int a[],int n)
{
        int count[3]={0,0,0};
        int idx=0;
        for(int i=0;i<n;i++)
        {
                if(a[i]==1)
                        count[0]++;
                else if(a[i]==2)
                        count[1]++;
                else if(a[i]==3)
                        count[2]++;

        }
        for( int i=0;i<3;i++)
                for(int j=0;j<count[i];j++)
        {
                a[idx]=i;
                idx++;
        }


}





int main(void)
{
      int a[]={2,3,1,3,1,2};
      int n=6;
      bucketSort(a,n);
      for(int i=0;i<n;i++)
                printf("%d",a[i]);
}
