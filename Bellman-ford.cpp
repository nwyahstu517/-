#include<iostream>
#include<cstring>
using namespace std;
struct Edge{
    int a,b,c;
}e[10000];
int n,m,k;
int dis[510],backup[510];
int main(){
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        cin>>e[i].a>>e[i].b>>e[i].c;
    }
    memset(dis,0x3f,sizeof dis);
    dis[1]=0;
    //bellman-fordÀ„∑®
    for(int i=1;i<=k;i++){
        memcpy(backup,dis,sizeof dis);
        for(int j=0;j<m;j++){
            dis[e[j].b]=min(dis[e[j].b],backup[e[j].a]+e[j].c);
        }
    }
    if(dis[n]>0x3f3f3f3f/2)puts("impossible");
    else cout<<dis[n];
    return 0;
}