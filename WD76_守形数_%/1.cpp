#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int n;
    int nf;
    int ny;
    while(scanf("%d",&n)!=EOF)
    {
        nf=n*n;
        if(n<10)
        {
            ny=nf%10;
        }
        else
        {
            ny=nf%100;
        }
        if(ny==n)
        {
            printf("YES!\n");
        }
        else
        {
            printf("NO!\n");
        }
    }
    return 0;
}
