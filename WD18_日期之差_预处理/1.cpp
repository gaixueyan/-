#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int buf[5001][13][32];
bool run(int year)
{
    if(year%400==0)return true;
    if(year%4==0 && year%100!=0)return true;
    return false;
}
int tianshu[12][2]=
{
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31
};

void jisuan()//计算0000年~5000年中每一天与0000年01月01日差几天（累加天数并赋值）
{
    int sum=0;
    int i,j,k,r;
    for(i=0;i<5000;i++)//这个for循环比示例的while漂亮
    {
        for(j=0;j<12;j++)
        {
            r=run(i);
            for(k=0;k<tianshu[j][r];k++)
            {
                buf[i][j][k]=sum;
                sum=sum+1;
            }
        }
    }
}
int main()
{
    jisuan();
    int year1,month1,day1,year2,month2,day2;
    while(scanf("%4d%2d%2d",&year1,&month1,&day1)!=EOF)
    {
        scanf("%4d%2d%2d",&year2,&month2,&day2);
        printf("num1:%d\n",buf[year1][month1-1][day1-1]);
        printf("num2:%d\n",buf[year2][month2-1][day2-1]);
        printf("%d",abs(buf[year1][month1-1][day1-1]-buf[year2][month2-1][day2-1])+1);
    }
    return 0;
}
