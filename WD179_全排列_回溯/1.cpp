#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char str[10];
char result[10];
int yiyong[10];
int strsize;
void huisu(int num)
{
    int i;
    if(num==strsize)
    {
        for(i=0; i<strsize; i++)
        {
            printf("%c",result[i]);
        }
        printf("\n");
        return;
    }
    for(i=0; i<strsize; i++)
    {
        if(yiyong[i]==0)
        {
            yiyong[i]=1;
            result[num]=str[i];
            huisu(num+1);
            yiyong[i]=0;
        }
    }
    return;
}
int main()
{
    while(scanf("%s",str)!=EOF)
    {
        strsize=strlen(str);
        for(int i=0; i<strsize; i++)
        {
            yiyong[i]=0;
        }
        sort(str,str+strsize);
        huisu(0);
        printf("\n");
        return 0;
    }
}
