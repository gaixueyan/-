#include<stdio.h>
#include<stdlib.h>
#include<stack>//ջ��׼ģ��⣬��set��sort��stackͷ�ļ�ʱ����������׼�����ռ�using namespace std;
using namespace std;
#include<string.h>
int main()
{
    char input[105];
    stack<int> zuo;//stack����ջ��ʱ���ø���С
    stack<int> you;
    stack<int> zuo2;
    stack<int> you2;
    int i,n;
    int r;
    while(scanf("%s",input)!=EOF)
    {
        n=strlen(input);
        for(i=0;i<n;i++)
        {
            if(input[i]=='(')
            {
                zuo.push(i);
            }
            else if(input[i]==')')
            {
                if(!zuo.empty())
                {
                    zuo.pop();
                }
                else
                {
                    you.push(i);
                }
            }
        }
        while(!zuo.empty())//ջ�ߵ�
        {
            r=zuo.top();
            zuo.pop();//pop�Ƕ����������ó��������˸�ֵ����top����
            zuo2.push(r);
        }
        while(!you.empty())//ջ�ߵ�
        {
            r=you.top();
            you.pop();
            you2.push(r);
        }
        printf("%s\n",input);
        for(i=0;i<n;i++)
        {
            if(!you2.empty() && you2.top()==i)
            {
                printf("?");
                you2.pop();
            }
            else if(!zuo2.empty() && zuo2.top()==i)
            {
                printf("$");
                zuo2.pop();
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
