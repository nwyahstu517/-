#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=10000;
const int INF=99999999;
int u[N];//边的起点;
int v[N];//边的终点;
int w[N];//边的权值;
int dis[N];//存储起点到i的距离
int bak[N];
int n,m;// n点 m边
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    //初始化dis数组
    for(int i=1;i<=n;i++){
        dis[i]=INF;
    }
    dis[1]=0;
    //核心
    for(int i=1;i<=n-1;i++){
        memcpy(bak,dis,sizeof dis);
        for(int j=1;j<=m;j++){
            dis[v[j]]=min(dis[v[j]],dis[u[j]]+w[j]);
        }
        bool check=0;
        //检测 dis 数组有无变化
        for(int i=1;i<=n;i++){
            if(dis[i]!=bak[i]){
                check=1;
                break;
            }
        }
        if(check==0){
            break;
        }
    }
    //检测负权回路
    bool flag=0;
    for(int j=1;j<=m;j++){
            if(dis[v[j]]>dis[u[j]]+w[j]){
                flag=1;
                break;
            }
    }
    if(flag){
        cout<<"存在负权回路";
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    return 0;
}
