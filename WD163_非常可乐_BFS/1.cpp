#include<stdio.h>
#include<iostream>
using namespace std;
#include<queue>
#define V 105
int mark[V][V][V];
struct zhuangtai
{
    int x,y,z;
    int t;
};
queue<zhuangtai> q;
int s,m,n;
bool pingjun(zhuangtai tmp)
{
    int a,b,c;
    a=tmp.x;
    b=tmp.y;
    c=tmp.z;
    if(a*2==s && b*2==s)
        return true;
    if(a*2==s && c*2==s)
        return true;
    if(b*2==s && c*2==s)
        return true;
    return false;
}
zhuangtai dao(zhuangtai tmp,int from,int to)
{
    if(from==1 && to==2)
    {
        if(tmp.x==0)return tmp;
        if(tmp.x+tmp.y>m)
        {
            tmp.x=tmp.x+tmp.y-m;
            tmp.y=m;
        }
        else
        {
            tmp.y=tmp.x+tmp.y;
            tmp.x=0;
        }
    }
    else if(from==2 && to==1)
    {
        if(tmp.y==0)return tmp;
        tmp.x=tmp.x+tmp.y;
        tmp.y=0;
    }
    else if(from==1 && to==3)
    {
        if(tmp.x==0)return tmp;
        if(tmp.x+tmp.y>n)
        {
            tmp.x=tmp.x+tmp.z-n;
            tmp.z=n;
        }
        else
        {
            tmp.z=tmp.x+tmp.z;
            tmp.x=0;
        }
    }
    else if(from==3 && to==1)
    {
        if(tmp.z==0)return tmp;
        tmp.x=tmp.x+tmp.z;
        tmp.z=0;
    }
    else if(from==2 && to==3)
    {

        if(tmp.y==0)return tmp;
        if(tmp.y+tmp.z>n)
        {
            tmp.y=tmp.y+tmp.z-n;
            tmp.z=n;
        }
        else
        {
printf("zheli2to3\n");
            tmp.z=tmp.y+tmp.z;
            tmp.y=0;
        }
    }
    else if(from==3 && to==2)
    {
        if(tmp.z==0)return tmp;
        if(tmp.y+tmp.z>m)
        {
            tmp.z=tmp.y+tmp.z-m;
            tmp.y=m;
        }
        else
        {
            tmp.y=tmp.y+tmp.z;
            tmp.z=0;
        }
    }
    return tmp;
}
int BFS()
{
    int a,b,c;
    zhuangtai tmp;
    zhuangtai next;
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        if(pingjun(tmp))
        {
            return tmp.t;
        }
        next=dao(tmp,1,2);//接收到的数不能在一轮中途变
        if(!mark[next.x][next.y][next.z])
        {
            next.t=next.t+1;
            mark[next.x][next.y][next.z]=1;
            q.push(next);
        }
        next=dao(tmp,2,1);
        if(!mark[next.x][next.y][next.z])
        {
            next.t=next.t+1;
            mark[next.x][next.y][next.z]=1;
            q.push(next);
        }
        next=dao(tmp,1,3);
        if(!mark[next.x][next.y][next.z])
        {
            next.t=next.t+1;
            mark[next.x][next.y][next.z]=1;
            q.push(next);
        }
        next=dao(tmp,3,1);
        if(!mark[next.x][next.y][next.z])
        {
            next.t=next.t+1;
            mark[next.x][next.y][next.z]=1;
            q.push(next);
        }
        next=dao(tmp,2,3);
        if(!mark[next.x][next.y][next.z])
        {
            next.t=next.t+1;
            mark[next.x][next.y][next.z]=1;
            q.push(next);
        }
        next=dao(tmp,3,2);
        if(!mark[next.x][next.y][next.z])
        {
            next.t=next.t+1;
            mark[next.x][next.y][next.z]=1;
            q.push(next);
        }
    }
    return -1;
}



int main()
{
    int i,j,k;
    while(scanf("%d %d %d",&s,&m,&n)!=EOF)
    {
        if(s==0 && n==0 && m==0)
            return 0;
        if(s%2==1)
        {
            printf("NO\n");
        }
        else
        {
            while(!q.empty())
            {
                q.pop();
            }
            for(i=0; i<s; i++)
            {
                for(j=0; j<s; j++)
                {
                    for(k=0; k<s; k++)
                    {
                        mark[i][j][k]=0;
                    }
                }
            }
            zhuangtai tmp;
            tmp.x=s;
            tmp.y=tmp.z=0;
            tmp.t=0;
            q.push(tmp);
            mark[s][0][0]=1;
            int result=BFS();
            if(result==-1)
            {
                printf("NO\n");
            }
            else
            {
                printf("%d\n",result);
            }
        }

    }
    return 0;
}
