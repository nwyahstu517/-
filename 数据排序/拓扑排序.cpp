#include<iostream>
#include<queue>
using namespace std;
const int MAXN=10005;
int n,m;
int indeg[MAXN];
queue<int> q;
bool a[MAXN][MAXN];
int ans[MAXN],cnt;
void input(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
        indeg[y]++;
    }
}
void topo_sort(){
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while (q.size())
    {
        int u=q.front();
        ans[++cnt]=u;
        q.pop();
        // 将 u 相关联的点的入度减去1
        for(int i=1;i<=n;i++){
            if(a[u][i]){
                indeg[i]--;
                if(indeg[i]==0){
                    q.push(i);
                }
            }
        }
    } 
}
void put(){
    if(cnt<n){
        cout<<"存在环";
        return;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}
int main(int argc, char const *argv[])
{
    input();
    topo_sort();
    put();
    return 0;
}
