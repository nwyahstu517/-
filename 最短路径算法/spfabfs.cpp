#include<bits/stdc++.h>
using namespace std;
const int N=1E5+10;
int MIN=2e9;
int head[N],net[N],to[N],w[N],dis[N],num;
bool vis[N];
queue<int> q;
int n,m;

void add(int f,int t,int v){
    num++;
    net[num]=head[f];
    head[f]=num;
    to[num]=t;
    w[num]=v;
}
void spfa(){
    while (q.size())
    {
        int f=q.front();
        q.pop();
        vis[f]=0;
        for(int i=head[f];i!=0;i=net[i]){
            int end=to[i];
            if(dis[end]>dis[f]+w[i]){
                dis[end]=dis[f]+w[i];
                if(vis[end]==0){
                    vis[end]=1;
                    q.push(end);
                }
            }
        }
    }
}
int main(){
    cin>>n>>m;
    fill(dis,dis+N,MIN);
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    q.push(1);
    dis[1]=0;
    vis[1]=1;
    spfa();
    // for(int i=1;i<=n;i++){
    //     cout<<dis[i]<<" ";
    // }
    cout<<dis[n];
    return 0;
}