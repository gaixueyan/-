#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

int result[20];//´Ó1¿ªÊ¼´æ·Å
int yiyong[20];
int n;
bool sushu(int n)
{
    int i;
    for(i=2;i<sqrt(n)+1;i++)
    {
        if(n%i==0)return false;
    }
    return true;
}

void huisu(int num)
{
    int i;
    if(num!=1)
    {
        if(!sushu(result[num]+result[num-1]))
        {
            return;
        }
    }
    if(num==n)
    {
        if(sushu(result[num]+result[1]))
        {
            for(i=1;i<=n;i++)
            {
                if(i!=1)
                {
                    printf(" ");
                }
                printf("%d",result[i]);
            }
            printf("\n");
        }
        return;
    }
    for(i=2;i<=n;i++)//写在递归里的循环，代表对于一个位置上的所有摆放的尝试
    {
        if(!yiyong[i])
        {
            result[num+1]=i;
            yiyong[i]=1;
            huisu(num+1);
            yiyong[i]=0;
        }
    }
}

int main()
{
    int i;
    int ci=1;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<1 || n>=17)return 0;
        for(i=1;i<=n;i++)
        {
            result[i]=0;
            yiyong[i]=0;
        }
        result[1]=1;
        yiyong[1]=1;
        printf("Case %d:\n",ci);
        huisu(1);
        ci++;
    }
    return 0;
}
