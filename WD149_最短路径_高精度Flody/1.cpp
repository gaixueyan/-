#include<stdio.h>
#include<iostream>
using namespace std;
#define N 102
#define MOD 100000
struct bigint
{
    int data[152];
    int sizedata;
};
struct bigint bian[N][N];
struct bigint chang;
void init()
{
    int i,j,k;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            for(k=0;k<152;k++)
            {
                bian[i][j].data[k]=0;
            }
            bian[i][j].data[0]=-1;
            bian[i][j].sizedata=1;
        }
        bian[i][i].data[0]=0;
        bian[i][i].sizedata=1;
    }
}

struct bigint add(struct bigint a,struct bigint b)
{
    int i,r;
    struct bigint sum;
    for(i=0;i<152;i++)
    {
        sum.data[i]=0;
    }
    sum.sizedata=0;
    for(i=0;i<a.sizedata || i<b.sizedata;i++)
    {
        r=sum.data[i]+a.data[i]+b.data[i];
        sum.data[i]=r%10;
        sum.data[i+1]=r/10;
        sum.sizedata++;
    }
    if(sum.data[sum.sizedata]!=0)
    {
        sum.sizedata++;
    }
    return sum;
}

struct bigint cheng(struct bigint a,int b)
{
    struct bigint result;
    int i,r;
    for(i=0;i<152;i++)
    {
        result.data[i]=0;
    }
    result.sizedata=0;
    for(i=0;i<a.sizedata;i++)
    {
        r=b*a.data[i]+result.data[i];
        result.data[i]=r%10;
        result.data[i+1]=r/10;
        result.sizedata++;
    }
    r=result.data[result.sizedata];
    while(r!=0)
    {
        result.data[result.sizedata]=r%10;
        r=r/10;
        result.sizedata++;
    }
    return result;
}

bool xiaoyu(struct bigint a,struct bigint b)
{
    if(a.sizedata<b.sizedata)return true;
    if(a.sizedata>b.sizedata)return false;
    int i;
    for(i=a.sizedata-1;i>=0;i--)
    {
        if(a.data[i]<b.data[i])return true;
        if(a.data[i]>b.data[i])return false;
    }
    return false;
}

int main()
{
    int a,b;
    int n,m;//n城市从0到n-1,m道路从0到m-1
    scanf("%d %d",&n,&m);
    init();
    chang.data[0]=1;
    chang.sizedata=1;
    int i,j,k;
    while(m!=0)
    {
        scanf("%d %d",&a,&b);
        for(i=0;i<chang.sizedata;i++)
        {
            bian[a][b].data[i]=bian[b][a].data[i]=chang.data[i];
        }
        bian[a][b].sizedata=bian[b][a].sizedata=chang.sizedata;
        chang=cheng(chang,2);//chang=chang*2
        m--;
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(bian[i][k].data[0]==-1 || bian[k][j].data[0]==-1)continue;
                if(bian[i][j].data[0]==-1 || xiaoyu(add(bian[i][k],bian[k][j]),bian[i][j]))
                {
                    bian[i][j]=add(bian[i][k],bian[k][j]);
                }
            }
        }
    }
    int flag;
    for(i=1;i<n;i++)
    {
        if(bian[0][i].sizedata>4)
        {
            flag=0;
            for(j=4;j>=0;j--)
            {
                if(bian[0][i].data[j]!=0)
                {
                    flag=1;
                }
                if(flag==1)
                {
                    printf("%d",bian[0][i].data[j]);
                }
            }
            printf(" ");
        }
        else
        {
            for(j=bian[0][i].sizedata-1;j>=0;j--)
            {
                printf("%d",bian[0][i].data[j]);
            }
            printf(" ");
        }
    }
    return 0;
}
