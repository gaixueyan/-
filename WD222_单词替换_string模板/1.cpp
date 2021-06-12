#include<stdio.h>
#include<iostream>
using namespace std;
#include<string>

int main()
{
    char str[105];
    string s,a,b;
    while(gets(str))
    {
        s=str;
        gets(str);
        a=str;
        gets(str);
        b=str;
        int t;
        t=s.find(a,0);
        while(!((t==0 || s[t-1]==' ') && (t+a.size()==s.size() || s[t+a.size()]==' ')))
        {
            t=s.find(a,t+1);
            if(t==string::npos)break;
        }
        while(t!=string::npos)
        {
            s.erase(t,a.size());
            s.insert(t,b);
            t=s.find(a,0);
            while(!((t==0 || s[t-1]==' ') && (t+a.size()==s.size() || s[t+a.size()]==' ')))
            {
                t=s.find(a,t+1);
                if(t==string::npos)break;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
