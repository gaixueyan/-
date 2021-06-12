//float有效数字是6 - 7位  double是15 - 16位    所以这道题最终结果用float算就WrongAnswer了   float辣鸡

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
float buf[3][1002];//0重量，1价值，2性价比
int zhaozuida(int n)
{
    int i;
    int zuida=-1;
    float zuidaxing=0;
    for(i=0;i<n;i++)
    {
        if(buf[2][i]>zuidaxing && buf[0][i]!=0)
        {
            zuida=i;
            zuidaxing=buf[2][i];
        }
    }
    return zuida;
}

int main()
{
    int zu;
    int m,n;
    int i;
    double zhongliang;
    scanf("%d %d",&m,&n);
    while(1)
    {
        zu=0;
        if(m==-1 && n==-1)
        {
            break;
        }
        for(i=0;i<n;i++)
        {
            cin>>buf[0][i]>>buf[1][i];
            buf[2][i]=buf[0][i]*1.000/buf[1][i];
        }
        int zuida;
        zhongliang=0;
        zuida=zhaozuida(n);
        for(i=0;i<n;i++)//特殊情况，初始给0元钱，有0元钱的货。而下面的程序是剩0元钱自动停止。
        {
            if(buf[1][i]==0)
            {
                zhongliang=zhongliang+buf[0][i];
                buf[0][i]=0;
            }
        }
        while(zuida!=-1 && m!=0)
        {
            if(m>=buf[1][zuida])
            {
                m=m-buf[1][zuida];
                zhongliang=zhongliang+buf[0][zuida];
                buf[0][zuida]=0;
            }
            else
            {
                zhongliang=zhongliang+buf[2][zuida]*m;
                buf[0][zuida]=buf[0][zuida]-buf[2][zuida]*m;
                m=0;
            }
            zuida=zhaozuida(n);
        }
        //if(zu!=0)printf("\n");
        printf("%.3f\n",zhongliang);
        zu++;
        scanf("%d %d",&m,&n);
    }
    return 0;
}
