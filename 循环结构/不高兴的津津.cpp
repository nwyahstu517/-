#include<iostream>
using namespace std;
int main(){
    int mx=8,bj=0;
    for(int i=1;i<=7;i++){
        int a,b;
        cin>>a>>b;
        if(a+b>mx){
            mx=a+b;
            bj=i;
        }
    }
    cout<<bj;
}