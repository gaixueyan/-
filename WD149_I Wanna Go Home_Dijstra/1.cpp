#include<iostream>
#include<stdio.h>
using namespace std;
#include<vector>
//Dijstra不用担心两点之间多条路的情况，Flyod输入时要比较
int city[602];
bool get[602];
struct Edge
{
    int next;
    int etime;
};
int gtime[602];
vector<Edge> edge[602];
void init()
{
    int i;
    for(i=0;i<602;i++)
    {
        city[i]=0;
        get[i]=false;
        gtime[i]=-1;
        edge[i].clear();
    }
}

int main()
{
    int n,m;
    int a,b,t;
    int i,j,k;
    while(cin>>n>>m&&n!=0)
    {
        init();
        while(m!=0)
        {
            scanf("%d %d %d",&a,&b,&t);
            struct Edge tmp;
            tmp.etime=t;
            tmp.next=b;
            edge[a].push_back(tmp);
            tmp.next=a;
            edge[b].push_back(tmp);
            m--;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&city[i]);//数组输入（字符串除外），也要加&
        }
        int zhongdian;
        zhongdian=1;
        get[zhongdian]=true;
        gtime[zhongdian]=0;
        int nextj,timej;
        for(i=1;i<n;i++)//依次确定i个点
        {
            for(j=0;j<edge[zhongdian].size();j++)//与i无关，应该只出现zhongdian
            {
                nextj=edge[zhongdian][j].next;
                timej=edge[zhongdian][j].etime;
                if(get[nextj])continue;
                if(city[zhongdian]==city[2] && city[nextj]==city[1])continue;
                if(gtime[nextj]=-1 || gtime[nextj]>gtime[zhongdian]+timej)
                {
                    gtime[nextj]=gtime[zhongdian]+timej;
                }
            }
            int mintime=123123123;
            for(j=1;j<=n;j++)
            {
                if(get[j])continue;
                if(gtime[j]==-1)continue;
                if(gtime[j]<mintime)
                {
                    mintime=gtime[j];
                    zhongdian=j;
                }
            }
            get[zhongdian]=true;
            if(zhongdian==2)
            {
                printf("%d\n",gtime[zhongdian]);
                break;
            }
        }
        if(!get[2])
        {
            printf("-1\n");
        }
    }
    return 0;
}
