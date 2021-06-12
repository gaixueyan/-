//哥德巴赫猜想：任意一个大于4的偶数都可以写成两个素数的和。
//设计程序，输入一个大于4的偶数，给出有几组素数满足加和等于这个偶数。p1+p2和p2+p1视为同一组
#include<stdio.h>
#include<iostream>
using namespace std;
#include<math.h>

int num[35000];

void sushuchuli()
{
    num[0]=num[1]=0;//0非素数
    int i,j;
    for(i=2;i<35000;i++)
    {
        num[i]=1;//1素数
    }
    for(i=2;i<35000;i++)
    {
        if(num[i]==1)
        {
            for(j=i*i;j<35000;j=j+i)
            {
                num[j]=0;
            }
        }
    }
}

int main()
{
    sushuchuli();
    int n;
    int i;
    int result;
    scanf("%d",&n);
    while(n!=0)
    {
        result=0;
        for(i=2;i<=n/2;i++)
        {
            if(num[i]==1 && num[n-i]==1)
            {
                result++;
            }
        }
        printf("%d\n",result);
        scanf("%d",&n);
    }
    return 0;
}
