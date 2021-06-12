#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct student
{
    char num[10];
    char name[20];
    char sex[10];
    int age;
}buf[1002];
bool cmp(struct student x,struct student y)
{
    return strcmp(x.num,y.num)<0;
}
int main()
{
    int N,M;
    while(scanf("%d",&N)!=EOF)
    {
    int i,j,k;
    for(i=0;i<N;i++)
    {
        scanf("%s %s %s %d",buf[i].num,buf[i].name,buf[i].sex,&buf[i].age);//中文的一个字也要用字符串接收，字符接收会崩溃啊
    }
    sort(buf,buf+N,cmp);
    char find[10];
    int low,high,mid;
    int address;
    int flag;
    getchar();
    cin>>M;
    for(i=0;i<M;i++)
    {
        cin>>find;
        low=0;
        high=N-1;
        flag=0;
        address=-1;
        while(low<=high && flag==0)
        {
            mid=(low+high)/2;
            if(strcmp(buf[mid].num,find)<0)
            {
                low=mid+1;
            }
            else if(strcmp(buf[mid].num,find))
            {
                high=mid-1;
            }
            else if(strcmp(buf[mid].num,find)==0)
            {
                address=mid;
                flag=1;
                break;
            }
        }
        if(address==-1)
        {
            cout<<"No Answer!";
        }
        else
        {
            printf("%s %s %s %d",buf[address].num,buf[address].name,buf[address].sex,buf[address].age);
        }
        if(i!=M-1)
        {
            cout<<endl;
        }
    }
    }
    return 0;
}
