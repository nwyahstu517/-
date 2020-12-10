#include<bits/stdc++.h>
using namespace std;

const int N=1010;
int v[N],w[N];
int f[N][N];
int ff[N];
int n,m;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d%d",&w[i],&v[i]);
     for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            f[i][j]=f[i-1][j];
            for(int k=0;k*w[i]<=j;k++){
                f[i][j]=max(f[i][j],f[i-1][j-k*w[i]]+k*v[i]);
            }
        }
    } 
    cout<<f[n][m];
    /*  for(int i=1;i<=n;i++){
        for(int j=w[i];j<=m;j++){
                ff[j]=max(ff[j],ff[j-w[i]]+v[i]);
        }
    }
    cout<<ff[m]<<endl;  */
}
