#include<iostream>
using namespace std;
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<stack>

stack<int> shu;
int main()
{
    int n;
    int i;
    char s;
    int a;
    scanf("%d",&n);
    while(n!=0)//��������д���ǣ�while (scanf("%d", &n)==1 && n!=0)��while(scanf("%d",&n)!=0)�Ǵ�ģ��жϵ���scanf��������ֵ
    {
        for(i=0;i<n;i++)
        {
            //scanf("%c",&s);
            cin>>s;//ֻ��cin��scanf("d",&a)��˳������P 5�������ݣ�����scanf�������������𣬻����Ի�
            //�����ַ���cin��������Կո�ͻس���scanf("%c",&i)�ȼ���i = getchar()�����з��ͻس����ᱻ���롣
            if(s=='P')
            {
                scanf("%d",&a);
                shu.push(a);
            }
            else if((s=='O')&&(!shu.empty()))
            {
                shu.pop();
            }
            else if(s=='A')
            {
                if(shu.empty())
                {
                    printf("E\n");
                }
                else
                {
                    printf("%d\n",shu.top());
                }
            }
        }
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}
