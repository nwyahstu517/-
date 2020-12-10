#include<iostream>
#include<queue>
using namespace std;
//标记四个方向
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
int mp[40][40];
bool visit[40][40];
int n;
queue<int> x;//记录行坐标
queue<int> y;//记录列坐标
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mp[i][j];
        }
    }
    x.push(0);y.push(0);//起始点坐标
    visit[0][0]=1;
    while (!x.empty())
    {
        //遍历四个方向，但是有些方向去不了
        for(int i=0;i<4;i++){
            int hzb=dx[i]+x.front();
            int zzb=dy[i]+y.front();
            if(hzb>=0&&hzb<=n+1&&zzb>=0&&zzb<=n+1&&mp[hzb][zzb]==0&&!visit[hzb][zzb]){
                x.push(hzb);
                y.push(zzb);
                visit[hzb][zzb]=1;
            }
        }
        x.pop();
        y.pop();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mp[i][j]==0&&visit[i][j]==0){
                cout<<2<<" ";
            }else{
                cout<<mp[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}