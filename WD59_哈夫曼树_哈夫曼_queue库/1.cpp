#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>
#include<queue>

priority_queue<int, vector<int>, greater<int> >Q;//用queue库函数充当堆，快速取出集合中最大/最小的元素
int main()
{
    int n;
    int quan;
    int i;
    int result;
    int a,b;
    while(scanf("%d",&n)!=EOF)
    {
        while(!Q.empty())Q.pop();
        result=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&quan);
            Q.push(quan);
        }
        while(Q.size()>1)
        {
            a=Q.top();
            Q.pop();
            b=Q.top();
            Q.pop();
            result=result+a+b;
            Q.push(a+b);
        }
        printf("%d\n",result);
    }
    return 0;
}
