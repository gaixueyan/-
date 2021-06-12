#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int weight[2005];
int dp[1005][2005];
int main()
{
    int n,k;
    int i,j;

    while(scanf("%d %d",&n,&k)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&weight[i]);
        }
        sort(weight+1,weight+1+n);//从weight[1]输入，sort也要从weight+1开始
        for(i=0;i<n;i++)
        {
            dp[0][i]=0;
            dp[i][0]=0;
            dp[i][1]=0;
        }
        for(i=1;i<=k;i++)
        {
            for(j=i*2;j<=n;j++)
            {
                if(j==i*2)
                {
                    dp[i][j]=dp[i-1][j-2]+(weight[j]-weight[j-1])*(weight[j]-weight[j-1]);
                }
                else
                {
                    dp[i][j]=min(dp[i-1][j-2]+(weight[j]-weight[j-1])*(weight[j]-weight[j-1]),dp[i][j-1]);
                }
            }
        }
        printf("%d\n",dp[k][n]);
    }
    return 0;
}
