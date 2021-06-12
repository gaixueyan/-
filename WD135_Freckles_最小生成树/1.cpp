#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
#define N 102

struct Dian
{
    float x;
    float y;
};
struct Dian dian[N];
int n;
struct Bian
{
    int qi;
    int zhi;
    float chang;

};
struct Bian bian[502];
int sizebian;
int tree[N];

void init()
{
    for(int i=0;i<n;i++)
    {
        tree[i]=-1;
    }
}

bool cmp(struct Bian a,struct Bian b)
{
    if(a.chang<=b.chang)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool liantong()
{
    int i;
    int sum;
    sum=0;
    for(i=0;i<n;i++)
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

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%f %f",&dian[i].x,&dian[i].y);
    }
    sizebian=0;
    float x2,y2;

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            bian[sizebian].qi=i;
            bian[sizebian].zhi=j;
            x2=(dian[i].x-dian[j].x)*(dian[i].x-dian[j].x);
            y2=(dian[i].y-dian[j].y)*(dian[i].y-dian[j].y);
            bian[sizebian].chang=sqrt(x2+y2);
            sizebian++;
        }
    }
    sort(bian,bian+sizebian,cmp);
    init();
    i=0;
    float result=0.00;
    int roota,rootb;
    while(!liantong())
    {
        roota=findroot(bian[i].qi);
        rootb=findroot(bian[i].zhi);
        if(roota!=rootb)
        {
            tree[rootb]=roota;
            result=result+bian[i].chang;
        }
        i++;
    }
    printf("%.2f\n",result);
    return 0;
}
