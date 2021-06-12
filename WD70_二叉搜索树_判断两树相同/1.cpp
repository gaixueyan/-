#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

char yuanstr[20];
char str[20];//字符串可以重复使用，长度重新计算，不是覆盖上一次内容，是新写
int flag;

struct Tree
{
    struct Tree * left;
    struct Tree * right;
    int data;
};

struct Tree * creat(int r)
{
    struct Tree * root=(struct Tree *)malloc(sizeof(struct Tree));
    root->data=r;
    root->left=NULL;
    root->right=NULL;
    return root;
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
    if(root!=NULL)
    {
        free(root);
    }
}

struct Tree * creatsou(struct Tree * root,int r)
{
    if(root==NULL)
    {
        root=creat(r);
    }
    else if(root->data > r)
    {
        root->left=creatsou(root->left,r);
    }
    else if(root->data < r)
    {
        root->right=creatsou(root->right,r);
    }
    return root;
}

void panduan(struct Tree * yuanroot,struct Tree * root)
{
    if(flag==0)
    {
        return;
    }
    if(yuanroot->data != root->data)
    {
        flag=0;
        return;
    }
    if(yuanroot==NULL && root!=NULL)
    {
        flag=0;
        return;
    }
    if(yuanroot!=NULL && root==NULL)
    {
        flag=0;
        return;
    }
    if(yuanroot->left!=NULL && root->left!=NULL)
    {
        panduan(yuanroot->left,root->left);
    }
    if(yuanroot->right!=NULL &&root->right!=NULL)
    {
        panduan(yuanroot->right,root->right);
    }
}

int main()
{
    int n;
    int i,j;
    struct Tree * yuanroot=NULL;
    struct Tree * root=NULL;
    int sizeyuanstr;
    int sizestr;

    scanf("%d",&n);
    while(n!=0)
    {
        scanf("%s",yuanstr);
        sizeyuanstr=strlen(yuanstr);
        for(j=0; j<sizeyuanstr; j++)
        {
            yuanroot=creatsou(yuanroot,yuanstr[j]);
        }
        for(i=0; i<n; i++)
        {
            scanf("%s",str);
            sizestr=strlen(str);
            for(j=0; j<sizestr; j++)
            {
                root=creatsou(root,str[i]);
            }
            flag=1;
            panduan(yuanroot,root);
            if(flag==1)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
            deletetree(root);
        }
        deletetree(yuanroot);
        scanf("%d",&n);
    }
    return 0;
}
