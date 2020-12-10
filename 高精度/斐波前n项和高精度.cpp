#include<bits/stdc++.h>
using namespace std;
void add(int a[],int b[],int c[]);
int first[2000],second[2000],res[2000],temp[2000],sum[2000];
int f=1;
int s=1;//初始数组长度
int sum_len=1;//前n项和的长度
int main(){
    memset(second,0,sizeof second);
    memset(res,0,sizeof res);
    memset(temp,0,sizeof temp);
    first[1]=1;
    second[1]=1;
    temp[1]=1;
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
            add(first,second,res);
            add(temp,second,temp);
            add(temp,res,sum);
            memcpy(first,second,1000);
            memcpy(second,res,1000);
        }
        for(int i=sum_len;i>=1;i--){
            cout<<sum[i];
        }
    }
    
    return 0;
}

void add(int first[],int second[],int res[]){
    int len=1;//第三数组长度
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
    sum_len=len;
}