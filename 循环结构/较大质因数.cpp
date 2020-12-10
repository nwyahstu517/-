#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        bool flag=true;
        if(n%i==0){
            int t=n/i;
            for(int j=2;j<=sqrt(t);j++){
                if(t%j==0){
                    flag=false;
                    break;
                }
            }
            if(flag){
                cout<<t;
                return 0;
            }  
        }
    }
}