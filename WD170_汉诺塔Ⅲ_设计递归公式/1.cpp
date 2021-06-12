#include<stdio.h>
#include<iostream>
using namespace std;

int hnt(int n)
{
    if(n==1)
    {
        return 2;
    }
    else
    {
        return hnt(n-1)*3+2;
    }
}
int main()
{
    int n;
    int result;
    while(scanf("%d",&n)!=EOF)
    {
        if(n>35 || n<1)return 0;
        result=hnt(n);
        printf("%d\n",result);
    }
    return 0;
}
