#include<iostream>
#define MAXN 1000 
using namespace std;
int n,a[MAXN],k;
int main(){
cin>>n;
for(int i=0;i<n;i++)
	cin>>a[i];
for(int i=0;i<n;i++){//��ŵ�λ�ô�С����
	k=i;//��ס��ǰ��������һ��Ԫ�ص�λ�� 
 	for(int j=i+1;j<n;j++){//����������һ��Ԫ�ؿ�ʼ���� 
 		if(a[j]<a[k])  k=j; 
	}
	if(k!=i) swap(a[i],a[k]);//���k�����仯��˵���ں�����ҵ��и�С��Ԫ��	
}
for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
return 0;
}

