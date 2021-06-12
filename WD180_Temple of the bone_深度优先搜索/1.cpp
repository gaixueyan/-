#include<stdio.h>
#include<iostream>
using namespace std;

char ditu[10][10];
int n,m,t;
int flag;

void shensou(int x,int y,int time)
{
    if(flag==1)return;
    if(time>t)return;
    if(time<t && ditu[x][y]=='D')return;
    if(time==t && ditu[x][y]=='D')
    {
        flag=1;
        return;
    }
    ditu[x][y]='X';
    if(x+1<n && ditu[x+1][y]!='X')
    {
        shensou(x+1,y,time+1);
    }
    if(y+1<m && ditu[x][y+1]!='X')
    {
        shensou(x,y+1,time+1);
    }
    if(x-1>=0 && ditu[x-1][y]!='X')
    {
        shensou(x-1,y,time+1);
    }
    if(y-1>=0 && ditu[x][y-1]!='X')
    {
        shensou(x,y-1,time+1);
    }
    ditu[x][y]='.';//退回上层（不走这步）之前，要先把这步改变的变回来
    return;
}

int main()
{
    int i,j;
    int qix,qiy;
    int zhix,zhiy;
    while(scanf("%d %d %d",&n,&m,&t)!=EOF)
    {
        getchar();
        if(n==0 && m==0 && t==0)return 0;//»òÕßbreak;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%c",&ditu[i][j]);
                if(ditu[i][j]=='S')
                {
                    qix=i;
                    qiy=j;
                }
                else if(ditu[i][j]=='D')
                {
                    zhix=i;
                    zhiy=j;
                }
            }
            getchar();
        }
        if((zhix-qix+zhiy-qiy)%2==0 && t%2==1)
        {
            printf("NO\n");
        }
        else if((zhix-qix+zhiy-qiy)%2==1 && t%2==0)
        {
            printf("NO\n");
        }
        else
        {
            flag=0;
            shensou(qix,qiy,0);
            if(flag==0)
            {
                printf("NO\n");
            }
            else
            {
                printf("YES\n");
            }
        }
    }
    return 0;
}
