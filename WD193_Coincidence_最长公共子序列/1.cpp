#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
char s1[105];
char s2[105];
int dp[105][105];

int main()
{
    int sizes1,sizes2;
    int i,j;
    int maxdp;
    while(scanf("%s %s",s1,s2)!=EOF)
    {
        sizes1=strlen(s1);
        sizes2=strlen(s2);
        for(i=0;i<105;i++)
        {
            for(j=0;j<105;j++)
            {
                dp[i][j]=0;
            }
        }
        maxdp=0;
        for(i=0;i<sizes1;i++)
        {
            if(s1[i]==s2[0])
            {
                dp[i][0]=1;
                maxdp=1;
            }
        }
        for(j=0;j<sizes2;j++)
        {
            if(s1[0]==s2[j])
            {
                dp[0][j]=1;
                maxdp=1;
            }
        }
        for(i=1;i<sizes1;i++)
        {
            for(j=1;j<sizes2;j++)
            {
                if(s1[i]==s2[j])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                if(dp[i][j]>maxdp)
                {
                    maxdp=dp[i][j];
                }
            }
        }
        printf("%d\n",maxdp);
    }
    return 0;
}
