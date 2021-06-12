#include<stdio.h>
#include<iostream>
using namespace std;
#include<math.h>

int num[10002];
int sushu[10002];
int sizesushu;
int yinshu[1000];
int yinshumi[1000];
int sizeyinshu;

void chulisushu()
{
    int i,j;
    num[0]=num[1]=0;
    for(i=2; i<10002; i++)
    {
        num[i]=1;
    }
    for(i=2; i<10002; i++)
    {
        if(num[i]==1)
        {
            sushu[sizesushu]=i;
            sizesushu++;
            for(j=i*i; j<10002; j=j+i)
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
    int n;
    int i,j;
    int result;
    while(scanf("%d",&n)!=EOF)
    {
        sizeyinshu=0;
        result=0;
        for(i=0;i<1000;i++)
        {
            yinshumi[i]=0;
        }
        for(i=0; i<sizesushu && n!=1; i++)
        {
            if(n%sushu[i]==0)
            {
                yinshu[sizeyinshu]=sushu[i];
                while(n%sushu[i]==0)
                {
                    n=n/sushu[i];
                    yinshumi[sizeyinshu]++;
                }
                sizeyinshu++;
            }
        }
        if(sizeyinshu==0)
        {
            yinshu[sizeyinshu]=n;
            yinshumi[sizeyinshu]=1;
            sizeyinshu++;
        }
        for(i=0;i<sizeyinshu;i++)
        {
            result=result+yinshumi[i];
        }
        printf("%d\n",result);
    }
    return 0;
}
