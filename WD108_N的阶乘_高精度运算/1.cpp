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

/*�Ҵ��ˣ���Ӧ�ý���ģ��˷������������߼�������ȫһ����
��ÿ��һ�θ�һλ�Ĺ���ͳ�����ÿ�ΰѽ�����һλ�洢������ͬ��֮�
Ҫ����ʶ���˷�����ģ�����ô�񣬼򵥵Ĵӵ���߱���ÿλ����int��ˣ���λ�����ˡ�
���˷��Ľ���ڡ����λ+1���ѻ���ȡ���10���ɶ���洢λ����*/
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
