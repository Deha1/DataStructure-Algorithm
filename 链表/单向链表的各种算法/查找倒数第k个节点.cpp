#include<stdio.h>
#include<stdlib.h>
#define N 8
//定义链表
typedef struct node
{
	int data;
	struct node *next;
}ElemSN;
//头插法建立不带表头链表
ElemSN *CreatLink(int a[])
{
	ElemSN *p,*h=NULL;
	int i;
	for(i=0;i<N;i++)
	{
		p=(ElemSN *)malloc(sizeof(ElemSN));
		p->data=a[i];
		p->next=h;
		h=p;
	}
	return h;
}
//第一种方法：两指针，第一个指针先跑K个，然后两指针一起跑
int Find(ElemSN *h,int k)
{
	int i;
	ElemSN *p1,*p2;
	p1=p2=h;
	for(i=0;i<k;i++)
		p2=p2->next;
	while(p2)
	{
		p1=p1->next;
		p2=p2->next;
	}
		return p1->data;
}
//第二种犯方法：来自刘航飞，倒数k个就是正数N-k个
int Find1(ElemSN *h,int k)
{
	ElemSN *p;
	p=h;
	int i=0;
	while(i-(N-k))
	{
		i++;
		p=p->next;
	}
	return p->data;
}
//我自己的方法
int Find2(ElemSN*h,int k)
{
        int a[8]={9,6,7,4,8,5,2,3};
        ElemSN*p;
        for(p=h;p&&p->data-a[N-k];p=p->next);
        return p->data;
}

int main()
{
	int a[8]={3,2,5,8,4,7,6,9};
	ElemSN *h;
	h=CreatLink(a);
	printf("%d",Find(h,5));
}
