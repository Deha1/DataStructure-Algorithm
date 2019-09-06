#include<stdio.h>
#include<stdlib.h>
#define N 9

typedef struct node{
        int data;
        struct node*left,*right;
}btnode;

btnode*CreateComBTree(int a[],int n)
{
        btnode*root,*p,*pa;
        btnode**q;
        int front,rear;
        q=(btnode**)malloc((N+2)*sizeof(btnode*));
        front=rear=0;
        //创建根节点
        pa=root=(btnode*)malloc(sizeof(btnode));
        root->data=a[0];
        root->left=root->right=NULL;
        for(int i=1;i<N;i++)
        {
                p=(btnode*)malloc(sizeof(btnode));
                p->data=a[i];
                p->left=p->right=NULL;
                //挂链，并且出入队操作
                if(!pa->left)//如果pa->left为空，就挂左链
                        pa->left=p;
                else{
                        pa->right=p;
                        pa=q[++front];//pa指向出队元素
                }
                //入队
                q[++rear]=p;
        }
        free(q);
        return root;
}

void LevelOrder(btnode*root)
{
        int front,rear;
        btnode**q;
        btnode*p;
        q=(btnode**)malloc((N+1)*sizeof(btnode*));
        front=rear=0;
        q[++rear]=root;
        while(front-rear){
                p=q[++front];
                printf("%5d",p->data);
                if(p->left)
                        q[++rear]=p->left;
                if(p->right)
                        q[++rear]=p->right;
        }
        free(q);
}



int main(void)
{
        int a[N]={3,2,13,8,12,7,9,1,6};
        btnode*root;
        root=CreateComBTree(a,9);
        LevelOrder(root);
        return 0;
}
