#include<iostream>
using namespace std;
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<stack>

stack<int> shu;
int main()
{
    int n;
    int i;
    char s;
    int a;
    scanf("%d",&n);
    while(n!=0)//合起来的写法是：while (scanf("%d", &n)==1 && n!=0)，while(scanf("%d",&n)!=0)是错的，判断的是scanf函数返回值
    {
        for(i=0;i<n;i++)
        {
            //scanf("%c",&s);
            cin>>s;//只有cin加scanf("d",&a)能顺利接收P 5这种数据，两个scanf崩，下面是区别，还是迷惑？
            //对于字符：cin的输入忽略空格和回车。scanf("%c",&i)等价于i = getchar()，换行符和回车都会被读入。
            if(s=='P')
            {
                scanf("%d",&a);
                shu.push(a);
            }
            else if((s=='O')&&(!shu.empty()))
            {
                shu.pop();
            }
            else if(s=='A')
            {
                if(shu.empty())
                {
                    printf("E\n");
                }
                else
                {
                    printf("%d\n",shu.top());
                }
            }
        }
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}
