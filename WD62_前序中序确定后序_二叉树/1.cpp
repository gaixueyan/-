#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

char qianxu[50];
char zhongxu[50];
int qianlong;
int zhonglong;

struct Tree
{
    struct Tree * left;
    struct Tree * right;
    char data;
};

void houbianli(struct Tree * root)
{
    if(root->left!=NULL)
    {
        houbianli(root->left);
    }
    if(root->right!=NULL)
    {
        houbianli(root->right);
    }
    printf("%c",root->data);
}

struct Tree * creat()
{
    struct Tree * node;
    node=(struct Tree *)malloc(sizeof(struct Tree));
    node->left=NULL;
    node->right=NULL;
    return node;
}

void deletetree(struct Tree * root)
{
    if(root->left!=NULL)
    {
        deletetree(root->left);
    }
    if(root->right!=NULL)
    {
        deletetree(root->right);
    }
    free(root);
}

struct Tree * make(int zhongqi,int zhongzhi)
{
    struct Tree * root;
    root=creat();
    int weizhi;
    int i,j;
    int flag;
    flag=0;
/*实际应用时，由于前序+中序确定树的问题中不能出现重复数字，
所以递归函数可以不加前序数组起始下标，每次直接在全部前序数组里对比（效率低为n^2，不然可以n）*/
    for(i=0; i<qianlong && flag==0; i++)
    {
        for(j=zhongqi; j<zhongzhi && flag==0; j++)
        {
            if(qianxu[i]==zhongxu[j])
            {
                weizhi=j;
                flag=1;
            }
        }
    }
    root->data=zhongxu[weizhi];
    if(weizhi-zhongqi>0)
    {
        root->left=make(zhongqi,weizhi);
    }
    if(zhongzhi-weizhi-1>0)
    {
        root->right=make(weizhi+1,zhongzhi);
    }
    return root;
};

int main()
{
    while(scanf("%s",qianxu)!=EOF)
    {
        struct Tree * root;
        scanf("%s",zhongxu);
        qianlong=strlen(qianxu);
        zhonglong=strlen(zhongxu);
        if(qianlong>0)
        {
            root=make(0,zhonglong);
            houbianli(root);
        }
        printf("\n");
        deletetree(root);
    }
    return 0;
}
