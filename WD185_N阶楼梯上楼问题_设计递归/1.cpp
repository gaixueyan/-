#include<stdio.h>
#include<iostream>
using namespace std;
int result[100];
int main()
{
    int n;
    result[1]=1;
    result[2]=2;
    int i;
    for(i=3;i<=90;i++)
    {
        result[i]=result[i-1]+result[i-2];
    }
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",result[n]);
    }
    return 0;
}
