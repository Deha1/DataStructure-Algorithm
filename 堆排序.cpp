#include<stdio.h>
#include<stdlib.h>
#define N 9

typedef struct node{
        int data;
        struct node*left,*right;
}btnode;


btnode*CreateBTree(int a[])
{
        btnode*root,*c,*p,*pa;
        root=(btnode*)malloc(sizeof(btnode));
        root->data=a[0];
        root->left=root->right=NULL;
        for(int i=1;i<N;i++)
        {
                p=(btnode*)malloc(sizeof(btnode));
                p->data=a[1];
                p->left=p->right=NULL;
                c=root;
                while(c)
                {
                pa=c;
                if(c->data>p->data)
                        c=c->left;
                else
                        c=c-right;
                }
                if(pa->data>p->data)
                        pa->left=p;
                else
                        pa->right=p;
        }
        return root;
}


btnode*CreateComBTree(int a[])
{
        btnode**q;
        btnode*p,*pa,*root;
        int front,rear;
        q=(btnode**)malloc((N+2)*sizeof(btnode*));
        front=rear=0;
        pa=(btnode*)malloc(sizeof(btnode));
        root->data=a[0];
        root->left=root->right=NULL;
        for(int i=1;i<N;i++)
        {
                p=(btnode*)malloc(sizeof(btnode));
                p->data=a[1];
                p->left=p->right=NULL;
                if(!pa->left)
                        pa->left=p;
                else
                {
                        pa->right=p;
                        pa=q[++front];
                }
                q[++rear]=p;
        }
        free(q);
        return root;
}

void HeapSort(btnode*root)
{
        btnode**q;
        btnode*p,*pmin;
        int front,rear,end,t,k,tag=1;
        q=(btnode**)malloc((N+2)sizeof(btnode*));
        front=rear=0;
        //根入队
        q[++rear]=root;
        //将完全二叉树存入队列
        while(1)
        {
                //p=出队元素
                p=q[++front];
                if(!p->left&&!p->right)
                        break;
                else
                {
                     if(!p->left)
                        //p->left入队
                        p->left=q[++rear];
                     else if(!p->right)
                        //p->right入队
                        p->right=q[++rear];
                }
                while(tag==0)
                {

                }




        }















}




int main(void)
{
        btnode*root;
        int a[]={3,2,13,8,12,7,9,1,6};
        root=CreateBTree(a);

        root=CreateComBTree(a);
        HeapSort(root);
}




