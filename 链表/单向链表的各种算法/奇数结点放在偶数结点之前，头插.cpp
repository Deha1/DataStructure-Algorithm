#include<stdio.h>
#include<stdlib.h>
#define N 5
typedef struct node{
        int data;
        struct node*next;
}ElemSN;

ElemSN*createlink(int a[]);
void printlink(ElemSN*h);
ElemSN*prelink(ElemSN*h);
void printprelink(ElemSN*h);

int main(void)
{
        int a[5]={1,2,3,4,5};
        ElemSN*head=NULL;
        ElemSN*head1;
        head=createlink(a);
        printlink(head);
        head1=prelink(head);
        printprelink(head1);
        return 0;
}

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
        printf("\n");
}

ElemSN*prelink(ElemSN*h)
{
        ElemSN*p,*q,*h1;
        h1=q=h;
        p=h->next;
        while(p)
        {
                if(p->data%2)
                {
                        q->next=p->next;
                        p->next=h1;
                        h1=p;
                        p=q->next;
                }
                else
                {
                        q=p;
                        p=p->next;
                }
        }
        return h1;
}

void printprelink(ElemSN*h)
{
        ElemSN*p;
        for(p=h;p!=NULL;p=p->next)
                printf("%5d",p->data);
}

