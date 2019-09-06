#include<stdio.h>
int col[20]={0};
int left[40]={0};
int right[23]={0};
int q[20];
int n,cnt;



void print()
{
        printf("\n");
        printf("第%d组解：\n",++cnt);
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        if(q[i]==j)
                                printf("Q\t");
                        else
                                printf("X\t");
                }
                printf("\n");
        }
        printf("\n");
}


void Queen(int i)
{
        if(i>n-1)
        {
                print();
        }
        else
        {
                for(int j=0;j<n;j++)
                {
                        if(!col[j]&&!left[i+j]&&!right[(n-1)+i-j])
                        {
                                q[i]=j;
                                left[i+j]=1;
                                right[(n-1)+i-j]=1;
                                col[j]=1;
                                Queen(i+1);
                                col[j]=left[i+j]=right[(n-1)+i-j]=0;

                        }

                }
        }
}

int main(void)
{
        int i=0;
        printf("请输入皇后数：");
        scanf("%d",&n);
        Queen(i);

        return 0;

}
