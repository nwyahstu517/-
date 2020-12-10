#include<iostream>
#include<queue>
using namespace std;
const int MAXN =10005;
int n,m;
int indeg[MAXN];//统计点的入度
queue<int> q;//采用队列思想
bool a[MAXN][MAXN];//记录是否有边
int ans[MAXN],cnt;//记录答案
void input(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        a[x][y]=1;//x->y  
        indeg[y]++;//y就有了入度
    }
}
void topo_sort(){
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while (!q.empty())
    {
        const int u=q.front();
        ans[++cnt]=u;
        q.pop();
        for(int i=1;i<=n;i++){
            if(a[u][i]){
                indeg[i]--;//删除的操作转化为入度为1
                if(indeg[i]==0){
                    q.push(i);
                }
            }
        }
    }
    
}
void output(){
    if(cnt<n)//判断是否有环，答案队列不足即有环
    {
        cout<<"有环！"<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    input();
    topo_sort();
    output();
    return 0;
}