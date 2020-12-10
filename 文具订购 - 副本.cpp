#include<iostream>
#include<cmath>
using namespace std;
int main(){
int n;
cin>>n;
int maxc=0;
int maxs=0;
int aa,bb,cc;
bool flag=false;
for(int a=1;a<=n/7;a++){
	for(int b=1;b<=n/4;b++){
		int c=(n-7*a-4*b)/3;
		int d=min(min(a,b),c);
		if(d>maxc&&a+b+c>maxs&&7*a+4*b+3*c==n){
			flag=true;
			aa=a;
			bb=b;
			cc=c;
			maxc=c;
			maxs=a+b+c;
		}
	}
} 
if(flag)
cout<<aa<<" "<<bb<<" "<<cc; 
else
cout<<-1;
return 0;
}

