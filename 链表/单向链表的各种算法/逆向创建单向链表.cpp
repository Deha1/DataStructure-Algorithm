#include<stdio.h>
#include<stdlib.h>
#define N 5

typedef struct node{
        int data;
        struct node*next;
}ElemSN;
ElemSN*createlink(int a[]);
void printlink(ElemSN*h);

int main(void)
{
        int a[5]={3,2,5,8,4};
        ElemSN*head=NULL;
        head=createlink(a);
        printlink(head);
}

ElemSN*createlink(int a[])
{
        ElemSN*h;
        int i;
        ElemSN*newp;
        h=NULL;
        for(i=N;i>=0;i--)
        {
                newp=(ElemSN*)malloc(sizeof(ElemSN));
                newp->data=a[i];
                newp->next=h;
                h=newp;
        }
        return h;
}

void printlink(ElemSN*h)
{
        ElemSN*p;
        for(p=h;p!=NULL;p=p->next)
                printf("%5d",p->data);
}
