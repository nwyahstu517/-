#include<iostream>
using namespace std;
int main(){
    int sum=0,n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        int temp=i;
        while(temp!=0){
            int t=temp%10;
            temp/=10;
            if(t==x){
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}