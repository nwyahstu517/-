#include<iostream>
#include<cmath>
#include<cstring>
#include<iomanip>
using namespace std;
const int  N = 3000;
long long  e[N][N] ; // 二维数组大小最好不超过 1e8
int n,m,st,en;
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j&&i!=k&&j!=k&&e[i][k]+e[k][j]<e[i][j]){
                    e[i][j]=e[i][k]+e[k][j];
                }
            }
        }
    }
}
int main(){
    cin>>n>>m>>st>>en;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==j)e[i][j]=0;
            else e[i][j]=2140000000;
        }
    }
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        e[x][y]=e[y][x]=z;
    }
    floyd();
    cout<<e[st][en];
    return 0;
}