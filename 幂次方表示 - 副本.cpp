#include<iostream>
#include<cmath>
using namespace std;
void power(int x){
	if(x<=4){
		switch(x){
			case 0:break;
			case 1:
				cout<<"2(0)";break;
			case 2:
				cout<<"2";break;
			case 3:
				cout<<"2(0)+2";break;
			case 4:
				cout<<"2(2)";break;
			default:
				break;
		}
	}else{
		int i=1;
		for(;pow(2,i)<=x;i++);//找到最大的i
		cout<<"2(";
		power(i-1); 
		cout<<")";
		if(x!=pow(2,i-1))
			cout<<"+";
		power(x-pow(2,i-1));
	}
} 
int main(){
int x;
cin>>x;
power(x);
return 0;
}

