#include<stdio.h>
#include<stdlib.h>
#define n 7

typedef struct node{
int data;
struct node*next;
}ElemSN;

ElemSN*createlink(int a[]);
void printlink(ElemSN*h);

int main(void)
{
        int a[n]={3,2,5,8,4,7,1};
        ElemSN*head=NULL;
        head=createlink(a);
        printlink(head);
}

ElemSN*createlink(int a[])
{
        ElemSN*h=NULL,*t,*p;
        for(int i=0;i<n;i++)
        {
                p=(ElemSN*)malloc(sizeof(ElemSN));
                p->data=a[i];
                if(!h)
                {
                        p->next=p;
                        h=t=p;
                }
                else
                {
                        p->next=h;
                        t=t->next=p;
                }
        }
        return h;

}

void printlink(ElemSN*h)
{
        ElemSN*p;
        p=h;
        do{
                printf("%5d",p->data);
                p=p->next;
        } while(p!=h);
}
