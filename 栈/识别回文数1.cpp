#include<stdio.h>
#include<string.h>
char str1[80];
int top=-1;
int main()
{
	char str[80];
	int i,tag=1,n;
	gets(str);
	n=strlen(str);
	for(i=0;str[i];i++)
		str1[++top]=str[i];
	for(i=0;i<n/2;i++,top--)
		if(str[i]!=str1[top])
			tag=0;
	if(tag)
		printf("是");
	else
		printf("不是");
}
