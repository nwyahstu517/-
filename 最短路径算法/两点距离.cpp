#include<iostream>
using namespace std;
const int N = 10010;
int MIN = 200000000 ;
int e[N][N] ; //�洢ͼ����Ϣ
int dis[N] ;//��㵽��������ľ���
int path[N] ;//��㵽�յ��·��
bool vis[N] ;//��Ǹõ���û�з���
int n,m,st,en;// n����  m����

void dijkstra(){
    int u;// ��¼��ת�Ķ�����
    for(int i=2 ;i<=n;i++){//��ʣ�µ� n-1 ���ڵ�����̵ıߵĶ���
        for(int j=1;j<=n;j++){
            if(!vis[j]&&dis[j]<MIN){
                MIN = dis[j];
                u = j;
            }
        }
         //�ҵ�����ת���� u ����u��ת����㵽����Ŀ�������ܷ���
         vis[u] = 1;
         MIN = 100000000 ;
         for(int i = 1;i <= n; i++){
            if(e[u][i]<MIN && dis[i]>dis[u]+e[u][i]){ //˵����תվ �� i �����ӣ����ܵ���
                dis[i]=dis[u]+e[u][i];
                path[i]=u;
             }
         }
    }
    // for(int i=1 ;i<=n;i++){
    //     cout<<dis[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=1 ;i<=n;i++){
    //     cout<<path[i]<<" ";
    // }
}


int main(){
    cin >> n >> m >>st>>en;//��� �յ�
    //��ʼ��ͼ
    for(int i = 1; i<= n; i++){
        for(int j =1; j<= n; j++){
            if(i == j){
                e[i][j] = 0;
            }else{
                e[i][j]= MIN;
            }
        }
    }
    // �����֮��Ĺ�ϵ
    for(int i=1 ;i<=m ;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e[a][b]=c;
        e[b][a]=c;//����ͼ
    }
    //��ʼ��dis ��path����
    // ����� st �ڽӵĵ���г�ʼ��
    for(int i=1 ;i<=n ;i++){
        dis[i]=e[st][i];// ��� st �����ڵĵ��Ȩֵ
    }
    vis[st] = 1;// ������ ����st ��ʼ
    dijkstra();
    cout<<dis[en];
    return 0;
}