#include<bits/stdc++.h>
using namespace std;
const int imax =0x7F7F7F7F;//极大值 
int n;
int dp[2000][2000];//答案数组 
int sum[2000];//花费数组 
int a[2000];//数据数组 
int s[2000][2000];//记录i和j之间的最优分割点
void init()//初始化
{
	memset(sum,0,sizeof(sum));
	memset(dp,imax,sizeof(dp));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];//1 2 3 4 
		sum[i]+=sum[i-1]+a[i];//0+1=1  1+2=3
		dp[i][i] = 0;
		s[i][i]=i;//初始值
	}
} 

int solve()
{
	init();
	for(int v=1;v<n;v++)//v是区间长度
	{
		for(int i=1;i<=n-v;i++)//i控制起点 
		{
			int j = i+v;//j控制终点
			int s = sum[j]-sum[i-1];//合并花费 
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