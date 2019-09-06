#include<stdio.h>
#include<stdlib.h>
#define v 20

typedef struct stuff{
        int gno;
        int gv;
}ElemG;

typedef struct node{
        int gno;
        struct node *link;
}Goodslink;

typedef struct box{
        int remainder;
        Goodslink *hg;
        struct box *next;
}Boxlink;



void sortD(ElemG*g,int n)
{
        ElemG t;
        int i,j;
        for(i=0;i<n-1;i++)
        {
                for(j=i+1;j<n;j++)
                {
                        if(g[i].gv<g[j].gv)
                        {
                                t=g[i];
                                g[i]=g[j];
                                g[j]=t;
                        }
                }
        }

}


Boxlink*packing(ElemG*g,int n)
{
        Boxlink*p=NULL;
        Boxlink*tail=NULL;
        Boxlink*hbox=NULL;
        Goodslink*q=NULL;
        Goodslink*newg=NULL;
        int i;
        for(i=0;i<n;i++)
        {
                //遍历箱子链，如果箱子容积不足，则向下遍历
                for(p=hbox;p&&p->remainder<g[i].gv;p=p->next);

                //如果上述容积不足或没箱子，则创建新箱子并且初始化
                if(!p)
                {
                        p=(Boxlink*)malloc(sizeof(Boxlink));

                        p->remainder=v;
                        //链尾指向null
                        p->next=NULL;
                        p->hg=NULL;
                        //挂箱子，如果第一次创建新箱子，则hbox没有指上来，需要让它指上来
                        if(!hbox)
                        {
                                hbox=p;
                                tail=p;
                        }

                        else
                                tail=tail->next=p;

                }
                p->remainder-=g[i].gv;
		newg=(Goodslink *)malloc(sizeof(Goodslink));
		newg->gno=g[i].gno;
		newg->link=NULL;
		//判断是否为新箱子，直接挂链或者尾插
		for(q=p->hg;q&&q->link;q=q->link);
		if(!q)
			p->hg=newg;
		else
			q->link=newg;
        }

        return hbox;
}


void PrintBox(Boxlink*h){
        int i=0;
        Boxlink*p=NULL;
        Goodslink*q=NULL;
        for(p=h;p;p=p->next)
        {
                printf("第%d个箱子",++i);
                for(q=p->hg;q;q=q->link)
                        printf("%d\t",q->gno);
                printf("\n");
        }
}


int main(void)
{
        ElemG*g;
        int w;
        Boxlink*hbox;
        int n;//物品个数
        //初始化物品信息
        printf("请输入物品个数：\n");
        scanf("%d",&n);
        g=(ElemG*)malloc(n*sizeof(ElemG));
        for(int i=0;i<n;i++)
        {
                g[i].gno=i+1;
                printf("请输入第%d个物品的体积:",i+1);
                scanf("%d",&w);
                g[i].gv=w;
        }
        //排序
        sortD(g,n);
        for(int i=0;i<n;i++){
                printf("gv:%d\n",g[i].gv);
        }
        //装箱
        hbox=packing(g,n);
        //输出
        PrintBox(hbox);
        return 0;
}



