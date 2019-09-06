#include<stdio.h>
#include<stdlib.h>
tydef struct node{
        char word;
        int weight;
        struct node*left,*right;
}HuffNode;

int main(void)
{
        HuffNode*root;
        HuffNode**F;
        int i,n,ch,w;
        printf("请输入叶子个数");
        scanf("%d",&n);
        F=(HuffNode**)malloc(n*sizeof(HuffNode*));
        for(i=0;i<n;i++)
        {

        }

}
