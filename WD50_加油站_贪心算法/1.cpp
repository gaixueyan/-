#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct jiayouzhan
{
    double di;//����
    double p;//ÿ���ͼ۸�
}buf[502];
bool cmp(jiayouzhan x,jiayouzhan y)
{
    if(x.di<=y.di) return true;
    else return false;
}
int main()
{
    double c,d,da;//c����������d�յ���룬daÿ���͹�����
    int n;//n����վ��
    double gone=0;//�Ѿ��ߵľ���
    double cost=0;//�Ѿ�����Ǯ
    double you=0;//���������
    int now=0;//Ŀǰ�ļ���վ
    cin>>c>>d>>da>>n;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>buf[i].p>>buf[i].di;
    }
    sort(buf,buf+n,cmp);//n������int�͵�
    int flag=1;
    int xiao=0;
    while(flag)//��ȷ���ܲ��ܵ��յ㣬��û���յ㣬���ߵ���һ������վ
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
                    //cout<<"û���ͣ�ֱ�ӵ�����һ�����˵�"<<now<<"cost"<<cost<<endl;
                }
                else
                {
                    cost=cost+((buf[i].di-buf[now].di)/da-you)*buf[now].p;
                    gone=buf[i].di;
                    now=i;
                    you=0;
                    //cout<<"���ͣ�������һ�����˵�"<<now<<"cost"<<cost<<endl;
                }
                xiao=1;
                flag=1;
                break;
            }
        }
        if(xiao==0)
        {
            if(c*da >= (d-gone))//�ߵ��յ�
            {
                if(you*da >= (d-gone))
                {
                    gone=d;
                    you=you-(d-buf[now].di)/da;
                    //cout<<"û���͵��յ�"<<now<<"cost"<<cost<<endl;
                }
                else                {
                    cost=cost+(d-buf[now].di)/da*buf[now].p;
                    gone=d;
                    you=0;
                    //cout<<"����֮���յ�"<<now<<"cost"<<cost<<endl;
                }
            }
            else if((c*da < (d-buf[now].di)) && now+1>=n)//�߲����յ�
            {
                cost=cost+(c-you)*buf[now].p;
                gone=gone+c*da;
                you=0;
                //cout<<"�������յ�"<<"cost"<<cost<<endl;
            }
            else if(c*da < (buf[now+1].di-buf[now].di))
            {
                cost=cost+(c-you)*buf[now].p;
                gone=gone+c*da;
                you=0;
            }
            else//�ߵ���һ��
            {
                cost=cost+(c-you)*buf[now].p;
                you=c;
                you=you-(buf[now+1].di-buf[now].di)/da;
                gone=buf[now+1].di;
                now=now+1;
                flag=1;
                //cout<<"���󣬼����͵���һ��վ"<<now<<"cost"<<cost<<endl;
            }
        }
    }
    if(gone == d)
    {
        printf("%.2lf\n",cost);//double�������scanf("%lf",&n)�������%lf,%f����
    }
    else
    {
        printf("The maximum travel distance = %.2lf\n",gone);
    }
    return 0;
}
