#include<stdio.h>
#include<iostream>
using namespace std;

bool fanxushu(int a,int b)
{
    int flag=1;
    int i;
    int awei[5];
    int bwei[5];
    for(i=0;i<4;i++)
    {
        awei[i]=a%10;
        a=a/10;
    }
    for(i=0;i<4;i++)
    {
        bwei[i]=b%10;
        b=b/10;
    }
    for(i=0;i<4;i++)
    {
        if(awei[i]!=bwei[3-i])
        {
            flag=0;
        }
    }
    if(flag==1)return true;
    else return false;
}

int main()
{
    int i;
    for(i=1000;i<=1111;i++)
    {
        if(fanxushu(i,i*9))
        {
            printf("%d\n",i);
        }
    }
    return 0;
}
