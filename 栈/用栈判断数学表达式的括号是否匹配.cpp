#include<stdio.h>
#include<string.h>


int tell(char s[]);
int main(void)
{
        char s[81];
        int tag;
        printf("plz input brakets:");
        gets(s);
        tag=tell(s);
        if(tag)
                printf("\nyes");
        else
                printf("\nno");
}

int tell(char s[])
{
        int i,top;
        top==-1;
        i==0;
        while(s[i])
        {
                if(s[i]='(')
                top++;
                else
                if(s[i]=')')
                {
                        if(top==-1)
                                break;
                        else
                                top--;
                }
        i++;
        }
        if(top==-1)
                return 0;
        else
                return 1;
}
