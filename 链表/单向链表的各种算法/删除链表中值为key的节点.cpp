#include<stdio.h>
#include<stdlib.h>
#define N 5
typedef struct node{
        int data;
        struct node*next;
}ElemSN;

ElemSN*createlink(int a[]);
void printlink(ElemSN*h);
ElemSN* delsamenode(ElemSN*h, int key);

int main(void)
{
        int a[5]={1,2,3,4,5};
        int key;
        ElemSN*head1;
        printf("plz input key:");
        scanf("%d",&key);
        ElemSN*head=NULL;
        head=createlink(a);
        delsamenode(head,key);
        head1=delsamenode(head,key);
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

ElemSN *delsamenode(ElemSN*h, int key)
{
        ElemSN*q,*p;
        p=h;
        while(p)
        {
                if(p->data-key)
                       { q=p;             //q为前驱结点，和p一前一后联动跑
                        p=p->next;        //p为待删结点，来判定是否为删除结点
                       }
                else
                {
                        if(p-h)
                        {
                                q->next=p->next;
                                free(p);
                                p=q->next;
                        }
                        else
                        {
                                h=h->next;
                                free(p);
                                p=h;
                        }
                }


        }
        return h;
}
