#include<stdio.h>
#include<stdlib.h>

typedef struct node{
        int data;
        struct node*left;
        struct node*right;
}btnode;

btnode*createbtree(int a[],int n);
void printbtree(btnode*root);

int main(void)
{
        int a[9]={6,3,2,5,8,7,4,1,9};
        btnode*root;
        root=createbtree(a,9);
        printf("广义表表示的二叉树的输出：\n");
        printbtree(root);
        printf("\n");
}

btnode*createbtree(int a[],int n)
{
        btnode*root,*c,*pa,*p;
        root=(btnode*)malloc(sizeof(btnode));
        root->data=a[0];
        root->left=root->right=NULL;
        for(int i=1;i<n;i++)
        {
                p=(btnode*)malloc(sizeof(btnode));
                p->data=a[i];
                p->left=p->right=NULL;
                c=root;
                while(c){
                        pa=c;
                        if(c->data=p->data)
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

void printbtree(btnode*root)
{
        int a[9]={6,3,2,5,8,7,4,1,9};
        if(root!=NULL)
        {
                for(int i=0;i<9;i++)
                {
                        printf("%c",a[i]);
                if(root->left!=NULL||root->right!=NULL)
                {
                        printf("(");
                        printbtree(root->left);
                        if(root->right)
                                printf(",");
                        printbtree(root->right);
                        printf(")");
                }
               }
        }
}
