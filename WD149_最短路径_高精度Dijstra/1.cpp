#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

struct bigint//bigint a;bigint b;a=b不用定义重载运算符=，自然而然struct赋值
{
    int data[152];
    int sizedata;
    void init()
    {
        int i;
        for(i=0;i<152;i++)
        {
            data[i]=0;
        }
        sizedata=0;
    }
    struct bigint operator +(struct bigint a) const//真香定律，运算符重载真香
    {
        int i;
        struct bigint sum;
        sum.init();
        int r;
        for(i=0;i<a.sizedata || i<sizedata ;i++)
        {
            r=sum.data[i]+a.data[i]+data[i];
            sum.data[i]=r%10;
            sum.data[i+1]=r/10;
            sum.sizedata++;
        }
        if(sum.data[sum.sizedata]!=0)
        {
            sum.sizedata++;
        }
        return sum;
    }
    bigint operator * (int a)const//真香定律，运算符重载真香
    {
        int i,r;
        bigint result;
        result.init();
        for(i=0;i<sizedata;i++)
        {
            r=result.data[i]+(data[i]*a);
            result.data[i]=r%10;
            result.data[i+1]=r/10;
            result.sizedata++;
        }
        r=result.data[result.sizedata];
        while(r!=0)
        {
            result.data[result.sizedata]=r%10;
            r=r/10;
            result.sizedata++;
        }
        return result;
    }
    bool operator <(bigint a)const
    {
        if(sizedata>a.sizedata)return false;
        if(sizedata<a.sizedata)return true;
        int i;
        for(i=sizedata-1;i>=0;i--)
        {
            if(data[i]>a.data[i])return false;
            if(data[i]<a.data[i])return true;
        }
        return false;
    }
};
struct Edge
{
    int next;
    struct bigint dist;
};
vector<Edge> edge[102];
bool get[102];
struct bigint dist[102];
void init()
{
    int i;
    for(i=0;i<102;i++)
    {
        edge[i].clear();
        get[i]=false;
        dist[i].init();
        dist[i].data[0]=-1;
    }
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    init();//初始化不能缺
    struct bigint cheng;
    cheng.init();
    cheng.data[0]=1;
    cheng.sizedata=1;
    int a,b;
    struct Edge tmp;
    while(m!=0)
    {
        scanf("%d %d",&a,&b);
        tmp.dist=cheng;
        tmp.next=b;
        edge[a].push_back(tmp);
        tmp.next=a;
        edge[b].push_back(tmp);
        cheng=cheng*2;
        m--;
    }
    int i,j,k;
    get[0]=true;
    dist[0].data[0]=0;
    dist[0].sizedata=1;
    int zhongdian;
    zhongdian=0;
    int t;
    struct bigint d;
    for(i=1;i<n;i++)
    {
        for(j=0;j<edge[zhongdian].size();j++)
        {
            t=edge[zhongdian][j].next;
            d=edge[zhongdian][j].dist;
            if(get[t])continue;
            if(dist[t].data[0]==-1 || dist[zhongdian]+d<dist[t])
            {
                dist[t]=dist[zhongdian]+d;
            }
        }
        bigint mindist;
        mindist.sizedata=150;
        for(j=0;j<mindist.sizedata;j++)
        {
            mindist.data[j]=9;
        }
        for(j=0;j<n;j++)
        {
            if(get[j])continue;
            if(dist[j].data[0]==-1)continue;//这里别忘
            if(dist[j]<mindist)
            {
                zhongdian=j;
                mindist=dist[j];
            }
        }
        get[zhongdian]=true;
    }
    int flag;
    for(i=1;i<n;i++){
        if(dist[i].sizedata>4)
        {
            flag=0;
            for(j=4;j>=0;j--)
            {
                if(dist[i].data[j]>0)
                {
                    flag=1;
                }
                if(flag==1)
                {
                    printf("%d",dist[i].data[j]);
                }
            }
            printf(" ");
        }
        else
        {
            for(j=dist[i].sizedata-1;j>=0;j--)
            {
                printf("%d",dist[i].data[j]);
            }
            printf(" ");
        }
    }
    return 0;
}
