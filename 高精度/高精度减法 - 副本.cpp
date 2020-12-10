#include<iostream>
#include<cstring>
using namespace std;
#define MAX 1000
string s1,s2;//接收数据
int a[MAX],b[MAX],c[MAX];//数据清0，并且将string的数字倒序存储到数组
int main(int argc, char const *argv[])
{
	cin>>s1>>s2;
	if(s1.length()<s2.length()||(s1.length()==s2.length()&&s1<s2)){
		swap(s1,s2);
		cout<<"-";
	}
	int len1=s1.length(),len2=s2.length();
	for(int i=0;i<len1;++i){
		a[len1-i]=s1[i]-'0';
	}
	for(int i=0;i<len2;++i){
		b[len2-i]=s2[i]-'0';
	}
	int len=1;
	while(len<=len1||len<=len2){
		if(a[len]<b[len]){
			a[len]+=10;
			a[len+1]--;
		}
		c[len]=a[len]-b[len];
		len++;
	}
	while(c[len]==0&&len>1)len--;
	while(len>0){
		cout<<c[len];
		len--;
	}
	return 0;
}