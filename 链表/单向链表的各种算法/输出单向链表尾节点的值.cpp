#include<stdio.h>
#include<stdlib.h>
#define N 5

typedef struct node{
        int data;
        struct node*next;
}ElemSN;

ElemSN*createlink(int a[]);
void printlink(ElemSN*h);
ElemSN*tailnode(ElemSN*h);
int countnode(ElemSN*h);

ElemSN*createlink(int a[])
{
        ElemSN*h,*tail;
        h=tail=(ElemSN*)malloc(sizeof(ElemSN));
        h->data=a[0];
        h->next=NULL;
        for(int i=1;i<N;i++)
        {
                tail=tail->next=(ElemSN*)malloc(sizeof(ElemSN));
                tail->data=a[i];
                tail->next=NULL;
        }
        return h;
}

void printlink(ElemSN*h)
{
        ElemSN*p;
        for(p=h;p!=NULL;p=p->next)
                printf("%5d",p->data);
}

ElemSN*tailnode(ElemSN*h)
{
        ElemSN*p;
        for(p=h;p->next;p=p->next);
        return p;
}

int countnode(ElemSN*h)
{
        int cnt=0;
        ElemSN*p;
        for(p=h;p;cnt++,p=p->next);
        return cnt;
}

int main(void)
{
        int a[5]={3,2,5,8,4};
        int count;
        ElemSN*head=NULL;
        ElemSN*ptail;
        head=createlink(a);
        printlink(head);
        ptail=tailnode(head);
        printf("\n尾节点值为:%d",ptail->data);
        count=countnode(head);
        printf("\n结点个数为:%d",count);
        return 0;
}



