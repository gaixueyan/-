#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
#define N 102

struct Edge
{
    int next;
    int cost;
};
vector<Edge> edge[N];
bool get[N];
int cost[N];
void init()
{
    int i;
    for(i=0;i<N;i++)
    {
        edge[i].clear();
        get[i]=false;
        cost[i]=-1;//-1���ɴ�
    }
    get[1]=true;
    cost[1]=0;
}

int main()
{
    int i,j,k;
    int a,b,c;
    int n,m;//n��,m��
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0 && m==0)
        {
            return 0;
        }
        init();
        while(m>0)
        {
            scanf("%d %d %d",&a,&b,&c);
            struct Edge tmp;
            tmp.cost=c;
            tmp.next=b;
            edge[a].push_back(tmp);
            tmp.next=a;
            edge[b].push_back(tmp);
            m--;
        }
        int zhongdian=1;
        int t,c;
        int mincost;
        for(i=1;i<n;i++)
        {
            for(j=0;j<edge[zhongdian].size();j++)
            {
                t=edge[zhongdian][j].next;//vector�ڲ������飿��������
                c=edge[zhongdian][j].cost;
                if(get[t])
                {
                    continue;
                }
                if(cost[t]=-1 || cost[zhongdian]+c<cost[t])
                {
                    cost[t]=cost[zhongdian]+c;
                }
            }
            mincost=123123123;
            for(j=1;j<=n;j++)
            {
                if(get[j])continue;//break�ǵõ�������������ѭ�����˳�for��continue���˳����for��ֱ�ӿ�ʼ��һ��for
                if(cost[j]<mincost)
                {
                    mincost=cost[j];
                    zhongdian=j;
                }
            }
            get[zhongdian]=true;
        }
        printf("%d\n",cost[n]);
    }
    return 0;
}
