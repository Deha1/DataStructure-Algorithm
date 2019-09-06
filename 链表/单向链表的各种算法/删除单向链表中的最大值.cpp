#include<stdio.h>
#include<stdlib.h>
#define N 6
typedef struct node{
        int data;
        struct node*next;
}ElemSN;

ElemSN*createlink(int a[]);
void printlink(ElemSN*h);
ElemSN*delmaxnode(ElemSN*h);


int main(void)
{
        int a[6]={1,2,3,6,3,5};
        ElemSN*head1;
        ElemSN*head=NULL;
        head=createlink(a);
        head1=delmaxnode(head);
        printlink(head1);
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
}

ElemSN*delmaxnode(ElemSN*h)
{
        ElemSN*p,*q,*pmax,*qmax;
        pmax=h;
        q=h;
        p=h->next;
        for(;p;q=p,p=p->next)
        {
                if(p->data>pmax->data)
                {
                        pmax=p;
                        qmax=q;
                }
        }
        if(pmax-h)
                qmax->next=pmax->next;
        else
                h=h->next;
        free(p);
        return h;
}
