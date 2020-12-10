#include<iostream>
#include<cstring>
#include<queue>
#include<iomanip>
using namespace std;
const int N=1E5+10;
int head[2*N],to[2*N],ne[2*N],w[2*N],idx;
void add(int from,int t,int value){
    ne[idx]=head[from];
    to[idx]=t;
    w[idx]=value;
    head[from]=idx++;
}
struct Node
{
    int data;
    double gl;//¸ÅÂÊ
}node[2*N];
queue<Node> q;
int chudu[N];
int rudu[N];
int n,m;
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    double ans=0;
    memset(head,-1,sizeof head);
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        chudu[a]++;
        rudu[b]++;
    }
    node[1].data=1;
    node[1].gl=1;
    q.push(node[1]);
    while (q.size())
    {
        Node t=q.front();
        double g=t.gl/chudu[t.data];
        q.pop();
        for(int k=head[t.data];k!=-1;k=ne[k]){
            int z=to[k];
            node[z].data=z;
            node[z].gl+=g;
            ans+=g*w[k];
            rudu[z]--;
            if(!rudu[z])q.push(node[z]);
        }
    }
    cout<<fixed<<setprecision(2)<<ans;
    return 0;
}