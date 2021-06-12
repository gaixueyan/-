#include<stdio.h>
using namespace std;
#include<iostream>
#include<queue>
#include<vector>
#define N 102

queue<int> q;
vector<int> edge[N];
int rudu[N];
int sum;
void init()
{
    while(!q.empty())
    {
        q.pop();
    }
    int i;
    for(i=0;i<N;i++)
    {
        edge[i].clear();
        rudu[i]=0;
    }
    sum=0;
}

int main()
{
    int n,m;
    int a,b;
    while(scanf("%d %d",&n,&m)!=EOF && n!=0)
    {
        init();
        while(m!=0)
        {
            scanf("%d %d",&a,&b);
            rudu[b]++;
            edge[a].push_back(b);
            m--;
        }
        int i;
        int r;
        for(i=0;i<n;i++)
        {
            if(rudu[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            r=q.front();
            q.pop();
            sum++;
            for(i=0;i<edge[r].size();i++)
            {
                rudu[edge[r][i]]--;
                if(rudu[edge[r][i]]==0)
                {
                    q.push(edge[r][i]);
                }
            }
        }
        if(sum==n)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
