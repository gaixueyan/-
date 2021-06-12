#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

priority_queue<int,vector<int>,greater<int> >Q;
int main()
{
    int n;
    int shu;
    int i;
    double result;
    double add;
    int a,b;
    scanf("%d",&n);
    while(n!=0)
    {
        result=0;
        while(!Q.empty())Q.pop();
        for(i=0;i<n;i++)
        {
            scanf("%d",&shu);
            Q.push(shu);
        }
        while(Q.size()>1)
        {
            a=Q.top();
            Q.pop();
            b=Q.top();
            Q.pop();
            add=a+b;
            Q.push(add);
            result=result+add;
        }
        printf("%.0f\n",result);
        scanf("%d",&n);
    }
    return 0;
}
