#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long n,s=1;
    cin>>n;
    if(n==1){
        s=1;
    }else if(n==2){
        s=1;
    }else if(n==3){
        s=2;
    }else if(n==4){
        s=4;
    }else{
        cout<<n<<"=";
        if(n%3==0){
            s*=pow(3,n/3);
            cout<<3<<"^"<<n/3;
        }else{
            s*=pow(3,n/3-1);
            cout<<3<<"^"<<n/3-1;
            n-=3*(n/3-1);
            if(n==4){
                s*=4;
                cout<<"*2*2";
            }
            else {
                s*=6;
                cout<<"*2*3";
            }
        }
    cout<<endl<<s;
    }
    return 0;
}