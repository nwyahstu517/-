#include<iostream>
#include<set> 
using namespace std;
int main(){
set<int> s;
int n;
cin>>n;
for(int i=1;i<=n;i++){
	int x;
	cin>>x;
	s.insert(x);	
}
set<int>::iterator it;
for(it=s.begin();it!=s.end();it++){
	printf("%d\n",*it);
}
cout<<*s.upper_bound(4);
return 0;
}

