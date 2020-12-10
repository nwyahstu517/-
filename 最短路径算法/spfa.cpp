#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N=10000;
const int INF=99999999;
int u[N];//�ߵ����;
int v[N];//�ߵ��յ�;
int w[N];//�ߵ�Ȩֵ;
int dis[N];//�洢��㵽i�ľ���
bool vis[N];
int first[N],nex[N];
int n,m;// n�� m��
queue<int> q;
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    //��ʼ��dis����
    for(int i=1;i<=n;i++){
        dis[i]=INF;
    }
    dis[1]=0;
    memset(first,-1,sizeof first);
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        nex[i]=first[u[i]];
        first[u[i]]=i;
    }

    //spfaʹ�ö��д���
    q.push(1);
    vis[1]=1;
    while (q.size())
    {
        int k=first[q.front()];//�õ���ǰ���׵�һ����
        while(k!=-1){
            if(dis[v[k]]>dis[u[k]]+w[k]){
                dis[v[k]]=dis[u[k]]+w[k];
                if(vis[v[k]]==0){
                    q.push(v[k]);
                    vis[v[k]]=1;
                }
            }
            k=nex[k];
        }
        vis[q.front()]=0;
        q.pop();
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    return 0;
}
