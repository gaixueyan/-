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
    int a,b;//intռ32λ��ʱ�������Ը�ֵΪ��2147483647����2��ͷ��ʮλ��Ŷ
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
