#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
using namespace std;

bool cmp(char x,char y)
{
	if(x>=y)
	{
		return true;
	}
	return false;
}
int main(int argc, char** argv) {
	char s[1000];
	cin>>s;
	int n=0;
	n=strlen(s);
	cout<<n<<endl;
	sort(s,s+n,cmp);
   	printf("%s ",s);
}
