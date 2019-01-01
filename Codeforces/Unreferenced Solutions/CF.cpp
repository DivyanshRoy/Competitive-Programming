#include <bits/stdc++.h>
using namespace std;

int main()
{
	set<long long int> se;
	se.insert(10);
	se.insert(20);
	se.insert(30);
	se.insert(40);
	se.insert(50);
	
	set<long long int>::iterator iter;
	iter=se.lower_bound(30);
	cout<<*iter<<endl;
	
	iter=se.upper_bound(30);
	cout<<*iter<<endl;
	
	return 0;
}
