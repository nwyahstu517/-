#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N =6010;
int n;
int f[N][2];//f[i][0]ûѡȡ i 
int w[N];//�ڵ��Ȩֵ
int h[N],e[N],ne[N],idx;
bool st[N];//�����Ҹ�
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
void dfs(int u){
    f[u][1]=w[u];
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];//��ǰ�ߵ��յ�
        dfs(j);
        f[u][0]+=max(f[j][0],f[j][1]);
        f[u][1]+=f[j][0];
    }
}
int main(int argc, char const *argv[])
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];//����ֵ
    }
    memset(h,-1,sizeof h);
    //for(int i=0;i<n-1;i++){
        int a,b;
        while((cin>>a>>b)&&a!=0&&b!=0){
       // cin>>a>>b;
        add(b,a);//b��a�ĸ��ڵ�
        st[a]=1;//˵��a�и���
        }
    int root=1;
    while(st[root])root++;
    dfs(root);
    cout<<max(f[root][0],f[root][1]);
    return 0;
}
