#include<iostream>
#include<cstring>
#define MAXN 100
using namespace std;
int n;//n������
int m;//m����
int u[MAXN],v[MAXN],w[MAXN];//��� �յ� Ȩֵ
int first[MAXN];//��¼�õ�����һ�����
int next[MAXN];//��¼�õ�ġ���һ����š�
int main(){
    cin>>n>>m;
    memset(first,-1,sizeof first);
    for(int i=1;i<=m;i++){//������
        cin>>u[i]>>v[i]>>w[i];
        next[i]=first[u[i]];
        first[u[i]]=i;
    }
    //���� 1�Ŷ�������б�
    int k=first[1];
    while(k!=-1){
        cout<<u[k]<<" "<<v[k]<<" "<<w[k]<<endl;
        k=next[k];
    }
    cout<<endl;
    //�������е�ı�
    for(int i=1;i<=n;i++){
       k=first[i];
        while(k!=-1){
            cout<<u[k]<<" "<<v[k]<<" "<<w[k]<<endl;
            k=next[k];
        } 
    }
    
    return 0;
}