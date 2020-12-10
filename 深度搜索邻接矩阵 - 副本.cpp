#include<iostream>
#include<cstdio> 
using namespace std;
int e[100][100]; //邻接矩阵
int visit[100];//标记顶点是否访问,初始为0 
int sum,n,m;//统计访问的顶点数目 
void dfs(int temp){
	cout<<temp<<" ";
	visit[temp]=1;//标记访问 
	sum++;
	if(sum==n)return;//递归出口
	for(int i=1;i<=n;i++){
		//判断当前temp到每个i是否存在边，并且i没有访问 
		if(e[temp][i]==1&&visit[i]==0){//如果存在 
			visit[i]=1;
			dfs(i);
		}
	} 
	return;
} 
int main(){
cin>>n>>m;
//初始化无向图二维矩阵 
for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
		if(i==j)e[i][j]=0;
		else e[i][j]=0x3f;
	}
}
for(int i=1;i<=m;i++){
	int a,b;
	cin>>a>>b;
	e[a][b]=e[b][a]=1;
}
dfs(1);//从1号顶点出发 
return 0;
}

