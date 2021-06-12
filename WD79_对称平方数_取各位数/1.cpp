#include<stdio.h>
#include<iostream>
using namespace std;

int gewei[10];

bool duichen(int shu)
{
    int i=0;
    while(shu!=0)
    {
        gewei[i]=shu%10;
        shu=shu/10;
        i++;
    }
    int j;
    for(j=0;j<i/2+1;j++)
    {
        if(gewei[j]!=gewei[i-j-1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int i;
    for(i=0;i<256;i++)
    {
        if(duichen(i*i))
        {
            printf("%d\n",i);
        }
    }
    return 0;
}
