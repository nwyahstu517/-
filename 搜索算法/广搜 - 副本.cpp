#include<iostream>
using namespace std;
int e[100][100];//�洢��
int visit[100];//��Ƕ����Ƿ����
int n,m,sum=1,count;//n������ m����
int d[100];
int main(){
cin>>n>>m;
//��e������г�ʼ��
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
d[1]=1;//1 ����� 
visit[1]=1;//��Ƿ��� 
while(count!=n){
int temp=d[1];//��¼���� 
cout<<temp<<" ";
count++;
for(int i=1;i<=n;i++){//����������ĵ������� 
	if(e[temp][i]==1&&visit[i]==0){
		d[++sum]=i;
		visit[i]=1;
	}
}
for(int i=1;i<=sum;i++){//ɾ�����ף������Ԫ����ǰŲ 
	d[i]=d[i+1];
}
sum--;//���ȼ� 1 
}
return 0;
}

