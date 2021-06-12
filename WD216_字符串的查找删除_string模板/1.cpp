#include<stdio.h>
#include<iostream>
using namespace std;
#include<string>
#include<ctype.h>

int main()
{
    char str[105];
    string a,b,c;
    gets(str);//gets函数往字符串里（char[105]）输入，string类型的输入不了
    a=str;
    int i;
    int r;
    for(i=0;i<a.size();i++)
    {
        a[i]=tolower(a[i]);
    }
    while(gets(str))
    {
        b=str;
        c=str;
        for(i=0;i<b.size();i++)
        {
            b[i]=tolower(b[i]);
        }
        r=b.find(a,0);
        while(r!=string::npos)
        {
            b.erase(r,a.size());
            c.erase(r,a.size());
            r=b.find(a,0);
        }
        r=c.find(' ',0);
        while(r!=string::npos)
        {
            c.erase(r,1);
            r=c.find(' ',0);
        }
        cout<<c<<endl;
    }
    return 0;
}
