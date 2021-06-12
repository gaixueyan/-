#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
#define N 1002
struct Edge
{
    int next;
    int distant;
    int cost;
};
vector<Edge> edge[N];
bool get[N];
int distant[N];
int cost[N];
void init()
{
    int i;
    for(i=0;i<N;i++)
    {
        edge[i].clear();
        get[i]=false;
        distant[i]=-1;
        cost[i]=-1;
    }
}

int main()
{
    int n,m;
    int s,t;//起点s，终点t
    int a,b,d,p;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0 && m==0)
        {
            return 0;
        }
        init();
        while(m!=0)
        {
            scanf("%d %d %d %d",&a,&b,&d,&p);
            struct Edge tmp;
            tmp.distant=d;
            tmp.cost=p;
            tmp.next=b;
            edge[a].push_back(tmp);
            tmp.next=a;
            edge[b].push_back(tmp);
            m--;
        }
        scanf("%d %d",&s,&t);
        get[s]=true;
        distant[s]=0;
        cost[s]=0;
        int i,j,k;
for(i=1;i<=n;i++)
{
    for(j=0;j<edge[i].size();j++)
    {
        printf("%d:",i);
        printf("next=%d dist=%d cost=%d\n",edge[i][j].next,edge[i][j].distant,edge[i][j].cost);
    }
}
        int zhongdian;
        zhongdian=s;
printf("zhongdian=%d\n",zhongdian);
        int jnext;
        int jdistant;
        int jcost;
        for(i=1;i<n;i++)
        {
            for(j=0;j<edge[zhongdian].size();j++)
            {
                jnext=edge[zhongdian][j].next;
                jdistant=edge[zhongdian][j].distant;
                jcost=edge[zhongdian][j].cost;
printf("jnext=%d jdistant=%d jcost=%d\n",jnext,jdistant,jcost);
                if(get[jnext])continue;
                if(distant[zhongdian]+jdistant==distant[jnext])
                {
                    if(cost[zhongdian]+jcost<cost[jnext])
                    {
                        cost[jnext]=cost[zhongdian]+jcost;
printf("cost改变=%d\n",cost[jnext]);
                    }
                }
                else if(distant[jnext]==-1 || distant[zhongdian]+jdistant<distant[jnext])
                {
                    distant[jnext]=distant[zhongdian]+jdistant;
                    cost[jnext]=cost[zhongdian]+jcost;
printf("dist改变%d cost改变=%d\n",distant[jnext],cost[jnext]);
                }
            }
            int mindist=123123123;
            for(j=1;j<=n;j++)
            {
                if(get[j])continue;//已拓展
                if(distant[j]==-1)continue;//还没找到通路，一定要有，不然出错很难找
                if(distant[j]<mindist)
                {
                    mindist=distant[j];
                    zhongdian=j;
                }
            }
            get[zhongdian]=true;
printf("zhongdian=%d distant=%d cost=%d\n",zhongdian,distant[zhongdian],cost[zhongdian]);
        }
        printf("%d %d\n",distant[t],cost[t]);
    }
    return 0;
}
