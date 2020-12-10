#include<iostream>
#include<string> 
#include<unordered_map>
using namespace std;
int work(string s){
	if(s=="")return 0;
	int res=0;
	unordered_map<char,int> hash;
	for(int i=0,j=0;i<s.size();i++){
		hash[s[i]]++;
		while(hash[s[i]]>1){
			hash[s[j++]]--;
		}
		res=max(res,i-j+1); 
	}
	return res;
}

int main(){
string s;
cin>>s;
cout<<work(s);
return 0;
}

