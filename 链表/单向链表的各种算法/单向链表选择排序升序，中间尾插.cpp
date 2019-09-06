#include<stdio.h>
#include<stdlib.h>
#define N 5
typedef struct node{
        int data;
        struct node*next;
}ElemSN;

ElemSN*createlink(int a[]);
void printlink(ElemSN*h);
ElemSN*selectsort(ElemSN*h);

int main(void)
{
        int a[5]={3,2,4,5,1};
        ElemSN*head=NULL;
        ElemSN*head1;
        head=createlink(a);
        head1=selectsort(head);
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

ElemSN*selectsort(ElemSN*h)
{
        ElemSN*h1,*q,*p,*qm,*pm,*t;
        h1=NULL;
        while(h){
                for(pm=q=h,p=h->next;p;q=p,p=p->next)
                {
                        if(p->data<pm->data)
                        {
                                pm=p;
                                qm=q;
                        }
                }
                if(pm-h)
                        qm->next=pm->next;
                else
                        h=h->next;
                pm->next=NULL;
                if(!h1)
                        h1=t=pm;
                else
                        t=t->next=pm;
        }
        return h1;
}


