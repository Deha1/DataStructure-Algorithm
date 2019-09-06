#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int data ;
struct node*next;
}ElemSN;

ElemSN*Createlink(int data[8],int n);
void printlink(ElemSN*h);
ElemSN*head;

int main(void)
{
        int data[8]={3,4,2,5,8,7,1};
        Createlink(data,7);
        printlink(head);
        return 0;
}

ElemSN*Createlink(int data[],int n)
{
        ElemSN*h,*t;
        head=h=t=(ElemSN*)malloc(sizeof(ElemSN));
        h->next=NULL;
        for(int i=0;i<n;i++)
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
}




