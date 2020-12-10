#include<iostream>
using namespace std;
long long a,b,m;
long long binaryPow(long long a,long long b,long long c){
    if(b==0)return 1;
    else if(b%2==1)
        return a*binaryPow(a,b-1,m)%m;
    else{
        long long num=binaryPow(a,b/2,m)%m;
        return num*num%m;
    }
}
int main(){
    cin>>a>>b>>m;
    cout<<binaryPow(a,b,m);
    return 0;
}