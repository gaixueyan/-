#include<map>//STL�Ķ�����.h
#include<iostream>
#include<stdio.h>
#include<cstring>//�ַ����ȽϺ���
using namespace std;
/*
��һ�����Ϊ�ؼ���(key)��ÿ���ؼ���ֻ����map�г���һ�Σ�
�ڶ������Ϊ�ùؼ��ֵ�ֵ(value)��
*/

/*
iter=name.find("Alice");�� iter = name.find(a);
if(iter != name.end())
cout<<"Find, the value is"<<iter->second;
else
cout<<"Do not Find";
(�������ҵĹؼ�key����ʱ���������������ڶ����λ�ã�����]�У�����iter��end������ֵ��ͬ��)
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
            if(!name[a])//��ֵvalue��1��ʼ��ţ�����һ�����ص�ֵ��0(Ĭ�ϱ��)��֪��û������ˡ���������find����������
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
