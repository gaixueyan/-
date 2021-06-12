#include<stdio.h>
#include<iostream>
using namespace std;
#include<queue>
#define N 502
#include<vector>

int rudu[N];
vector<int> edge[N];
priority_queue<int,vector<int>,greater<int> > q;

void init()
{
    while(!q.empty())
    {
        q.pop();
    }
    int i;
    for(i=0;i<N;i++)
    {
        rudu[i]=0;
        edge[i].clear();
    }
}

int main()
{
    int n,m;
    int a,b;
    scanf("%d %d",&n,&m);
    init();
    while(m!=0)
    {
        scanf("%d %d",&a,&b);
        rudu[b]++;
        edge[a].push_back(b);
        m--;
    }
    int i;
    for(i=1;i<=n;i++)
    {
        if(rudu[i]==0)
        {
            q.push(i);
        }
    }
    int r;
    int sum=0;
    while(!q.empty())
    {
        r=q.top();
        q.pop();
        sum++;
        printf("%d",r);
        if(sum!=n)
        {
            printf(" ");
        }
        for(i=0;i<edge[r].size();i++)
        {
            rudu[edge[r][i]]--;
            if(rudu[edge[r][i]]==0)
            {
                q.push(edge[r][i]);
            }
        }
    }
    return 0;
}
