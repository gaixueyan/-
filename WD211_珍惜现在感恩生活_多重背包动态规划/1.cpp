#include<stdio.h>
#include<iostream>
using namespace std;
struct DAMI
{
    int value;
    int weight;
}dami[505];
int d[505][105];
int main()
{
    int zuc;
    int n,m;
    int p,h,c;
    int i,j;
    int erjinzhi;
    int num;
    scanf("%d",&zuc);
    while(zuc--)
    {
        scanf("%d %d",&n,&m);
        num=1;
        while(m--)
        {
            scanf("%d %d %d",&p,&h,&c);
            erjinzhi=1;
            while(erjinzhi<c)
            {
                dami[num].value=erjinzhi*p;
                dami[num].weight=erjinzhi*h;
                erjinzhi=erjinzhi*2;
                num++;
            }
            dami[num].value=c*p;
            dami[num].weight=c*h;
            num++;
        }
        for(j=0;j<=n;j++)
        {
            d[0][j]=0;
        }
        for(i=1;i<num;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(dami[i].value>j)
                {
                    d[i][j]=d[i-1][j];
                }
                else
                {
                    d[i][j]=max(d[i-1][j],d[i-1][j-dami[i].value]+dami[i].weight);
                }
            }
        }
        printf("%d\n",d[num-1][n]);
    }
    return 0;
}
