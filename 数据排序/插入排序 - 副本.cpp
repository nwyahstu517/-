#include<iostream>
using namespace std;
const int MAXN=1000;
int n,a[MAXN],i,j,k; 
int main(){
cin>>n;
for(int i=0;i<n;i++)
	cin>>a[i];
for(i=0;i<n;i++){//��ǰԪ�� 
	for(j=i-1;j>=0;j--){//���λ����ǰ���ҵ�һ��С�ڵ��ڵ�λ�� 
		if(a[j]<=a[i])break;
	}
	if(j!=i-1){
		int temp=a[i];
		for(k=i-1;k>j;k--){
			a[k+1]=a[k];
		}
		a[k+1]=temp;
	}
}
for(i=0;i<n;i++){
	cout<<a[i]<<" ";
}
return 0;
}

