#include<stdio.h>
#include<stdlib.h>
#define N 5
typedef struct node{
        int data;
        struct node*next;
}ElemSN;

ElemSN*createlink(int a[]);
void printlink(ElemSN*h);
ElemSN*findkeynode(ElemSN*h,int key);
ElemSN*delsinglenode(ElemSN*h,int key);


int main(void)
{
        int a[5]={1,2,3,4,5};
        int key;
        printf("plz input key:\n");
        scanf("%d",&key);
        ElemSN*head;
        ElemSN*head1;
        ElemSN*pkey;
        head=createlink(a);
        pkey=findkeynode(head,key);
        if(!pkey)
                printf("not found!\n");
        else{
                printf("值为：%d\n",pkey->data);
        }
        head1=delsinglenode(head,key);
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



ElemSN*findkeynode(ElemSN*h,int key)
{
        ElemSN*p;
        for(p=h;p&&p->data-key;p=p->next);
        return p;
}

ElemSN*delsinglenode(ElemSN*h,int key)
{
        ElemSN*p,*q;
        for(p=h;p&&p->data-key;q=p,p=p->next);
        if(!p)
                printf("not found\n");
        else
        {
                if(p-h)
                        q->next=p->next;
                else
                        h=h->next;
                free(p);
                p=NULL;
        }
        return h;
}
















