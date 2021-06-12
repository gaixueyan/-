//cout<<fixed<<setprecision(2)<<n;是控制n的小数位数，有四舍五入功能。去掉fixed是设置精度（小数位数）。头文件#include <iomanip>
//控制四舍五入的printf方法：两位小数———n+0.005，然后输出截止到.2f
#include<iostream>
#include<algorithm>
#include <iomanip>
using namespace std;
int pi[102];
int main()
{
    int c;
    cin>>c;
    int i;
    int n,v,w;
    double nongdu;
    int sum;
    int flag;
    while(c>0)
    {
        cin>>n>>v>>w;
        for(i=0;i<n;i++)
        {
            cin>>pi[i];
        }
        nongdu=0;
        sum=0;
        sort(pi,pi+n);//从小到大排序
        i=0;
        flag=1;
        while(flag==1 && i<n)
        {
            flag=0;
            if(((pi[i]+nongdu*sum)/(1+sum))<=w)//小于等于哦
            {
                flag=1;
                nongdu=(pi[i]+nongdu*sum)/(1+sum);
                sum++;
            }
            i++;
        }
        nongdu=nongdu/100;
        cout<<sum*v<<" "<<fixed<<setprecision(2)<<nongdu<<endl;//setprecision包含四舍五入
        c--;
    }
    return 0;
}
