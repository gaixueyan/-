#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    char buf[205];
    int n;
    while(gets(buf))
    {
        n=strlen(buf);
        sort(buf,buf+n);
        cout<<buf<<endl;
    }
    return 0;
}
