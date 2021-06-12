#include <iostream>
#include <set>
using namespace std;
 
int main(int argc, char** argv) {
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(1);
	s.insert(2);
	s.insert(4);
	if(!s.empty())
	{
		cout<<"不为空"<<endl;
	}
	cout<<"个数"<<s.size()<<endl;
	cout<<"第一个元素"<<*s.begin()<<endl;//*s.begin(),说明返回的是指针 
	cout<<"最后元素"<<*s.end()<<endl;
	cout<<"1是否出现"<<s.count(1)<<endl;
	cout<<"12是否出现"<<s.count(12)<<endl;
	s.erase(1);
	set<int>::iterator it;
	it=s.begin();
	cout<<"第一个元素"<<*s.begin()<<endl;//*s.begin(),说明返回的是指针 
	s.erase(it);
	for(it=s.begin();it!=s.end();it++)
	{
		cout<<*it<<endl;
	}	
	it=s.find(5);
	if(it!=s.end())
	{
		cout<<*it<<endl;
	}
	return 0;
}
