#include<iostream>
#define MAXN 1000 
using namespace std;
int n,a[MAXN],k;
int main(){
cin>>n;
for(int i=0;i<n;i++)
	cin>>a[i];
for(int i=0;i<n;i++){//存放的位置从小到大
	k=i;//记住当前无序区第一个元素的位置 
 	for(int j=i+1;j<n;j++){//从有序区后一个元素开始查找 
 		if(a[j]<a[k])  k=j; 
	}
	if(k!=i) swap(a[i],a[k]);//如果k发生变化，说明在后面查找到有更小的元素	
}
for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
return 0;
}

