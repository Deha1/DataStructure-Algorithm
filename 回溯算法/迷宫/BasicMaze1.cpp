#include<stdio.h>
#include<stdlib.h>
#define R 7;
#define C 8;
int M[R+2][C+2]={0};
int T[R+2][C+2]={0};
int Move{4}{2}={{1,0},{0,1},{-1,0},{0,-1}};

int main(void)
{
        for(i=0;i<R+2;i++)
        {
                for(j=0;j<C+2;j++)
                {
                        if(i==0||i==R+1||j==0||j==C+1)
                                M[i][j]=1;
                }
        }
        Maze(1,1);

}

int Maze(int x,int y)
{
        if(x==7&&y==8)
        {
                print();
                return;
        }
        for(int i=0;i<4;i++)
        {
                a=Move[i][0]+x;
                b=Move[i][1]=y;
                if(!M[a][b]&&!T[a][b])
                {
                        T[a][b]=1;
                        top++;
                        stack[top][0]=a;
                        stack[top][1]=b;
                        Maze(a,b);
                        T[a][b];
                        top--;
                }
        }
}
