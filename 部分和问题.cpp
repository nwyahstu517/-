#include<iostream>
using namespace std;
int a[1000];
int dfs(int,int);
int k,n;
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>k;
    dfs(0,0);
    if(dfs(0,0)){
        cout<<"yes";
    }else{
        cout<<"no";
    }
    return 0;
}
int dfs(int i,int sum){
    if(i==n)return sum==k;
    if(dfs(i+1,sum)){
      return 1;  
    }
    if(dfs(i+1,sum+a[i])){
       return 1; 
    }
    return 0;
}