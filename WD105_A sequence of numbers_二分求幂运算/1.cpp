//(a * b) % c = (( a % c ) * ( b % c ))%c���κ�ʱ�򶼿����õģ���������10��
//(16*12)%9=((16%9)*(12%9))%9=3

//%���Դ���long long�͵�
//long long�Ľ���Ҫ��"%lld"

//(a + b) % c = (a % c + b % c) % c �ӷ���
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
#define M 200907

int main()
{
    int n;
    long long a,b,c;
    int k;
    int i;
    int result;
    int q;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld %lld %d",&a,&b,&c,&k);
        if((c-b)==(b-a))//�Ȳ�����
        {
            result=(a%M+((b-a)%M)*((k-1)%M))%M;
            printf("%d\n",result);
        }
        else//�ȱ�����
        {
            q=(b/a)%M;
            k=k-1;
            result=1;
            while(k!=0)
            {
                if(k%2==1)
                {
                    result=(result*q)%M;
                }
                q=q%M*q%M;
                k=k/2;
            }
            printf("%d\n",result);
        }
    }
    return 0;
}
