#include<iostream>
#include<cstdio> 
using namespace std;
int e[100][100]; //�ڽӾ���
int visit[100];//��Ƕ����Ƿ����,��ʼΪ0 
int sum,n,m;//ͳ�Ʒ��ʵĶ�����Ŀ 
void dfs(int temp){
	cout<<temp<<" ";
	visit[temp]=1;//��Ƿ��� 
	sum++;
	if(sum==n)return;//�ݹ����
	for(int i=1;i<=n;i++){
		//�жϵ�ǰtemp��ÿ��i�Ƿ���ڱߣ�����iû�з��� 
		if(e[temp][i]==1&&visit[i]==0){//������� 
			visit[i]=1;
			dfs(i);
		}
	} 
	return;
} 
int main(){
cin>>n>>m;
//��ʼ������ͼ��ά���� 
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
dfs(1);//��1�Ŷ������ 
return 0;
}

