#include<iostream>
using namespace std;
/*
原理图：
   数组：10 12 93 12 75
辅助数组  0  0  0  0  0  如果访问过，就标记1
*/
int main(){
    int n;
    cin>>n;
    int a[2001];
    bool flag[2001];
    for(int i=0;i<n;i++){
        cin>>a[i];
        flag[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]==a[i]&&flag[j]==0){
                flag[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(flag[i]==0) cout<<a[i]<<" ";
    }
}