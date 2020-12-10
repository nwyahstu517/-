#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
int main(){
vector<int> a={5,4,3,2,2,1,6};
vector<int> b={6,5,4,3,2,2,7};
vector<int> res;
sort(a.begin(),a.end());
sort(b.begin(),b.end());

// 交集 
set_intersection(a.begin(),a.end(),b.begin(),b.end(),a.begin());
a.erase(unique(a.begin(),a.end()),a.end());
for(int i=0;i<a.size();i++){
	cout<<a[i]<<" ";
}
cout<<endl;

//并集
a={5,4,3,2,1,6};
b={6,5,4,3,2,7};

sort(a.begin(),a.end());
sort(b.begin(),b.end()); 

set_union(a.begin(),a.end(),b.begin(),b.end(),a.begin());
a.erase(unique(a.begin(),a.end()),a.end());
for(int i=0;i<a.size();i++){
	cout<<a[i]<<" ";
}
cout<<endl;
//差集
a={5,4,3,2,1,6};
b={6,5,4,3,2,7};

sort(a.begin(),a.end());
sort(b.begin(),b.end()); 

set_difference(a.begin(),a.end(),b.begin(),b.end(),a.begin());
a.erase(unique(a.begin(),a.end()),a.end());
for(int i=0;i<a.size();i++){
	cout<<a[i]<<" ";
}
cout<<endl;
//对称差集
a={5,4,3,2,1,6};
b={6,5,4,3,2,7};

sort(a.begin(),a.end());
sort(b.begin(),b.end()); 

set_symmetric_difference(a.begin(),a.end(),b.begin(),b.end(),a.begin());
a.erase(unique(a.begin(),a.end()),a.end());
for(int i=0;i<a.size();i++){
	cout<<a[i]<<" ";
}
cout<<endl;
return 0;
}

