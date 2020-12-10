#include<iostream>
#include<vector>
using namespace std;
bool mp[1001][1001];
int d[1001];
int n,m,start=1;
vector<int> res;

void dfs(int x){
    for(int i=1;i<=n;i++){
        if(mp[x][i]){
            mp[x][i]=0;
            mp[i][x]=0;
            res.push_back(i);
            dfs(i);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        mp[x][y]=1;
        mp[y][x]=1;
        d[x]++;
        d[y]++;
    }
    for(int i=1;i<=n;i++){
        if(d[i]%2!=0){
            start=i;
            break;
        }
    }
    res.push_back(start);
    dfs(start);
    for(int i=res.size()-1;i>=0;i--){
        cout<<res[i]<<" ";
    }
    return 0;
}