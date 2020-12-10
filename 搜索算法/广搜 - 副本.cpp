#include<iostream>
using namespace std;
int e[100][100];//存储边
int visit[100];//标记顶点是否访问
int n,m,sum=1,count;//n个顶点 m条边
int d[100];
int main(){
cin>>n>>m;
//对e数组进行初始化
for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
		if(i==j) e[i][j]=0;
		else e[i][j]=0x3f;
	}
}
for(int i=1;i<=m;i++){
	int a,b;
	cin>>a>>b;
	e[a][b]=e[b][a]=1;
}
d[1]=1;//1 入队列 
visit[1]=1;//标记访问 
while(count!=n){
int temp=d[1];//记录队首 
cout<<temp<<" ";
count++;
for(int i=1;i<=n;i++){//与队首相连的点入数组 
	if(e[temp][i]==1&&visit[i]==0){
		d[++sum]=i;
		visit[i]=1;
	}
}
for(int i=1;i<=sum;i++){//删除队首，后面的元素往前挪 
	d[i]=d[i+1];
}
sum--;//长度减 1 
}
return 0;
}

