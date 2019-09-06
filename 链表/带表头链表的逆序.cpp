#include<stdio.h>
#include<stdlib.h>
#define N 7

typedef struct node{
        int data;
        struct node*next;
}ElemSN;

ElemSN*createlink(int data[]);
void printlink(ElemSN*h);
void prelink(ElemSN*head);
void prelink2(ElemSN*head);

int main(void)
{
        int a[]={3,2,5,8,4,7,1};
        ElemSN*head;
        head=createlink(a);
        prelink(head);
        printlink(head);
        prelink2(head);
        printlink(head);
}

ElemSN*createlink(int data[])
{
        ElemSN*h=NULL,*t;
        h=t=(ElemSN*)malloc(sizeof(ElemSN));
        h->next=NULL;
        for(int i=0;i<N;i++)
        {
                t=t->next=(ElemSN*)malloc(sizeof(ElemSN));
                t->data=data[i];
                t->next=NULL;
        }
        return h;
}

void printlink(ElemSN*h)
{
        ElemSN*p;
        for(p=h;p->next;p=p->next)
                printf("%5d",p->next->data);
        printf("\n");
}

void prelink(ElemSN*head)
{
        ElemSN*p,*r;
        r=head->next;
        head->next=NULL;
        while(r){
                p=r;
                r=r->next;            //p的前驱指针
                p->next=head->next;   //挂链操作1 挂p和第一个节点
                head->next=p;     //挂链操作2 挂头节点
        }
}

void prelink2(ElemSN*head)
{
        ElemSN*p,*r;
        p=head->next;
        r=p->next;
        head->next->next=NULL;
        while(r){
                p=r;
                r=r->next;
                p->next=head->next;
                head->next=p;
        }
}











