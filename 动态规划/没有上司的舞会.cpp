#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N =6010;
int n;
int f[N][2];//f[i][0]没选取 i 
int w[N];//节点的权值
int h[N],e[N],ne[N],idx;
bool st[N];//用于找根
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
void dfs(int u){
    f[u][1]=w[u];
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];//当前边的终点
        dfs(j);
        f[u][0]+=max(f[j][0],f[j][1]);
        f[u][1]+=f[j][0];
    }
}
int main(int argc, char const *argv[])
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];//高兴值
    }
    memset(h,-1,sizeof h);
    //for(int i=0;i<n-1;i++){
        int a,b;
        while((cin>>a>>b)&&a!=0&&b!=0){
       // cin>>a>>b;
        add(b,a);//b是a的父节点
        st[a]=1;//说明a有父亲
        }
    int root=1;
    while(st[root])root++;
    dfs(root);
    cout<<max(f[root][0],f[root][1]);
    return 0;
}
