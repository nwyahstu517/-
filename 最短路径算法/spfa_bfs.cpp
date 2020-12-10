#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
const int N=10010;
const int M=20010;
using namespace std;
int n,m,idx;//n���㣬m����
int ne[M];//�洢��һ���ߺ�
int w[M];//�洢�ߵ�Ȩֵ
int v[M];//�洢�ߵ��յ�
int first[N];//�洢�ýڵ����µıߺ�
bool vis[N];
int d[N];//��¼����
int cnt[N];//��¼��㵽������㾭���ĵ������
void add(int x,int y,int z){
    idx++;
    ne[idx]=first[x];
    first[x]=idx;
    v[idx]=y;
    w[idx]=z;
}
bool spfa(int s){
    queue<int> q;
    memset(d,127,sizeof d);
    d[s]=0;
    cnt[s]=1;
    q.push(s);
    vis[s]=1;
    while (q.size())
    {
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(int i=first[x];i;i=ne[i]){
            int y=v[i];
            if(d[y]>d[x]+w[i]){
                d[y]=d[x]+w[i];
                cnt[y]=cnt[x]+1;
                if(cnt[y]>n){
                    return false;
                }
                if(!vis[y]){
                    q.push(y);
                    vis[y]=1;
                }
            }
        }
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    bool flag;
    flag=spfa(1);
    if(!flag){
        cout<<"����";
    }else{
        cout<<"�޸���";
    }
    return 0;
}
