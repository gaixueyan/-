//矩阵的运算不是单独的个元素的运算，矩阵A^2=A*A=每一个位置为第一个矩阵（A）的一行乘第二个矩阵（A）的一列的和
#include<stdio.h>
#include<iostream>
using namespace std;
#include<math.h>
#define M 9973

struct juzhen//当函数需要返回数组时，定义struct型，struct里面放数组，则函数返回struct即可
{
    int data[20][20];
};

int n;

struct juzhen cheng(struct juzhen a,struct juzhen b)//参数是两个数组，返回一个数组
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
