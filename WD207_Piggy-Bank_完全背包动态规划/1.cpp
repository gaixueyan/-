#include<stdio.h>
#include<iostream>
using namespace std;
#define INF 0x7fffffff//最大值
struct QIAN
{
    int value;
    int weight;
}qian[505];
int d[10005];
int main()
{
    int t,e,f;
    int beibao;
    int n;
    int i,j;
    scanf("%d",&t);
    while(t>0)
    {
        scanf("%d %d",&e,&f);
        beibao=f-e;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&qian[i].value,&qian[i].weight);
        }
        d[0]=0;
        for(j=1;j<=beibao;j++)
        {
            d[j]=INF;
        }
        for(i=1;i<=n;i++)
        {
            for(j=qian[i].weight;j<=beibao;j++)
            {
                if(d[j-qian[i].weight]!=INF)//正好满背包注意点，用if判断是否INF，结果是否合理（正好满）好判断
                {
                    d[j]=min(d[j-qian[i].weight]+qian[i].value,d[j]);//完全背包（每个物品不限量件）就必须用一维了，不然初始值d[所有i][j]赋着麻烦
                }
            }
        }
        if(d[beibao]!=INF)
        {
            printf("The minimum amount of money in the piggy-bank is %d.\n",d[beibao]);
        }
        else
        {
            printf("This is impossible.\n");
        }
        t--;
    }
    return 0;
}
