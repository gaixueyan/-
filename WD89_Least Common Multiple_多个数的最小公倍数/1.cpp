#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    int n,m,a,b,t,r;
    int aa,bb;
    int i,j,k;
    scanf("%d",&m);
    for(j=0; j<m; j++)
    {
        scanf("%d",&n);
        a=1;
        b=1;
        for(i=0; i<n; i++)
        {
            scanf("%d",&b);//������󹫹���С��������һ��һ�����룬������߼����֮ǰ��������С������
            if(b>a)
            {
                r=a;
                a=b;
                b=r;
            }
            if(b==0)
            {
                a=0;
            }
            else
            {
                aa=a;
                bb=b;
                while(b!=0)
                {
                    t=a%b;
                    a=b;
                    b=t;
                }
                a=aa/a*bb;//�������߼����ȳ˺����Ϊʵ���ȳ���ˣ�Ϊ�˷�ֹ������
            }
        }
        printf("%d\n",a);
    }
    return 0;
}
