#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    int a,b,r,t;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        if(a>b)
        {
            r=a;
            a=b;
            b=r;
        }
        if(a==0)
        {
            printf("%d\n",b);
        }
        else if(b==0)
        {
            printf("%d\n",0);
        }
        else
        {
            t=a*b;
            while(b!=0)
            {
                r=a%b;
                a=b;
                b=r;
            }
            printf("%d\n",t/a);
        }
    }
    return 0;
}
