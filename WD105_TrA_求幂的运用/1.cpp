//��������㲻�ǵ����ĸ�Ԫ�ص����㣬����A^2=A*A=ÿһ��λ��Ϊ��һ������A����һ�г˵ڶ�������A����һ�еĺ�
#include<stdio.h>
#include<iostream>
using namespace std;
#include<math.h>
#define M 9973

struct juzhen//��������Ҫ��������ʱ������struct�ͣ�struct��������飬��������struct����
{
    int data[20][20];
};

int n;

struct juzhen cheng(struct juzhen a,struct juzhen b)//�������������飬����һ������
{
    struct juzhen result;
    int i,j,k;
    int sum;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            sum=0;
            for(k=0;k<n;k++)
            {
                sum=(sum+(a.data[i][k]*b.data[k][j])%M)%M;
            }
            result.data[i][j]=sum;
        }
    }
    return result;
}

int main()
{
    int t,k;
    int i,j,e;
    int result;
    struct juzhen num;
    struct juzhen mi;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        result=0;
        scanf("%d %d",&n,&k);
        for(j=0; j<n; j++)
        {
            for(e=0; e<n; e++)
            {
                scanf("%d",&num.data[j][e]);
                mi.data[j][e]=0;
            }
        }
        for(j=0;j<n;j++)
        {
            mi.data[j][j]=1;
        }
        while(k!=0)
        {
            if(k%2==1)
            {
                mi=cheng(mi,num);
            }
            k=k/2;
            num=cheng(num,num);
        }
        for(j=0;j<n;j++)
        {
            result=(result+mi.data[j][j])%M;
        }
        printf("%d\n",result);
    }
    return 0;
}
