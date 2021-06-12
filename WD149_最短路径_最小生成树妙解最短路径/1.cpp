/*
2^k > 2^(k-1)+2^(k-2)+2^(k-3)+...+2^2+2^0
因为2^k = 2^(k-1)+2^(k-2)+2^(k-3)+...+2^2+2^0 + 1
所以后出现的边比之前出现的所有边的长度加和都大。
所以给出一条边，当它连接的两点还没连通，就由这条边连通，因为越往后边长越大，早出现的边要用上。
所以...就从Dijstra变成了并查集
*/
#include<stdio.h>
#include<iostream>
using namespace std;
#define N 102
#define MOD 100000
int tree[N];
int bian[N][N];
int cost[N];
int n,m;
void init()
{
    int i,j;
    for(i=0;i<N;i++)
    {
        tree[i]=-1;
        cost[i]=-1;
        for(j=0;j<N;j++)
        {
            bian[i][j]=-1;
        }
    }
}
int findroot(int a)
{
    if(tree[a]==-1)return a;
    else
    {
        int root;
        root=findroot(tree[a]);
        tree[a]=root;
        return root;
    }
}
void getcost(int a,int qiancost)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(cost[i]!=-1)continue;
        if(bian[a][i]!=-1)
        {
            cost[i]=qiancost+bian[a][i];
            getcost(i,cost[i]);//这是个递归呀，用得好
        }
    }
}

int main()
{
    int a,b;
    int roota,rootb;
    scanf("%d %d",&n,&m);
    init();
    int chang=1;
    while(m!=0)
    {
        scanf("%d %d",&a,&b);
        roota=findroot(a);
        rootb=findroot(b);
        if(roota!=rootb)
        {
            tree[rootb]=roota;
            bian[a][b]=chang;
            bian[b][a]=chang;
        }
        chang=(chang*2)%MOD;
        m--;
    }
    getcost(0,0);
    int i;
    for(i=1;i<n;i++)
    {
        printf("%d\n",cost[i]);
    }
    return 0;
}
