#include<iostream>
using namespace std;
int f[100010];
int g[100010];
int p;
int main(int argc, char const *argv[])
{
    int n;
    cin>>n>>p;
    int m=0;
    for(int k=1;f[m]<=n;k++){
        f[++m]=(3*k*k-k)/2;
        f[++m]=(3*k*k+k)/2;//计算广义五边形
    }
    for(int i=1;i<=n;i++){
        cout<<f[i]<<" ";
    }
    cout<<endl;
    g[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1,t=1;f[j]<=i;j++){
            g[i]=(g[i]+g[i-f[j]]*t)%p;
            if(j%2==0){
                t*=-1;
            }
        }
    }
    cout<<(g[n]+p)%p;
    return 0;
}
