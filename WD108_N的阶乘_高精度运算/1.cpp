#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

struct bigint
{
    int data[3002];
    int sizedata;
};

struct bigint result;
struct bigint cheng;

/*我错了，不应该叫他模拟乘法。这跟手算的逻辑并不完全一样。
但每乘一次高一位的规则和程序中每次把结果提高一位存储有异曲同工之妙。
要有意识：乘法不用模拟的那么像，简单的从低向高遍历每位，和int相乘，进位就行了。
最后乘法的结果在【最高位+1】堆积，取余除10化成多个存储位即可*/
void monicheng(int n)
{
    int i;
    int tmp;
    for(i=0; i<3002; i++)
    {
        cheng.data[i]=0;
    }
    cheng.sizedata=0;
    for(i=0; i<result.sizedata; i++)
    {
        tmp=result.data[i]*n;
        cheng.data[i+1]=(cheng.data[i]+tmp)/10;
        cheng.data[i]=(cheng.data[i]+tmp)%10;
        cheng.sizedata++;
    }
    tmp=cheng.data[cheng.sizedata];
    while(tmp!=0)
    {
        cheng.data[cheng.sizedata]=tmp%10;
        tmp=tmp/10;
        cheng.sizedata++;
    }
    for(i=0; i<cheng.sizedata; i++)
    {
        result.data[i]=cheng.data[i];
    }
    result.sizedata=cheng.sizedata;
}

int main()
{
    int n;
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        result.sizedata=cheng.sizedata=0;
        for(i=0; i<3002; i++)
        {
            result.data[i]=cheng.data[i]=0;
        }
        result.data[0]=1;
        result.sizedata=1;
        for(j=2; j<=n; j++)
        {
            monicheng(j);
        }
        for(i=result.sizedata-1; i>=0; i--)
        {
            printf("%d",result.data[i]);
        }
        printf("\n");
    }
    return 0;
}
