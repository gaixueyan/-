#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;

char charshi[40];
char shi[40];
char er[200];
char buf[40];
int sizeshi;
int sizeer;
int sizebuf;

int main()
{
    int i,j;
    int r;
    while(scanf("%s",charshi)!=EOF)
    {
        sizeshi=strlen(charshi);
        if(sizeshi==1 && charshi[0]=='0')
        {
            printf("0");
            //break;//���ﲻ����break������whileѭ�����Ҳ���while�ж�
        }
        else
        {
            for(i=0; i<sizeshi; i++)
            {
                shi[i]=charshi[sizeshi-i-1]-'0';
            }
            sizeer=0;
            while(sizeshi>0 || shi[0]!=0)
            {
                er[sizeer]=shi[0]%2;//ȡ��
                sizeer++;
                r=0;
                for(i=sizeshi-1; i>=0; i--)//������Ư���ĳ���ģ��
                {
                    buf[i]=(r*10+shi[i])/2;
                    r=shi[i]%2;
                }
                for(i=sizeshi-1; i>=0; i--)
                {
                    if(buf[i]!=0)
                    {
                        break;
                    }
                    sizeshi--;
                }
                for(i=0; i<sizeshi+1; i++)
                {
                    shi[i]=buf[i];
                }
            }
            for(i=sizeer-1; i>=0; i--)
            {
                printf("%d",er[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
