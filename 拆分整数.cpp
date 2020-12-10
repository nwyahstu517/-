#include<iostream>
using namespace std;
//将N分解成不同数之和，乘积最大
int main(){
    int input;
    cin>>input;
    int k=2;//从2开始
    int a[10000]={},i=0;
    while (input>=k)
    {
        a[i++]=k;
        input-=k;
        k++;
    }
    //判断input是否非0，并且是否等于最后一位
    if(input){
        if(input==a[i-1]){
            a[i-1]++;
        }
        for(int j=0;j<input;j++){
            a[i-1-j]++;
        }
    }
    unsigned long long res=1;
    for(int j=0;j<i;j++){
        res*=a[j];
    }
    cout<<res;
    return 0;
}