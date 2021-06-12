#include<stdio.h>
#include<iostream>
using namespace std;

int buff[102][102];
void init()
{
    int i,j;
    for(i=0;i<102;i++)
    {
        for(j=0;j<102;j++)
        {
            if(i==j)
            {
                buff[i][j]=0;
            }
            else
            {
                buff[i][j]=-1;
            }
        }
    }
}

int main()
{
    int i,j,k;
    int n,m;
    int a,b,c;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0 && m==0)
        {
            return 0;
        }
        init();
        while(m!=0)
        {
            scanf("%d %d %d",&a,&b,&c);
            buff[a][b]=c;
            buff[b][a]=c;
            m--;
        }
        for(k=1;k<=n;k++)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    if(buff[i][k]==-1 || buff[k][j]==-1)
                    {
                        continue;
                    }
                    if(buff[i][j]==-1 || buff[i][k]+buff[k][j]<buff[i][j])
                    {
                        buff[i][j]=buff[i][k]+buff[k][j];
                    }
                }
            }
        }
        printf("%d\n",buff[1][n]);
    }
    return 0;
}
