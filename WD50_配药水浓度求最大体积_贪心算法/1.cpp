//cout<<fixed<<setprecision(2)<<n;�ǿ���n��С��λ�������������빦�ܡ�ȥ��fixed�����þ��ȣ�С��λ������ͷ�ļ�#include <iomanip>
//�������������printf��������λС��������n+0.005��Ȼ�������ֹ��.2f
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
        sort(pi,pi+n);//��С��������
        i=0;
        flag=1;
        while(flag==1 && i<n)
        {
            flag=0;
            if(((pi[i]+nongdu*sum)/(1+sum))<=w)//С�ڵ���Ŷ
            {
                flag=1;
                nongdu=(pi[i]+nongdu*sum)/(1+sum);
                sum++;
            }
            i++;
        }
        nongdu=nongdu/100;
        cout<<sum*v<<" "<<fixed<<setprecision(2)<<nongdu<<endl;//setprecision������������
        c--;
    }
    return 0;
}
