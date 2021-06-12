#include<stdio.h>
#include<iostream>
using namespace std;

int gcd(int a,int b)
{
    if(b==0)return a;
    else return gcd(b,a%b);//否则，返回gcd()的结果，gcd不能只调用而不返回结果
}

int main()
{
    int a,b,r;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        if(a<b)
        {
            r=a;
            a=b;
            b=r;
        }
        if(a==0)
        {
            printf("%d\n",b);
        }
        else
        {
            /*while(b!=0)
            {
                r=a%b;
                a=b;
                b=r;
            }
            printf("%d\n",a);*/
            r=gcd(a,a%b);
            printf("%d\n",r);
        }
    }
    return 0;
}
