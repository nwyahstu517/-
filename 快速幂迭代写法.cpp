#include<iostream>
using namespace std;
typedef long long ll;
ll binaryPow(ll a,ll b,ll c){
    ll ans=1;
    while(b>0){
        if(b & 1){
            ans = ans * a % c;
        }
        a= a*a%c;
        b >>= 1;
    }
    return ans;
}
int main(){
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<binaryPow(a,b,c);
    return 0;
}