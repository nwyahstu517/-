#include <iostream>
#include <cstring>
using namespace std;
struct edge_node{
    int to;
    int next;
}edge[100];
int main(){
    int vertex[10];
    memset(vertex,-1,sizeof(vertex));
    int n;
    cin>>n;
    int cnt=1; 
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        //��װ�Լ�
        edge[cnt].to=b;
        edge[cnt].next=vertex[a];
        vertex[a]=cnt++; 
    }
    cout<<"---------------���ÿ���ڵ�Ĵ洢���---------------"<<endl;
    cout<<"edge[i].to"<<" "<<"edge[i].next"<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<edge[i].to<<" "<<edge[i].next<<endl;
    }
    //���ÿ���ڵ�ı�
    cout<<"---------------���ÿ���ڵ�ı�---------------"<<endl;
    for(int i=1;i<=6;i++){//���� 
        cout<<i<<": ";
        for(int j=vertex[i];j!=-1;j=edge[j].next){//������ 
            cout<<edge[j].to<<" ";
        }
        cout<<endl; 
    } 
    return 0;
}
