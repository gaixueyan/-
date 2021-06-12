#include <iostream>
using namespace std;
int buf[102][2];//0开始时间，1结束时间
int domax(int n)
{
    int i;
    int time=0;
    for(i=0;i<n;i++)
    {
        if(buf[i][1]>time)
        {
            time=buf[i][1];
        }
    }
    return time;
}

int main()
{
    int n;
    int i;
    int time;
    int sum;
    int flag;
    int xiabiao;
    int min;
    int maxjieshu;
    cin>>n;
    while(1)
    {
        if(n==0)break;
        time=0;
        sum=0;
        xiabiao=-1;
        flag=1;
        for(i=0;i<n;i++)
        {
            cin>>buf[i][0]>>buf[i][1];
        }
        maxjieshu=domax(n);
        while(flag)
        {
            flag=0;
            min=maxjieshu;
            for(i=0;i<n;i++)
            {
                if(buf[i][0]>=time && buf[i][1]<=min)
                {
                    min=buf[i][1];
                    xiabiao=i;
                    flag=1;
                }
            }
            if(flag)
            {
                time=buf[xiabiao][1];
                sum=sum+1;
            }
        }
        cout<<sum<<endl;
        cin>>n;
    }
    return 0;
}
