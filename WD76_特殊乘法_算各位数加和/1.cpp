#include<stdio.h>
#include<iostream>
using namespace std;

int geweihe(int shu)
{
    int result=0;
    while(shu!=0)
    {
        result=result+shu%10;
        shu=shu/10;
    }
    return result;
}

int main()
{
    int a,b;//int占32位的时候，最大可以赋值为：2147483647，是2开头的十位数哦
    int ahe,bhe;
    int result;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        ahe=geweihe(a);
        bhe=geweihe(b);
        result=ahe*bhe;
        printf("%d\n",result);
    }
    return 0;
}
