#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    int n,x,y,z;
    int value;
    int flag;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d %d %d",&x,&y,&z);
        flag=0;
        int a,b;
        for(a=9;a>0 && flag==0;a--)
        {
            for(b=9;b>=0 && flag==0;b--)
            {
                if((a*10000+x*1000+y*100+z*10+b)%n==0)
                {
                    value=(a*10000+x*1000+y*100+z*10+b)/n;
                    printf("%d %d %d\n",a,b,value);
                    flag=1;
                }
            }
        }
        if(flag==0)
        {
            printf("0\n");
        }
    }
    return 0;
}
