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
		cout<<"��Ϊ��"<<endl;
	}
	cout<<"����"<<s.size()<<endl;
	cout<<"��һ��Ԫ��"<<*s.begin()<<endl;//*s.begin(),˵�����ص���ָ�� 
	cout<<"���Ԫ��"<<*s.end()<<endl;
	cout<<"1�Ƿ����"<<s.count(1)<<endl;
	cout<<"12�Ƿ����"<<s.count(12)<<endl;
	s.erase(1);
	set<int>::iterator it;
	it=s.begin();
	cout<<"��һ��Ԫ��"<<*s.begin()<<endl;//*s.begin(),˵�����ص���ָ�� 
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
