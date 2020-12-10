#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 10010, M = N * 2;
int ans=N;
int n;
int h[N],e[M],ne[M],idx;
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
int dfs(int u,int father){
    int res=0,sum=0;//sum 存储他儿子一共有多少节点
    for(int i=h[u];~i;i = ne[i]){
        int j=e[i];
        if(j == father)continue;
        int t=dfs(j,u);//返回当前节点的儿子返回的子孙节点的数量
        res=max(res,t);//当删除当前节点后，他的左右儿子节点相互对比，更新最大的连通点的值
        sum+=t;//统计他的子孙的数量，他儿子中最大的连通点和他的上右连通节点比大小，保存最大连通点的值
    }
    //这一步 ，每个点只会执行一一次
    res = max(res,n-sum-1);//当删除该节点后，
    ans = min(ans,res);//所有最大连通点中的最小值
    return sum+1;
}
int main(){
    cin >> n;
    memset(h,-1,sizeof h);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    dfs(1,-1);
    cout<<ans;
    return  0;
}