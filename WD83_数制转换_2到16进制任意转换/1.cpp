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
            if('0'<=yuan[i] && yuan[i]<='9')//���ﲻ��python,���Բ�����д��'0'<=yuan[i]<='9'��Ҫд�����Ƚϣ���&&
            {
                n=n+(yuan[i]-'0')*cheng;
            }
            else if('a'<=yuan[i] && yuan[i]<='z')
            {
                n=n+(yuan[i]-'a'+10)*cheng;//a�滻10��b�滻11�ķ�������Ҫһ��else if��
            }
            else if('A'<=yuan[i] && yuan[i]<='Z')
            {
                n=n+(yuan[i]-'A'+10)*cheng;//��pow�Ļ�һ��ע�⴦���(int)(pow(a,j)+0.5)
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
                result[i]=r-10+'A';//10����a��11����b�ķ���
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
