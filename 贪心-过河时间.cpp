#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[1000];
    while(n--){
        int m;
        cin>>m;
         memset(a,0,sizeof a);
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    sort(a+1,a+m+1);
    int dp[1001];
    dp[1]=a[1];
    dp[2]=a[2];
    for(int i=3;i<=m;i++){
        dp[i]=min(dp[i-1]+a[1]+a[i],dp[i-2]+a[1]+a[i]+a[2]*2);//只让速度最快的送;可以让速度第二的参与
    }
    cout<<dp[m]<<endl;
    }
}