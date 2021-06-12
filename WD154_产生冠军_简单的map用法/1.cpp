#include<map>//STL的都不加.h
#include<iostream>
#include<stdio.h>
#include<cstring>//字符串比较好用
using namespace std;
/*
第一个域称为关键字(key)，每个关键字只能在map中出现一次；
第二个域称为该关键字的值(value)；
*/

/*
iter=name.find("Alice");或 iter = name.find(a);
if(iter != name.end())
cout<<"Find, the value is"<<iter->second;
else
cout<<"Do not Find";
(当所查找的关键key出现时，它返回数据所在对象的位置，如果沒有，返回iter与end函数的值相同。)
*/

map<string,int> name;
int beidabai[2002];
void init()
{
    name.clear();
    int i;
    for(i=0;i<2002;i++)
    {
        beidabai[i]=0;
    }
}

int main()
{
    string a,b;
    int n;
    int sum;
    while(scanf("%d",&n)!=EOF && n!=0)
    {
        sum=1;
        init();
        while(n!=0)
        {
            cin>>a>>b;
            if(!name[a])//把值value从1开始编号，这样一旦返回的值是0(默认编号)就知道没编过号了。正常是用find函数，见上
            {
                name[a]=sum;
                sum++;
            }
            if(!name[b])
            {
                name[b]=sum;
                sum++;
            }
            beidabai[name[b]]++;
            n--;
        }
        int i;
        int guanjun=0;
        for(i=1;i<sum;i++)
        {
            if(beidabai[i]==0)
            {
                guanjun++;
            }
        }
        if(guanjun==1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
