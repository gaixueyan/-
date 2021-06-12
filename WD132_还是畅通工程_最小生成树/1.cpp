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

bool liantong(int n)
{
    int sum=0;
    for(int i=1;i<=n;i++)
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
    while(scanf("%d",&n)!=EOF && n!=0)
    {
        init();
        sizelu=0;
        m=n*(n-1)/2;
        while(m!=0)
        {
            scanf("%d %d %d",&lu[sizelu].a,&lu[sizelu].b,&lu[sizelu].cost);
            sizelu++;
            m--;
        }
        sort(lu,lu+sizelu,cmp);//lu,lu+sizelu,cmp自动识别成lu[0],lu[0]+sizelu,cmp(),写了反而不好使
        i=0;
        cost=0;
        while(!liantong(n))
        {
            roota=findroot(lu[i].a);
            rootb=findroot(lu[i].b);
            if(roota!=rootb)
            {
                tree[roota]=rootb;
                cost=cost+lu[i].cost;
            }
            i++;
        }
        printf("%d\n",cost);
    }
    return 0;
}
