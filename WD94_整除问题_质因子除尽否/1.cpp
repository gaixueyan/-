#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

int num[1002];
int sushu[1002];
int sizesushu;
int yinshu[102];
int yinshumi[102];
int sizeyinshu;

void chulisushu()
{
    int i,j;
    num[0]=num[1]=0;
    for(i=2;i<1002;i++)
    {
        num[i]=1;
    }
    for(i=2;i<1002;i++)
    {
        if(num[i]==1)
        {
            sushu[sizesushu]=i;
            sizesushu++;
            for(j=i*i;j<1002;j=j+i)
            {
                num[j]=0;
            }
        }
    }
}

int main()
{
    sizesushu=0;
    chulisushu();
    int n,a,k;
    sizeyinshu=0;
    scanf("%d %d",&n,&a);
    int i,j;
    int r,t;
    for(i=0;i<102;i++)
    {
        yinshumi[i]=0;
    }
    for(i=0;i<sizesushu && a!=1;i++)
    {
        if(a%sushu[i]==0)
        {
            yinshu[sizeyinshu]=sushu[i];
            while(a%sushu[i]==0)
            {
                a=a/sushu[i];
                yinshumi[sizeyinshu]++;
            }
            sizeyinshu++;
        }
    }
    k=10000;
    for(i=0;i<sizeyinshu;i++)
    {
        r=yinshu[i];
        t=0;
        while(n/r!=0)
        {
            t=t+n/r;
            r=r*yinshu[i];
        }
        if(k>t/yinshumi[i])
        {
            k=t/yinshumi[i];
        }
    }
    printf("%d\n",k);
    return 0;
}
