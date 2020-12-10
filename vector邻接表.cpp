#include<iostream>
#include<vector>
#define MAXN 100
using namespace std;
int n,m;
struct edge{
    int to;
    int cost;
};
vector<edge> mp[100];
int main(){
    cin>>n>>m;//n个顶点 m条边
    int s;//有向边的起点序号
    for(int i=1;i<=m;i++){//输入编号
        edge e;
        cin>>s>>e.to>>e.cost;
        mp[s].push_back(e);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<mp[i].size();j++){
            cout<<"起点："<<i<<"  终点"<<mp[i][j].to<<"  权值"<<mp[i][j].cost<<endl;
        }
    }
    return 0;
}