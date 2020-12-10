#include<bits/stdc++.h>
using namespace std;
void add(int a[],int b[],int c[]);
int first[1001],second[1001],ans[1001];
int f=1;
int s=1;//初始数组长度
int len;
int main(){
    memset(second,0,sizeof second);
    first[1]=1;
    second[1]=1;
    int n;
    cin>>n;
    if(n==1){
        cout<<1;
        return 0;
    }else if(n==2){
        cout<<2;
        return 0;
    }else{
        for(int i=3;i<=n;i++){
            add(first,second,ans);
            memcpy(first,second,1000);
            memcpy(second,ans,1000);
        }
        for(int i=len;i>=1;i--){
            cout<<ans[i];
        }   
    }
    
    return 0;
}

void add(int first[],int second[],int res[]){
    len=1;//第三数组长度
    int x=0;//进制
    //逆序;
    for(int i=1,j=len;i<j;i++){
        swap(first[i],first[j]);
        swap(second[i],second[j]);
    }
    while(len<=f||len<=s){
        res[len]=first[len]+second[len]+x;
        x=res[len]/10;
        res[len]%=10;
        len++;
    }
    res[len]=x;
    if(res[len]==0){
        len--;
    }
    f=len;
    for(int i=len;i>=1;i--)
        ans[i]=res[i];
}