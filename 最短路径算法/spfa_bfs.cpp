#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
const int N=10010;
const int M=20010;
using namespace std;
int n,m,idx;//n个点，m条边
int ne[M];//存储上一条边号
int w[M];//存储边的权值
int v[M];//存储边的终点
int first[N];//存储该节点最新的边号
bool vis[N];
int d[N];//记录距离
int cnt[N];//记录起点到达这个点经过的点的数量
void add(int x,int y,int z){
    idx++;
    ne[idx]=first[x];
    first[x]=idx;
    v[idx]=y;
    w[idx]=z;
}
bool spfa(int s){
    queue<int> q;
    memset(d,127,sizeof d);
    d[s]=0;
    cnt[s]=1;
    q.push(s);
    vis[s]=1;
    while (q.size())
    {
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(int i=first[x];i;i=ne[i]){
            int y=v[i];
            if(d[y]>d[x]+w[i]){
                d[y]=d[x]+w[i];
                cnt[y]=cnt[x]+1;
                if(cnt[y]>n){
                    return false;
                }
                if(!vis[y]){
                    q.push(y);
                    vis[y]=1;
                }
            }
        }
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    bool flag;
    flag=spfa(1);
    if(!flag){
        cout<<"负环";
    }else{
        cout<<"无负环";
    }
    return 0;
}
