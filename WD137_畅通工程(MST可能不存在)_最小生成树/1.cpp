#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

struct luxing
{
    int a;
    int b;
    int cost;
}lu[502];
int sizelu;
int tree[102];

bool cmp(struct luxing x,struct luxing y)
{
    if(x.cost<=y.cost)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void init()
{
    for(int i=0;i<102;i++)
    {
        tree[i]=-1;
    }
}

int findroot(int a)
{
    if(tree[a]==-1)
    {
        return a;
    }
    else
    {
        int root;
        root=findroot(tree[a]);
        tree[a]=root;
        return root;
    }
}

bool liantong(int m)
{
    int sum=0;
    for(int i=1;i<=m;i++)
    {
        if(tree[i]==-1)
        {
            sum++;
        }
    }
    if(sum==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    int cost;
    int m;
    int i,j;
    int r0,r1,r2;
    int roota,rootb;
    while(scanf("%d %d",&n,&m)!=EOF && n!=0)
    {
        init();
        sizelu=0;
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&lu[sizelu].a,&lu[sizelu].b,&lu[sizelu].cost);
            sizelu++;
        }
        sort(lu,lu+sizelu,cmp);//lu,lu+sizelu,cmp自动识别成lu[0],lu[0]+sizelu,cmp(),写了反而不好使
        cost=0;
        for(i=0;i<n;i++)
        {
            roota=findroot(lu[i].a);
            rootb=findroot(lu[i].b);
            if(roota!=rootb)
            {
                tree[roota]=rootb;
                cost=cost+lu[i].cost;
            }
        }
        int result=liantong(m);
        if(result)
        {
            printf("%d\n",cost);
        }
        else
        {
            printf("?\n");
        }
    }
    return 0;
}
