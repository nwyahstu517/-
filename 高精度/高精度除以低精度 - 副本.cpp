#include<iostream>
using namespace std;
#define MAXN 1000
string s;
int n;
int a[MAXN],c[MAXN];
int main(int argc, char const *argv[])
{
	cin>>s>>n;
	int len=s.size();
	for(int i=0;i<len;i++){
		a[i+1]=s[i]-'0';
	}
	int x=0;
	for(int i=1;i<=len;i++){
		c[i]=(x*10+a[i])/n;
		x=(x*10+a[i])%10;
	}
	int lenc=1;
	while(c[lenc]==0&&lenc<len){
		lenc++;
	}
	for(int i=lenc;i<=len;i++){
		cout<<c[i];
	}
	return 0;
}
