#include<iostream>
#include<cstring>
#include<algorithm> 
using namespace std;
int main(int argc, char const *argv[])
{
	int n,m;//n个物品，容量m的背匄1�7
	cin>>n>>m;
	int w[20],v[20];
	for (int i = 1; i<=n; ++i)
	{
		cin>>w[i]>>v[i];
	}
	int f[20][20];
	int ff[20];
	memset(ff,0,sizeof ff);
	memset(f,0,sizeof f);
	/*for(int i=1;i<=n;i++){
		for(int j=m;j>=w[i];j--){//Ҫ������˳����ǰ���ֵ��Ӱ�� 
				ff[j]=max(ff[j],ff[j-w[i]]+v[i]); //�Ż� 
		}
	}
	cout<<ff[m];*/
	for(int i=1;i<=n;i++){
		for(int j=w[i];j<=m;j++){
			f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+v[i]);
		}
	} 
	cout<<f[n][m];
	return 0;
}
