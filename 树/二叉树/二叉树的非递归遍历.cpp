#include <stdio.h>
#include <stdlib.h>
#define N 9

typedef struct node{
        int data;
        struct node*left;
        struct node*right;
}btnode;



btnode*CreateBtree(int data[],int n)
{
        btnode* root,*c,*pa,*p;
        root=(btnode*)malloc(sizeof(btnode));
        root->left=root->right=NULL;
        root->data=data[0];
        for(int i=1;i<n;i++)
        {
                p=(btnode*)malloc(sizeof(btnode));
                p->data=data[i];
                p->left=p->right=NULL;
                c=root;
                while(c){
                        pa=c;
                        if(c->data>p->data)
                                c=c->left;
                        else
                                c=c->right;
                }
                if(pa->data>p->data)
                        pa->left=p;
                else
                        pa->right=p;
        }
        return root;

}

//层序遍历，队列
void LevelOrder(btnode*root)
{

        btnode*p;
        btnode**q;
        int front,rear;
        //声明队列
        q=(btnode**)malloc((N+1)*sizeof(btnode*));
        //初始队列
        front=rear=0;
        q[++rear]=root;//按层输出

        while(front-rear){//当跑完所有元素是front=rear，遍历完毕
                //printf("%d\n",front);
                p=q[++front];//出队
               // printf("%d\n",front);

                printf("%5d",p->data);
                //入队
                if(p->left)
                        q[++rear]=p->left;
                if(p->right)
                        q[++rear]=p->right;
        }
        free(q);
}

//前序遍历，栈
void Forder(btnode*root)
{
        btnode**s;
        int top=-1;
        btnode*p;
        //创建栈
        s=(btnode**)malloc((N+1)*sizeof(btnode*));
        //初始化栈
        s[++top]=root;
        //非递归前序遍历
        while(top!=-1){
                p=s[top--];//p指上来，top下移，出栈操作
                printf("%5d",p->data);
                //入栈操作
                if(p->right)
                        s[++top]=p->right;
                if(p->left)
                        s[++top]=p->left;
        }
        free(s);
}

void Inorder(btnode*root)
{
        btnode**s;
        int top=-1;
        btnode*p;
        //创建栈
        s=(btnode**)malloc((N+1)*sizeof(btnode*));
        //初始化栈
        p=root;
        while(top!=-1||p)
        {

               while(p)
               {
                        s[++top]=p;
                        p=p->left;
               }
                p=s[top--];
                printf("%5d",p->data);
                p=p->right;

        }

        free(s);
}

void Inorder(btnode*root)
{
        btnode**s;
        int top=-1;
        btnode*p;
        //创建栈
        s=(btnode**)malloc((N+1)*sizeof(btnode*));





}


int main(void)
{
        int data[N]={6,2,8,1,4,10,3,5,9};
        btnode*root;
        root=CreateBtree(data,9);
        LevelOrder(root);
        printf("\n");
        Forder(root);
        printf("\n");
        Inorder(root);
        return 0;
}







