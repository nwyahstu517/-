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
        //武装自己
        edge[cnt].to=b;
        edge[cnt].next=vertex[a];
        vertex[a]=cnt++; 
    }
    cout<<"---------------输出每个节点的存储情况---------------"<<endl;
    cout<<"edge[i].to"<<" "<<"edge[i].next"<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<edge[i].to<<" "<<edge[i].next<<endl;
    }
    //输出每个节点的边
    cout<<"---------------输出每个节点的边---------------"<<endl;
    for(int i=1;i<=6;i++){//顶点 
        cout<<i<<": ";
        for(int j=vertex[i];j!=-1;j=edge[j].next){//遍历边 
            cout<<edge[j].to<<" ";
        }
        cout<<endl; 
    } 
    return 0;
}
