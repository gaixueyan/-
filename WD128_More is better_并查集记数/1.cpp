#include<stdio.h>
#include<iostream>
using namespace std;
#define N 10000002

int buff[N];
int cost[N];

void init(int n)
{
    int i;
    for(i=1;i<=N;i++)
    {
        buff[i]=-1;
        cost[i]=1;
    }
}

int findroot(int a)
{
    if(buff[a]==-1)
    {
        return a;
    }
    else
    {
        int tmp;
        tmp=findroot(buff[a]);
        buff[a]=tmp;
        return tmp;
    }
}

int main()
{
    int n;
    int a,b;
    int roota,rootb;
    int i;
    int maxcost;
    while(scanf("%d",&n)!=EOF)
    {
        init(n);
        while(n!=0)
        {
            scanf("%d %d",&a,&b);
            roota=findroot(a);
            rootb=findroot(b);
            if(roota!=rootb)
            {
                buff[rootb]=roota;
                cost[roota]=cost[roota]+cost[rootb];
            }
            n--;
        }
        maxcost=1;
        for(i=1;i<=N;i++)
        {
            if(buff[i]==-1 && cost[i]>maxcost)
            {
                maxcost=cost[i];
            }
        }
        printf("%d\n",maxcost);
    }
    return 0;
}
