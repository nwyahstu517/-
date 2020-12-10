#include<iostream>
#define MAXN 10
using namespace std;
int main(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
	cin>>a[i];
for(int i=n-1;i>=1;i--){//进行N-1趟冒泡 
	for(int j=0;j<i;j++){//每趟进行i次比较 
		if(a[j]>a[j+1])
			swap(a[j],a[j+1]);
	}
}
for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
return 0;
}

