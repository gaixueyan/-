#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int x,y,z;
        for(x=0;x<=100;x++)
        {
            if(x*5>n)
            {
                break;
            }
            for(y=0;y<=100-x;y++)
            {
                if(x*5+y*3>n)
                {
                    break;
                }
                z=100-x-y;
                if(x*5*3+y*3*3+z<=n*3)//为了避免除法/3，在不等式左右都乘3，小技巧啊
                {
                    printf("x=%d,y=%d,z=%d\n",x,y,z);
                }
            }
        }
    }
    return 0;
}
