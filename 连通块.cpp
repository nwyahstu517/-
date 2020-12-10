#include<iostream>
#include<vector>
using namespace std;
const int N=1000;
vector<int> G[N];//�ڽӱ�
bool vis[N];
int n,m;
void dfs(int v){
    vis[v]=1;
    for(int i=0;i<G[v].size();i++){
        if(vis[G[v][i]]==0){
            dfs(G[v][i]);
        }
    }
}
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int block=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i);
            block++;
        }
    }
    if(block==1){
        cout<<"��ͨͼ";
    }else{
        cout<<"������ͨͼ";
    }
    return 0;
}
