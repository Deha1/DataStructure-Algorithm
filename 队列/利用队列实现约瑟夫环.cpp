#include<stdio.h>
#include<stdlib.h>

void josephsring(int*q,int s,int n);

int main(void)
{
        int*q;
        int n,s;
        printf("plz input:");
        scanf("%d %d",&n,&s);
        q=(int*)malloc((n+1)*sizeof(int));
        for(int i=0;i<n+1;i++)
                q[i]=i;
        josephsring(q,n,s);
}

void josephsring(int*q,int n,int s)
{
        int front=0,rear=n;    //因为浪费一个x空间，所以front头指针指向队列第一个元素，队列第二个元素为队首，x空间不属于队列元素；
        while(front-rear){
                for(int i=0;i<s-1;i++)
                {
                        front=(front+1)%n;       //出队列；
                        rear=(rear+1)%n;
                        q[rear]=q[front];         //入队列；
                }
                front=(front+1)%n;
        printf("%5d",q[front]);
        }
}
