#include<stdio.h>
#include<iostream>
using namespace std;
//n个东西全部放错原本位置的排法有多少种，用错排公式F[n]=(n-1)*(f[n-1]+f[n-2])
int cuopai(int n)
{
    if(n==2)
    {
        return 1;
    }
    if(n==3)
    {
        return 2;
    }
    return (n-1)*(cuopai(n-1)+cuopai(n-2));//递推公式里有乘(n-1)，就得在递归函数里算，只在递归函数外乘一次就错了
}

int main()
{
    int n;
    int result;
    while(scanf("%d",&n)!=EOF)
    {
        result=cuopai(n);
        printf("%d\n",result);
    }
    return 0;
}
