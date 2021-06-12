#include<stdio.h>
#include<iostream>
using namespace std;
#define N 1002

int sizename;
char name[N][5];
int tree[N];
int shu[N];
int cost[N];
int he[N];
int result[102];

void init()
{
    int i;
    for(i=0;i<N;i++)
    {
        tree[i]=-1;
        shu[i]=1;
        cost[i]=0;
        he[i]=0;
    }
    sizename=0;
}

int findname(char a[])
{
    int i;
    for(i=0;i<sizename;i++)
    {
        if(name[i][0]==a[0] && name[i][1]==a[1] &&name[i][2]==a[2])
        {
            return i;
        }
    }
    name[sizename][0]=a[0];
    name[sizename][1]=a[1];
    name[sizename][2]=a[2];
    sizename++;
    return sizename-1;
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
    int i;
    int sum;
    int n,k;
    char stra[5];//姓名是三个字，但字符串存储至少需要4个位置，'\0'结尾也要存啊
    char strb[5];
    int a,b,c;
    int roota,rootb;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        init();
        while(n!=0)
        {
            scanf("%s %s %d",stra,strb,&c);
            a=findname(stra);
            b=findname(strb);
            cost[a]=cost[a]+c;
            cost[b]=cost[b]+c;
            roota=findroot(a);
            rootb=findroot(b);
            if(roota==rootb)
            {
                he[roota]=he[roota]+c;
                if(roota==a && cost[b]>cost[a])
                {
                    tree[a]=b;
                    tree[b]=-1;
                    shu[b]=shu[a];
                    he[b]=he[a];
                }
                else if(roota==b && cost[a]>cost[b])
                {
                    tree[b]=a;
                    tree[a]=-1;
                    shu[a]=shu[b];
                    he[a]=he[b];
                }
                else if(cost[a]>cost[b] && cost[a]>cost[roota])
                {
                    tree[roota]=a;
                    tree[a]=-1;
                    shu[a]=shu[roota];
                    he[a]=he[roota];
                }
                else if(cost[b]>cost[a] && cost[b]>cost[roota])
                {
                    tree[roota]=b;
                    tree[b]=-1;
                    shu[b]=shu[roota];
                    he[b]=he[roota];
                }
            }
            if(roota!=rootb)
            {
                if(cost[roota]>=cost[rootb])
                {
                    tree[rootb]=roota;
                    shu[roota]=shu[roota]+shu[rootb];
                    he[roota]=he[roota]+he[rootb]+c;
                }
                else if(cost[rootb]>cost[roota])
                {
                    tree[roota]=rootb;
                    shu[rootb]=shu[roota]+shu[rootb];
                    he[rootb]=he[roota]+he[rootb]+c;
                }
                if(roota==a && cost[b]>cost[a])
                {
                    tree[a]=b;
                    tree[b]=-1;
                    shu[b]=shu[a];
                    he[b]=he[a];
                }
                else if(roota==b && cost[a]>cost[b])
                {
                    tree[b]=a;
                    tree[a]=-1;
                    shu[a]=shu[b];
                    he[a]=he[b];
                }
                else if(cost[a]>cost[b] && cost[a]>cost[roota])
                {
                    tree[roota]=a;
                    tree[a]=-1;
                    shu[a]=shu[roota];
                    he[a]=he[roota];
                }
                else if(cost[b]>cost[a] && cost[b]>cost[roota])
                {
                    tree[roota]=b;
                    tree[b]=-1;
                    shu[b]=shu[roota];
                    he[b]=he[roota];
                }
            }
            n--;
        }
        sum=0;
        for(i=0;i<sizename;i++)
        {
            printf("name= %s tree= %d  shu= %d  he= %d cost= %d\n",name[i],tree[i],shu[i],he[i],cost[i]);
            if(tree[i]==-1 && shu[i]>2 && he[i]>k)
            {
                result[sum]=i;
                sum++;
            }
        }
        printf("%d\n",sum);
        for(i=0;i<sum;i++)
        {
            printf("%s %d\n",name[result[i]],shu[result[i]]);
        }
    }
    return 0;
}
