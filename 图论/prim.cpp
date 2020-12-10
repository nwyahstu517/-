#include<bits/stdc++.h>
using namespace std;
const int N=200;
const int MAXN=0x7f7f7f7f;
int g[N][N];//邻接矩阵
int minx[N];//minx[i]蓝点i与白点相连的最小边权
bool u[N];// 1 代表还未放入生成树 0代表放入生成树
int n;
int prim(){
    for(int i=1;i<=n;i++){
        int k=0;
        for(int j=1;j<=n;j++){
            if(u[j]&&minx[j]<minx[k]){
                k=j;
            }
        }//找到最小的minx[i]
        u[k]=0;
        for(int j=1;j<=n;j++){
            if(u[j]&&g[k][j]<minx[j]){
                minx[j]=g[k][j];
            }
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=minx[i];
    }
    return sum;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
        }
    }
    fill(minx,minx+N,MAXN);
    fill(u,u+N,1);
    minx[1]=0;
    cout<<prim();
    return 0;
}