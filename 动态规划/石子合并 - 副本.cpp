#include<bits/stdc++.h>
using namespace std;
const int imax =0x7F7F7F7F;//����ֵ 
int n;
int dp[2000][2000];//������ 
int sum[2000];//�������� 
int a[2000];//�������� 
int s[2000][2000];//��¼i��j֮������ŷָ��
void init()//��ʼ��
{
	memset(sum,0,sizeof(sum));
	memset(dp,imax,sizeof(dp));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];//1 2 3 4 
		sum[i]+=sum[i-1]+a[i];//0+1=1  1+2=3
		dp[i][i] = 0;
		s[i][i]=i;//��ʼֵ
	}
} 

int solve()
{
	init();
	for(int v=1;v<n;v++)//v�����䳤��
	{
		for(int i=1;i<=n-v;i++)//i������� 
		{
			int j = i+v;//j�����յ�
			int s = sum[j]-sum[i-1];//�ϲ����� 
			for(int k=i;k<j;k++)
			dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+s); 
		}
	}
	return dp[1][n];
}
int main()
{
	cout<<solve();
	return 0;
}