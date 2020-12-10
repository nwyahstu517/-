#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=10000;
const int INF=99999999;
int u[N];//�ߵ����;
int v[N];//�ߵ��յ�;
int w[N];//�ߵ�Ȩֵ;
int dis[N];//�洢��㵽i�ľ���
int bak[N];
int n,m;// n�� m��
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    //��ʼ��dis����
    for(int i=1;i<=n;i++){
        dis[i]=INF;
    }
    dis[1]=0;
    //����
    for(int i=1;i<=n-1;i++){
        memcpy(bak,dis,sizeof dis);
        for(int j=1;j<=m;j++){
            dis[v[j]]=min(dis[v[j]],dis[u[j]]+w[j]);
        }
        bool check=0;
        //��� dis �������ޱ仯
        for(int i=1;i<=n;i++){
            if(dis[i]!=bak[i]){
                check=1;
                break;
            }
        }
        if(check==0){
            break;
        }
    }
    //��⸺Ȩ��·
    bool flag=0;
    for(int j=1;j<=m;j++){
            if(dis[v[j]]>dis[u[j]]+w[j]){
                flag=1;
                break;
            }
    }
    if(flag){
        cout<<"���ڸ�Ȩ��·";
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    return 0;
}
