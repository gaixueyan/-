#include<stdio.h>
#include<iostream>
using namespace std;

int buff[1002];

void init(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        buff[i]=-1;
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
        int root;
        root=findroot(buff[a]);
        buff[a]=root;
        return root;
    }
}

int main()
{
    int a,b;
    int roota,rootb;
    int n,m;
    int i;
    int sum;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        init(n);
        while(m!=0)
        {
            scanf("%d %d",&a,&b);
            roota=findroot(a);
            rootb=findroot(b);
            if(roota!=rootb)
            {
                buff[rootb]=roota;
            }
            m--;
        }
        sum=0;
        for(i=1;i<=n;i++)
        {
            if(buff[i]==-1)
            {
                sum++;
            }
        }
        if(sum==1)
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
