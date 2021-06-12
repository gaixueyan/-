#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

char yuan[100];
char result[100];

int main()
{
    int a,b;
    long long n;
    int sizeyuan,sizeresult;
    int i,j,r;
    while(scanf("%d %s %d",&a,yuan,&b)!=EOF)
    {
        sizeyuan=strlen(yuan);
        n=0;
        long long cheng=1;
        for(i=sizeyuan-1;i>=0;i--)
        {
            if('0'<=yuan[i] && yuan[i]<='9')//这里不是python,绝对不能连写成'0'<=yuan[i]<='9'，要写两个比较，用&&
            {
                n=n+(yuan[i]-'0')*cheng;
            }
            else if('a'<=yuan[i] && yuan[i]<='z')
            {
                n=n+(yuan[i]-'a'+10)*cheng;//a替换10，b替换11的方法，不要一串else if了
            }
            else if('A'<=yuan[i] && yuan[i]<='Z')
            {
                n=n+(yuan[i]-'A'+10)*cheng;//用pow的话一定注意处理成(int)(pow(a,j)+0.5)
            }
            cheng=cheng*a;
        }
        i=0;
        while(n!=0)
        {
            r=n%b;
            n=n/b;
            if(0<=r && r<=9)
            {
                result[i]=r+'0';
            }
            else
            {
                result[i]=r-10+'A';//10换成a，11换成b的方法
            }
            i++;
        }
        for(j=i-1;j>=0;j--)
        {
            printf("%c",result[j]);
        }
        printf("\n");
    }
    return 0;
}
