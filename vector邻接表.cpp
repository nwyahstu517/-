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
    cin>>n>>m;//n������ m����
    int s;//����ߵ�������
    for(int i=1;i<=m;i++){//������
        edge e;
        cin>>s>>e.to>>e.cost;
        mp[s].push_back(e);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<mp[i].size();j++){
            cout<<"��㣺"<<i<<"  �յ�"<<mp[i][j].to<<"  Ȩֵ"<<mp[i][j].cost<<endl;
        }
    }
    return 0;
}