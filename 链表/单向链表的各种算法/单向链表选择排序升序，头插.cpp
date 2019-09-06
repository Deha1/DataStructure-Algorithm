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
        int a[N]={3,2,5,8,4};
        ElemSN*head,*head1;
        head=createlink(a);
        head1=selectsort(head);
        printlink(head1);
        return 0;
}

ElemSN*createlink(int a[])
{
        ElemSN*h,*tail;
        h=tail=(ElemSN*)malloc(sizeof(ElemSN));
        h->next=NULL;
        h->data=a[0];
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
        ElemSN*h1,*p,*q,*pm,*qm;
        h1=NULL;
        while(h)
        {
                for(q=pm=h,p=h->next;p;q=p,p=p->next)
                {
                        if(p->data>pm->data)
                        {
                                pm=p;
                                qm=q;
                        }
                }
                if(pm-h)
                        qm->next=pm->next;
                else
                        h=h->next;
                pm->next=h1;
                h1=pm;
        }
        return h1;
}




















