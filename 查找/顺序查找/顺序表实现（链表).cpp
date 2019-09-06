#include<stdio.h>
#include<stdlib.h>
#define N 8
typedef struct node{
        int data;
        struct node*next;
}ElemSN;

ElemSN*createlink(int a[]);
void printlink(ElemSN*h);
ElemSN*search(ElemSN*h,int key);

int main(void)
{
        int a[]={5,13,17,42,46,55,70,94};
        int key;
        ElemSN*p1;
        ElemSN*head=NULL;
        head=createlink(a);
        printlink(head);
        scanf("%5d",&key);
        p1=search(head,key);
        printf("%5d",p1->data);
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

ElemSN*search(ElemSN*h,int key)
{
        ElemSN*p;
        for(p=h;p;p=p->next)
                if(p->data==key)
                        return p;
}










