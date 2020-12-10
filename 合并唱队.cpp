#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int f[110][2];//f[i][0]以i结尾的升序长度
int a[110];
int main(){
    for(int i=0;i<=105;i++){
        for(int j=0;j<2;j++){
            f[i][j]=1;
        }
    }
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[i]>a[j]){
                f[i][0]=max(f[i][0],f[j][0]+1);
            }
        }
    }

    int m=0;
    for(int i=n;i>=1;i--){
        for(int j=n;j>i;j--){
            if(a[i]>a[j]){
                f[i][1]=max(f[i][1],f[j][1]+1);
            }
        }
        m=max(m,f[i][0]+f[i][1]-1);
    }
    cout<<n-m;
    return 0;
}