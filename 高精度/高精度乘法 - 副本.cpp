#include<iostream>
#include<cstring>
using namespace std;
#define MAX 1000
string s1,s2;//接收数据
int a[MAX],b[MAX],c[MAX];//数据清0，并且将string的数字倒序存储到数组
int main(int argc, char const *argv[])
{
	cin>>s1>>s2;
	int len1=s1.length(),len2=s2.length();
	for(int i=0;i<len1;++i){
		a[len1-i]=s1[i]-'0';
	}
	for(int i=0;i<len2;++i){
		b[len2-i]=s2[i]-'0';
	}
	int x;
	for(int i=1;i<=len1;++i){
		x=0;
		for(int j=1;j<=len2;++j){
			c[i+j-1]=a[i]*b[j]+x+c[i+j-1];
			x=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
		c[i+len2]=x;
	}
	int len=len1+len2;
	while(c[len]==0&&len>1){
		len--;
	}
	for(int i=len;i>=1;i--){
		cout<<c[i];
	}
	return 0;
}