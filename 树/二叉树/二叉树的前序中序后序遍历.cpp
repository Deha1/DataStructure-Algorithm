#include<stdio.h>
#include<stdlib.h>

typedef struct node{
        int data;
        struct node*left;
        struct node*right;
}btnode;

btnode*createbtree(int a[],int n);
void forder(btnode*root);
void inorder(btnode*root);
void porder(btnode*root);

int main(void)
{
        int a[9]={6,3,2,5,8,7,4,1,9};
        btnode*root;
        root=createbtree(a,9);
        forder(root);
        printf("\n");
        inorder(root);
        printf("\n");
        porder(root);
}

btnode*createbtree(int a[],int n)
{

        btnode *root,*c,*pa,*p;
        root=(btnode*)malloc(sizeof(btnode));
        root->left=root->right=NULL;
        root->data=a[0];
        for(int i=1;i<n;i++)
        {
                p=(btnode*)malloc(sizeof(btnode));
                p->data=a[i];
                p->left=p->right=NULL;
                c=root;

                while(c){

                        pa=c;
                        if(c->data > p->data)
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


//前序遍历
void forder(btnode*root)
{
        if(root){
                printf("%5d",root->data);
                forder(root->left);
                forder(root->right);
        }
}

//中序遍历
void inorder(btnode*root)
{
        if(root){
                inorder(root->left);
                printf("%5d",root->data);
                inorder(root->right);
        }
}

//后序遍历
void porder(btnode*root)
{
        if(root){
                porder(root->left);
                porder(root->right);
                printf("%5d",root->data);
        }
}



