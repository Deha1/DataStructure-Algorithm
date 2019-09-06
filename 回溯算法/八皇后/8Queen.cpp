#include<stdio.h>
#include<stdlib.h>
int col[8]={0};
int left[15]={0};
int right[15]={0};
int q[8];



void Queen()
{
        int top,i,j;
        i=0;
        j=0;
        top=-1;
        while(top!=7){
                for(;j<8;j++)
                {
                        //判断是否放入皇后
                        if(!col[j]&&!left[i+j]&&!right[7+i-j])
                        {
                                //以top为行号，j为列号存入一个皇后
                                q[++top]=j;
                                //在以此皇后的左右横线和列中存入1，代表不可放入皇后的位置
                                col[j]=left[i+j]=right[7+i-j]=1;
                                //行号加一
                                i++;
                                //仍然从0列开始
                                j=0;
                                break;
                        }
                }
                //回溯(上面无法放入皇后)
                if(j==8)
                {

                        i--;
                        //出栈
                        j=q[top--];
                        //抹掉左右斜线和列中的值
                        col[j]=left[i+j]=right[7+i-j]=0;
                        //列号j回溯到之前一行皇后的所在列
                        j++;

                }



        }
}



int main(void)
{
        int i;
        Queen();
        for(i=0;i<8;i++)
                printf("%5d",q[i]);
}









