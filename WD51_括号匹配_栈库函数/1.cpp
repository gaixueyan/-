#include<stdio.h>
#include<stdlib.h>
#include<stack>//栈标准模板库，用set，sort，stack头文件时必须声明标准命名空间using namespace std;
using namespace std;
#include<string.h>
int main()
{
    char input[105];
    stack<int> zuo;//stack声明栈的时候不用给大小
    stack<int> you;
    stack<int> zuo2;
    stack<int> you2;
    int i,n;
    int r;
    while(scanf("%s",input)!=EOF)
    {
        n=strlen(input);
        for(i=0;i<n;i++)
        {
            if(input[i]=='(')
            {
                zuo.push(i);
            }
            else if(input[i]==')')
            {
                if(!zuo.empty())
                {
                    zuo.pop();
                }
                else
                {
                    you.push(i);
                }
            }
        }
        while(!zuo.empty())//栈颠倒
        {
            r=zuo.top();
            zuo.pop();//pop是丢掉，不能拿出来给别人赋值，用top才行
            zuo2.push(r);
        }
        while(!you.empty())//栈颠倒
        {
            r=you.top();
            you.pop();
            you2.push(r);
        }
        printf("%s\n",input);
        for(i=0;i<n;i++)
        {
            if(!you2.empty() && you2.top()==i)
            {
                printf("?");
                you2.pop();
            }
            else if(!zuo2.empty() && zuo2.top()==i)
            {
                printf("$");
                zuo2.pop();
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
