#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
struct data
{
    char name[100];
    int age;
    int score;
};
data buf[1000];
bool cmp(data x,data y)
{
    if(x.score<y.score)return true;
    if(x.score>y.score)return false;
    if(!strcmp(x.name,y.name))return true;
    if(strcmp(x.name,y.name))return false;
    if(x.age<=y.age)return true;
    if(x.age>y.age)return false;
}
int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        for(int i=0;i<N;i++)
        {
            scanf("%s %d %d",buf[i].name,&buf[i].age,&buf[i].score);
        }
        sort(buf,buf+N,cmp);
        for(int i=0;i<N;i++)
        {
            printf("%s %d %d\n",buf[i].name,buf[i].age,buf[i].score);
        }
    }
    return 0;
}
