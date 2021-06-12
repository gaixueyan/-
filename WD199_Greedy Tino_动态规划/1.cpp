#include<stdio.h>
#include<iostream>
using namespace std;
#define OFFSET 2000
int weight[105];
int d[105][4005];
int sanmax(int a,int b,int c)
{
    if(a>=b && a>=c)return a;
    if(b>=a && b>=c)return b;
    if(c>=a && c>=b)return c;
}
int main()
{
    int zu,n;
    int i,j;
    int di=1;
    scanf("%d",&zu);
    while(zu!=0)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&weight[i]);
        }
        for(j=0;j<4005;j++)
        {
            d[0][j]=-999999;
        }
        d[0][OFFSET]=0;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<OFFSET+2000;j++)
            {
                d[i][j]=sanmax(d[i-1][j-weight[i]]+weight[i],d[i-1][j+weight[i]]+weight[i],d[i-1][j]);
                //printf("d[%d][%d]=%d\n",i,j,d[i][j]);
            }
        }
        printf("Case%d:%d\n",di,d[n][OFFSET]/2);
        zu--;
        di++;
    }
    return 0;
}
