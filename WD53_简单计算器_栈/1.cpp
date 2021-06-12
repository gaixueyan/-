#include<string.h>
#include<stdio.h>
#include<stack>
#include<iostream>
using namespace std;

char biaodashi[205];
stack<int>fuhao;//堆栈声明不写大小
stack<double>shuzi;
int weizhi;
int changdu;

int compare[4][4]={//+0 -1 *2 /3，前面的是栈顶符号，后面的是表达式当前符号，栈顶大于等于当前符号时可以运算栈
1,1,0,0,
1,1,0,0,
1,1,1,1,
1,1,1,1
};//数组赋值括号外加分号
int getshu()
{
    int result=0;
    while((biaodashi[weizhi]!=' ')&&(weizhi<changdu))
    {
        result=result*10+(biaodashi[weizhi]-'0');
        weizhi++;
    }
    return result;
}
int getfuhao()
{
    int result;
    if(biaodashi[weizhi]=='+')return 0;
    else if(biaodashi[weizhi]=='-')return 1;
    else if(biaodashi[weizhi]=='*')return 2;
    else if(biaodashi[weizhi]=='/')return 3;
    return 0;
}
double yunsuan()
{
    double result=0;
    double shu1=shuzi.top();
    shuzi.pop();
    double shu2=shuzi.top();
    shuzi.pop();
    int fu=fuhao.top();
    fuhao.pop();
    if(fu==0)result=shu1+shu2;
    else if(fu==1)result=shu2-shu1;
    else if(fu==2)result=shu1*shu2;
    else if(fu==3)result=1.000000*shu2/shu1;
    shuzi.push(result);
    return result;
}
int main()
{
    while(strcmp(gets(biaodashi),"0"))//scanf接收不了空格
    {
        while(!fuhao.empty())fuhao.pop();
        while(!shuzi.empty())shuzi.pop();
        weizhi=0;
        changdu=strlen(biaodashi);
//cout<<changdu<<"  a ";
        while(weizhi<changdu)
        {
            shuzi.push(getshu());
//cout<<shuzi.top()<<" b  ";
            weizhi++;
//cout<<weizhi<<" gai1  ";
            if(weizhi>=changdu)
                break;
            while((!fuhao.empty())&&(compare[fuhao.top()][getfuhao()]))
            {
cout<<shuzi.top()<<" c  ";
                yunsuan();
            }
            fuhao.push(getfuhao());
cout<<fuhao.top()<<"   fuaho    ";
            weizhi=weizhi+2;
        }
        while(!fuhao.empty())
        {
cout<<fuhao.top()<<" gai2  ";
//fuhao.pop();
            yunsuan();
        }
        printf("%.2f\n",shuzi.top());
    }
    return 0;
}
