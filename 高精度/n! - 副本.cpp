#include<iostream>
#include<cstring>
const int maxlen=10001; 
using namespace std;
int main(){
int i,j,fac[maxlen];
//int n;
//cin>>n;
memset(fac,0,sizeof(fac));
fac[1]=1;
int len=1;
for(i=1;i<=1977;i++){
	int x=0;
	for(j=1;j<=len;j++){
		fac[j]=fac[j]*i+x;
		x=fac[j]/10;
		fac[j]%=10;
		if(x>0&&j>=len){
			len++;
		}
	}
}
for(int k=len;k>=1;k--){
	cout<<fac[k];
}
return 0;
}

