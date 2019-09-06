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
        ElemSN*head1=NULL;
        head=createlink(a);
        head1=createlink(a);
        printlink(head);
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
                tail->next=(ElemSN*)malloc(sizeof(ElemSN));
                tail=tail->next;
                tail->data=a[i];
                tail->next=NULL;
        }
        return h;
}

ElemSN*createlink1(int a[])
{
        ElemSN*h,*tail,*p;
        for(int i=0;i<N;i++)
        {
                p=(ElemSN*)malloc(sizeof(ElemSN));
                p->data=a[i];
                p->next=NULL;
                if(!h)
                        h=tail=p;
                else{
                        tail->next=p;
                        tail=tail->next;
                }
                return h;
        }
}


ElemSN * createlink2(int a[]){
    ElemSN *h, *tail, *p;
    //创建头结点
    h=tail=(ElemSN *)malloc(sizeof(ElemSN));
    h->data = a[0];
    h->next = NULL;
    for(int i=1;i<N;i++){
        p=(ElemSN *)malloc(sizeof(ElemSN));
        p->data = a[i];
        p->next = NULL;
        tail->next = p;
        tail=p;
    }
}

void printlink(ElemSN*h)
{
        ElemSN*p;
        for(p=h;p!=NULL;p=p->next)
                printf("%5d",p->data);
        printf("\n");
}
