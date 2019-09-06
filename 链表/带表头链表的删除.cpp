#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int data ;
struct node*next;
}ElemSN;

ElemSN*Createlink(int data[8],int n);
void printlink(ElemSN*h);
void delsamenode(ElemSN*h,int key);

int main(void)
{
        int data[7]={3,4,2,5,3,7,1};
        int key;
        ElemSN*head;
        scanf("%d",&key);
        head=Createlink(data,7);
        delsamenode(head,key);
        printlink(head);
        return 0;
}

ElemSN*Createlink(int data[],int n)
{
        ElemSN*h=NULL,*t;
        h=t=(ElemSN*)malloc(sizeof(ElemSN));
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

void delsamenode(ElemSN*h,int key)
{
        ElemSN*p,*delp;
        for(p=h;p->next;)         //因为是带表头的链表，p是前驱，所以p->next必须存在
        {
                if(p->next->data-key)
                        p=p->next;     //p为前驱结点
                else{
                        delp=p->next;           //delp指向待删结点
                        p->next=delp->next;
                }
                free(delp);
        }
}
