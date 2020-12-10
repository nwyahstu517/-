#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 1000
// 描述边的信息
struct e{
    int to;
    int next;
    int val;
};
int head[MAXN],num=1;
e ee[MAXN];
void add(int from,int to){
    ee[num].next=head[from];
    ee[num].to=to;
    head[from]=num++;
}
int main(){
    memset(head,0,sizeof head);
    //上图 4个顶点  5条边  但是无向图是要保存双向，明白吧。
    for(int i=1;i<=5;i++){
        int from,to,val;//这里val就不输入了，因为是 0
        cin>>from>>to;
        add(from,to);
        add(to,from);
    }
    for(int i=1;i<=4;i++){//遍历每个起点
        for(int j=head[i];j!=0;){
            if(ee[j].to!=0){
                cout<<i<<" "<<ee[j].to<<endl;
            }
            j=head[i]=ee[j].next;
        }
        cout<<endl;
    }
    return 0;
}