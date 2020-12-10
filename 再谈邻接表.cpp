#include<iostream>
#include<cstring>
#define MAXN 100
using namespace std;
int n;//n个顶点
int m;//m条边
int u[MAXN],v[MAXN],w[MAXN];//起点 终点 权值
int first[MAXN];//记录该点的最后一条编号
int next[MAXN];//记录该点的“上一条编号”
int main(){
    cin>>n>>m;
    memset(first,-1,sizeof first);
    for(int i=1;i<=m;i++){//输入编号
        cin>>u[i]>>v[i]>>w[i];
        next[i]=first[u[i]];
        first[u[i]]=i;
    }
    //遍历 1号顶点的所有边
    int k=first[1];
    while(k!=-1){
        cout<<u[k]<<" "<<v[k]<<" "<<w[k]<<endl;
        k=next[k];
    }
    cout<<endl;
    //遍历所有点的边
    for(int i=1;i<=n;i++){
       k=first[i];
        while(k!=-1){
            cout<<u[k]<<" "<<v[k]<<" "<<w[k]<<endl;
            k=next[k];
        } 
    }
    
    return 0;
}