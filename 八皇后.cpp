#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
int col[40]={0};
int zs[40]={0};//行列之和相等 
int yx[40]={0};
int a[40]={0};
void pr(){
	if(cnt<=3){
		for(int i=1;i<=n;i++){
		   cout<<a[i]<<" ";
	    }
	    cout<<endl;
	}
}
void dfs(int x){//x 可以代表行的意思
	if(x>n){
		cnt++;
		pr();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!col[i]&&!zs[x+i]&&!yx[x-i+n]){
			col[i]=1;
			zs[x+i]=1;
			yx[x-i+n]=1;
			a[x]=i;
			dfs(x+1);
			col[i]=0;
			zs[x+i]=0;
			yx[x-i+n]=0;
		}
	}
}
int main(){
	memset(col,0,sizeof col);
	memset(zs,0,sizeof col);
	memset(yx,0,sizeof col);
	cin>>n;
	dfs(1);
	cout<<cnt;
	return 0;
}
