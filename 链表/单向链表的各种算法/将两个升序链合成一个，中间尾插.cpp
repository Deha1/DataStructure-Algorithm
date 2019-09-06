#include<stdio.h>
#include<stdlib.h>
#define N 5
#define H 6

typedef struct node{
        int data;
        struct node*next;
}ElemSN;

ElemSN*createlink(int a[]);
void printlink(ElemSN*h);
ElemSN*createlink1(int a[]);
ElemSN*composedlink(ElemSN*head1,ElemSN*head2);

int main(void)
{
        int a[5]={1,2,3,4,5};
        int b[6]={3,4,5,6,7,8};
        ElemSN*head=NULL;
        ElemSN*head1=NULL;
        ElemSN*headp;
        head=createlink(a);
        printlink(head);
        head1=createlink1(b);
        printlink(head1);
        headp=composedlink(head,head1);
        printlink(headp);
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

ElemSN*createlink1(int a[])
{
        ElemSN*h,*tail;
        h=tail=(ElemSN*)malloc(sizeof(ElemSN));
        h->data=a[0];
        h->next=NULL;
        for(int i=1;i<H;i++)
        {
                tail=tail->next=(ElemSN*)malloc(sizeof(ElemSN));
                tail->data=a[i];
                tail->next=NULL;
        }
        return h;
}

ElemSN*composedlink(ElemSN*head1,ElemSN*head2)
{
        ElemSN*h,*p,*t;
        h=NULL;
        while(head1&&head2)
        {
                if(head1->data<head2->data){
                        p=head1;
                        head1=head1->next;
                }
                else{
                        p=head2;
                        head2=head2->next;
                }
                p->next=NULL;
                if(!h)
                        h=t=p;
                else{
                        t->next=p;          //挂链操作
                        t=t->next;
                }
        }
        if(head1)
                p=head1;
        else
                p=head2;
        t->next=p;     //单链挂链
        return h;
}


