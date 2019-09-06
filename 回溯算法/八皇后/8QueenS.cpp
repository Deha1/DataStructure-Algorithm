#include<stdio.h>
int col[8]={0};
int left[15]={0};
int right[15]={0};
int q[8];
int cnt=0;



void print()
{
        printf("\n");
        printf("第%d组解：\n",++cnt);
        for(int i=0;i<8;i++)
        {
                for(int j=0;j<8;j++)
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
        int j;
        //当查询完所有的列，都无法放元素之后，就可以回溯操作
        for(j=0;j<8;j++)
        {
                //判断是否可以放入皇后，为0则可以放入
                if(!col[j]&&!left[i+j]&&!right[7+i-j])
                {
                        q[i]=j;
                        left[i+j]=1;
                        right[7+i-j]=1;
                        col[j]=1;
                        if(i<7)
                        {
                                Queen(i+1);
                        }
                        else
                        {
                                print();
                                col[j]=left[i+j]=right[7+i-j]=0;
                        }
                }

        }
	i--;
	j=q[i];//通过栈中的列号，来获取列号，知道元素行列的位置，进行回溯操作
	col[j]=left[i+j]=right[7+i-j]=0;
	j++;
	return;
}



int main(void)
{
        int i=0;
        Queen(i);
        return 0;
}



