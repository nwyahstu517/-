#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int sum=0;
    for(int i=100;i<=999;i++){
        int t=i,g,s,b;
        g=t%10;
        s=t/10%10;
        b=t/100;
        if(pow(g,3)+pow(b,3)+pow(s,3)==t){
            sum++;
            cout<<t<<" ";
            if(sum==2){
                return 0;
            }
        }
    }
    return 0;
}