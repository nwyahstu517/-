#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N=10000;
const int INF=99999999;
int u[N];//边的起点;
int v[N];//边的终点;
int w[N];//边的权值;
int dis[N];//存储起点到i的距离
bool vis[N];
int first[N],nex[N];
int n,m;// n点 m边
queue<int> q;
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    //初始化dis数组
    for(int i=1;i<=n;i++){
        dis[i]=INF;
    }
    dis[1]=0;
    memset(first,-1,sizeof first);
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        nex[i]=first[u[i]];
        first[u[i]]=i;
    }

    //spfa使用队列处理
    q.push(1);
    vis[1]=1;
    while (q.size())
    {
        int k=first[q.front()];//拿到当前队首的一条边
        while(k!=-1){
            if(dis[v[k]]>dis[u[k]]+w[k]){
                dis[v[k]]=dis[u[k]]+w[k];
                if(vis[v[k]]==0){
                    q.push(v[k]);
                    vis[v[k]]=1;
                }
            }
            k=nex[k];
        }
        vis[q.front()]=0;
        q.pop();
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    return 0;
}
