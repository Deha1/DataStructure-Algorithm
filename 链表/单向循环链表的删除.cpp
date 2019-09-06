#include<stdio.h>
#include<stdlib.h>
#define n 7

typedef struct node{
int data;
struct node*next;
}ElemSN;

ElemSN*createlink(int a[]);
void printlink(ElemSN*h);
ElemSN*delkeynode(ElemSN*h,int key);

int main(void)
{
        int a[n]={3,2,5,8,4,7,1};
        int key;
        printf("plz input the key:\n");
        scanf("%d",&key);
        ElemSN*head=NULL;
        ElemSN*head1;
        head=createlink(a);
        printlink(head);
        head1=delkeynode(head,key);
        printlink(head1);
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
                        p->next=h;   //相互挂链
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


ElemSN*delkeynode(ElemSN*h,int key)
{
        ElemSN*p,*q;
        p=h;
        q=NULL;
        do{
                if(p->data-key)
                {
                        q=p;
                        p=p->next;
                }
                else
                        break;
        }while(p-h);
        if(p=h&&q!=NULL)
                printf("not found\n");
        else
        {
                if(p==h)  //q为空，p==h
                {
                        for(q->next-h;q=q->next)
                                h=h->next;
                }
                q->next=p->next;
                free(p);
        }
        return h;
}










