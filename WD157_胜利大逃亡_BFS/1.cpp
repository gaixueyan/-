#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;
#define N 52
int chengbao[N][N][N];
int a,b,c;
struct weizhi
{
	int x;
	int y;
	int z;
	int t;
};
bool fuhe(struct weizhi dian)
{
	if(dian.x<0 || dian.x>=a || dian.y<0 || dian.y>=b || dian.z<0 || dian.z>=c)
	{
		return false;
	}
	if(chengbao[dian.x][dian.y][dian.z]==0)
	{
		return true;
	}
	return false;
}
queue<weizhi> q;
int BFS()
{
	while(!q.empty())
	{
		struct weizhi dangqian;
		dangqian=q.front();
		q.pop();
		if(dangqian.x==a-1 && dangqian.y==b-1 && dangqian.z==c-1)
		{
			return dangqian.t;
		}
		struct weizhi xia;
		xia=dangqian;
		xia.t++;
		xia.x++;
		if(fuhe(xia))
		{
			q.push(xia);
			chengbao[xia.x][xia.y][xia.z]=2;
		}
		xia=dangqian;
		xia.t++;
		xia.x--;
		if(fuhe(xia))
		{
			q.push(xia);
			chengbao[xia.x][xia.y][xia.z]=2;
		}		
		xia=dangqian;
		xia.t++;
		xia.y++;
		if(fuhe(xia))
		{
			q.push(xia);
			chengbao[xia.x][xia.y][xia.z]=2;
		}
		xia=dangqian;
		xia.t++;
		xia.y--;
		if(fuhe(xia))
		{
			q.push(xia);
			chengbao[xia.x][xia.y][xia.z]=2;
		}
		xia=dangqian;
		xia.t++;
		xia.z++;
		if(fuhe(xia))
		{
			q.push(xia);
			chengbao[xia.x][xia.y][xia.z]=2;
		}	
		xia=dangqian;
		xia.t++;
		xia.z--;
		if(fuhe(xia))
		{
			q.push(xia);
			chengbao[xia.x][xia.y][xia.z]=2;
		}
	}
printf("chuqu\n");
	return -1;
}
int main()
{
    int kc;
    int t;
    int i,j,k;
	scanf("%d",&kc);
	while(kc!=0)
	{
		scanf("%d %d %d %d",&a,&b,&c,&t);
		for(i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				for(k=0;k<c;k++)
				{
					scanf("%d",&chengbao[i][j][k]);
				}
			}
		}
		while(!q.empty())
		{
			q.pop();
		}
		int time;
		struct weizhi chushi;
		chushi.x=0;
		chushi.y=0;
		chushi.z=0;
		chushi.t=0;
		q.push(chushi);
		chengbao[0][0][0]=2;
		time=BFS();
		if(time<=t)
		{
			printf("%d\n",time);
		}
		else
		{
			printf("-1\n");
		}
		kc--;
	}
    return 0;
}
