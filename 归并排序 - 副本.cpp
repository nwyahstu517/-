#include<iostream>
using namespace std;
const int MAXN=1000;
int n,a[MAXN],r[MAXN];
void msort(int s,int t){
	if(s==t)return;
	int mid=(s+t)/2;
	msort(s,mid);//分解左序列
	msort(mid+1,t);//分解右序列
	//开始合并
	int i=s,j=mid+1,k=s;
	while(i<=mid&&j<=t){
		if(a[i]<=a[j]){
			r[k]=a[i];
			k++;
			i++;
		}else{
			r[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=mid){
		r[k]=a[i];
		k++;
		i++;
	} 
	while(j<=t){
		r[k]=a[j];
		k++;
		j++;
	}
	for(int i=s;i<=t;i++)
		a[i]=r[i]; 
} 
int main(){
cin>>n;
for(int i=0;i<n;i++){
	cin>>a[i];
}
msort(0,n-1);
for(int i=0;i<n;i++){
	cout<<a[i]<<" ";
}
return 0;
}

