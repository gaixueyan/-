#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct jiayouzhan
{
    double di;//距离
    double p;//每升油价格
}buf[502];
bool cmp(jiayouzhan x,jiayouzhan y)
{
    if(x.di<=y.di) return true;
    else return false;
}
int main()
{
    double c,d,da;//c油箱容量，d终点距离，da每升油公里数
    int n;//n加油站数
    double gone=0;//已经走的距离
    double cost=0;//已经花的钱
    double you=0;//油箱里的油
    int now=0;//目前的加油站
    cin>>c>>d>>da>>n;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>buf[i].p>>buf[i].di;
    }
    sort(buf,buf+n,cmp);//n必须是int型的
    int flag=1;
    int xiao=0;
    while(flag)//不确定能不能到终点，还没到终点，能走到下一个加油站
    {
        flag=0;
        xiao=0;
        for(i=0;i<n;i++)
        {
            if(buf[i].di>gone && buf[i].di<=gone+c*da && buf[i].p<=buf[now].p)
            {
                if(you*da >= (buf[i].di-buf[now].di))
                {
                    you=you-(buf[i].di-buf[now].di)/da;
                    gone=buf[i].di;
                    now=i;
                    //cout<<"没加油，直接到达下一个便宜的"<<now<<"cost"<<cost<<endl;
                }
                else
                {
                    cost=cost+((buf[i].di-buf[now].di)/da-you)*buf[now].p;
                    gone=buf[i].di;
                    now=i;
                    you=0;
                    //cout<<"加油，到达下一个便宜的"<<now<<"cost"<<cost<<endl;
                }
                xiao=1;
                flag=1;
                break;
            }
        }
        if(xiao==0)
        {
            if(c*da >= (d-gone))//走到终点
            {
                if(you*da >= (d-gone))
                {
                    gone=d;
                    you=you-(d-buf[now].di)/da;
                    //cout<<"没加油到终点"<<now<<"cost"<<cost<<endl;
                }
                else                {
                    cost=cost+(d-buf[now].di)/da*buf[now].p;
                    gone=d;
                    you=0;
                    //cout<<"加油之后到终点"<<now<<"cost"<<cost<<endl;
                }
            }
            else if((c*da < (d-buf[now].di)) && now+1>=n)//走不到终点
            {
                cost=cost+(c-you)*buf[now].p;
                gone=gone+c*da;
                you=0;
                //cout<<"到不了终点"<<"cost"<<cost<<endl;
            }
            else if(c*da < (buf[now+1].di-buf[now].di))
            {
                cost=cost+(c-you)*buf[now].p;
                gone=gone+c*da;
                you=0;
            }
            else//走到下一个
            {
                cost=cost+(c-you)*buf[now].p;
                you=c;
                you=you-(buf[now+1].di-buf[now].di)/da;
                gone=buf[now+1].di;
                now=now+1;
                flag=1;
                //cout<<"都大，加满油到下一个站"<<now<<"cost"<<cost<<endl;
            }
        }
    }
    if(gone == d)
    {
        printf("%.2lf\n",cost);//double输入必须scanf("%lf",&n)，输出则%lf,%f均可
    }
    else
    {
        printf("The maximum travel distance = %.2lf\n",gone);
    }
    return 0;
}
