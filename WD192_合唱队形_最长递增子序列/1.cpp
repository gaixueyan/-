#include<stdio.h>
#include<iostream>
using namespace std;
int t[105];
int up[105];
int down[105];
int main()
{
    int n;
    int i,j;
    int maxi;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&t[i]);
        }
        for(i=0;i<n;i++)
        {
            maxi=1;
            for(j=0;j<i;j++)
            {
                if(t[j]<t[i])
                {
                    maxi=max(maxi,up[j]+1);
                }
            }
            up[i]=maxi;
        }
        for(i=n-1;i>=0;i--)
        {
            maxi=1;
            for(j=n-1;j>i;j--)
            {
                if(t[j]<t[i])
                {
                    maxi=max(maxi,down[j]+1);
                }
            }
            down[i]=maxi;
        }
        int result=0;
        for(i=0;i<n;i++)
        {
            if(up[i]+down[i]>result)
            {
                result=up[i]+down[i];
            }
        }
        printf("%d\n",n-(result-1));//题目问几个人出列，注意result是留几个，还要减了才能输出
    }
    return 0;
}
