#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<iomanip>
int f[110][2];//f[i][0]代表以i为结尾的上升子序列个数 f[i][1]下降序列个数
int a[110];
int n;
using namespace std;
int main(){
    cin>>n;
    memset(f,1,sizeof f);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //上升序列
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[i]>a[j]){
                f[i][0]=max(f[i][0]+1,f[j][0]);
            }
        }
    }
    //求下降
    int m=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]<a[i]){
                f[i][1]=max(f[i][1]+1,f[j][1]);
            }
        }
        m=max(m,f[i][0]+f[i][1]-1);
    }
    cout<<n-m;
    return 0;
}