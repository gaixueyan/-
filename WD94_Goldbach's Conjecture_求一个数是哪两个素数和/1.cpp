//��°ͺղ��룺����һ������4��ż��������д�����������ĺ͡�
//��Ƴ�������һ������4��ż���������м�����������Ӻ͵������ż����p1+p2��p2+p1��Ϊͬһ��
#include<stdio.h>
#include<iostream>
using namespace std;
#include<math.h>

int num[35000];

void sushuchuli()
{
    num[0]=num[1]=0;//0������
    int i,j;
    for(i=2;i<35000;i++)
    {
        num[i]=1;//1����
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
