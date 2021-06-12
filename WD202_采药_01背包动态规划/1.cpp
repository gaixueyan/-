#include<stdio.h>
#include<iostream>
using namespace std;
struct CY
{
    int time;
    int value;
}caoyao[105];
int d[105][1005];
int main()
{
    int t,m;
    int i,j;
    while(scanf("%d %d",&t,&m)!=EOF)
    {
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&caoyao[i].time,&caoyao[i].value);
        }
        for(i=0;i<=t;i++)
        {
            d[0][i]=0;
        }
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=t;j++)
            {
                if(caoyao[i].time>j)
                {
                    d[i][j]=d[i-1][j];
                }
                else
                {
                    d[i][j]=max(d[i-1][j-caoyao[i].time]+caoyao[i].value,d[i-1][j]);
                }
            }
        }
        printf("%d\n",d[m][t]);
    }
    return 0;
}
