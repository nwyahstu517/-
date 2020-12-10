#include<iostream>
#include<cstring> 
using namespace std;
int main(){
int b[101],n,k;
memset(b,0,sizeof(b));
cin>>n;
for(int i=1;i<=n;i++){
	cin>>k;
	b[k]++;
} 
for(int i=0;i<=100;i++){
	while(b[i]>0){
		cout<<i<<" ";
		b[i]--;
	}
}
return 0;
}

