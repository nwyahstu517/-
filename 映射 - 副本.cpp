#include<iostream>
#include<map>
#include<sstream>
using namespace std;

int main(){
map<char,char> m;
//m['A']=2;m["B"]=2;m["C"]=2;
//m["D"]=3;m["E"]=3;m["F"]=4;
//m["G"]=4;m["H"]=4;m["I"]=4;
//m["J"]=5;m["K"]=5;m["L"]=5;
//m["M"]=6;m["N"]=6;m["O"]=6;
//m["P"]=7;m["R"]=7;m["S"]=7;
//m["T"]=8;m["U"]=8;m["V"]=8;
//m["W"]=9;m["X"]=9;m["Y"]=9;
m['A']='2';m['B']='2';m['C']='2';
m['D']='3';m['E']='3';m['F']='3';
m['G']='4';m['H']='4';m['I']='4';
m['J']='5';m['K']='5';m['L']='5';
m['M']='6';m['N']='6';m['O']='6';
m['P']='7';m['R']='7';m['S']='7';
m['T']='8';m['U']='8';m['V']='8';
m['W']='9';m['X']='9';m['Y']='9';
//for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
//	cout<<it->first<<" "<<it->second;
//}
int n;
string s;
cin>>n;
//for(int i=0;i<n;i++){
//	cin>>s[i];
//}
//for(int i=0;i<n;i++){
//	cout<<s[i]<<endl;
//}
map<string,int> mp;
for(int i=0;i<n;i++){
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			continue;
		}else if(s[i]>='A'&&s[i]<='Z'){
			s[i]=m[s[i]];
		}
	}
	string::iterator it;
	for(it=s.begin();it!=s.end();it++){
		if(*it=='-'){
			s.erase(it);
			it--;
		}
	}
	s=s.insert(3,"-");
	mp[s]++;
}
map<string,int>::iterator it;
bool bj=false;
for(it=mp.begin();it!=mp.end();it++){
	if(it->second>1){
		bj=true;
		cout<<it->first<<" "<<it->second<<endl;
	}
}
if(!bj){
	cout<<"No duplicates.";
}
return 0;
}

