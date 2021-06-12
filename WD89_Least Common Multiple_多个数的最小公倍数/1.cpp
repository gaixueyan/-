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
            scanf("%d",&b);//多个数求公共最小公倍数，一个一个输入，边输入边计算和之前的数的最小公倍数
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
                a=aa/a*bb;//这里由逻辑上先乘后除改为实际先除后乘，为了防止相乘溢出
            }
        }
        printf("%d\n",a);
    }
    return 0;
}
