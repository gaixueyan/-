#include<stdio.h>
#include<iostream>
using namespace std;
//n������ȫ���Ŵ�ԭ��λ�õ��ŷ��ж����֣��ô��Ź�ʽF[n]=(n-1)*(f[n-1]+f[n-2])
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
    return (n-1)*(cuopai(n-1)+cuopai(n-2));//���ƹ�ʽ���г�(n-1)���͵��ڵݹ麯�����㣬ֻ�ڵݹ麯�����һ�ξʹ���
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
