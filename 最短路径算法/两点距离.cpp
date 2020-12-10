#include<iostream>
using namespace std;
const int N = 10010;
int MIN = 200000000 ;
int e[N][N] ; //存储图的信息
int dis[N] ;//起点到其他各点的距离
int path[N] ;//起点到终点的路径
bool vis[N] ;//标记该点有没有访问
int n,m,st,en;// n个点  m条边

void dijkstra(){
    int u;// 记录中转的顶点编号
    for(int i=2 ;i<=n;i++){//从剩下的 n-1 个节点找最短的边的顶点
        for(int j=1;j<=n;j++){
            if(!vis[j]&&dis[j]<MIN){
                MIN = dis[j];
                u = j;
            }
        }
         //找到了中转顶点 u ，从u中转看起点到各个目标点距离能否变短
         vis[u] = 1;
         MIN = 100000000 ;
         for(int i = 1;i <= n; i++){
            if(e[u][i]<MIN && dis[i]>dis[u]+e[u][i]){ //说明中转站 和 i 有连接，即能到达
                dis[i]=dis[u]+e[u][i];
                path[i]=u;
             }
         }
    }
    // for(int i=1 ;i<=n;i++){
    //     cout<<dis[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=1 ;i<=n;i++){
    //     cout<<path[i]<<" ";
    // }
}


int main(){
    cin >> n >> m >>st>>en;//起点 终点
    //初始化图
    for(int i = 1; i<= n; i++){
        for(int j =1; j<= n; j++){
            if(i == j){
                e[i][j] = 0;
            }else{
                e[i][j]= MIN;
            }
        }
    }
    // 输入边之间的关系
    for(int i=1 ;i<=m ;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e[a][b]=c;
        e[b][a]=c;//无向图
    }
    //初始化dis ，path数组
    // 与起点 st 邻接的点进行初始化
    for(int i=1 ;i<=n ;i++){
        dis[i]=e[st][i];// 起点 st 到相邻的点的权值
    }
    vis[st] = 1;// 标记起点 ，从st 开始
    dijkstra();
    cout<<dis[en];
    return 0;
}