#include<cstdio>
#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("1.txt");
ofstream fout("2.txt");
#define N 310
struct node{
    int vis[N];
}a[N];
int n,m,head,tail,flag;
int v[20][N];
int ok(int x){//验证 
    for(int i=1;i<=m;i++)
        if(!a[x].vis[i])return 0;
    return 1;
}
void bfs(){
    while(head<=tail){//不明确第一个状态，so"<=" 
        if(head>10*n) return ;//防止死循环 
        for(int i=1;i<=n;i++){
            ++tail;
            for(int j=1;j<=m;j++)//回溯 
                a[tail].vis[j]=a[head].vis[j];
            int ff=0;
            for(int j=1;j<=v[i][0];j++)
                if(a[tail].vis[v[i][j]]){//有1 - 不满足 
                    ff=1;break;
                }
            if(!ff){
                for(int j=1;j<=v[i][0];j++)
                    a[tail].vis[v[i][j]]=1;//更新vis 
                if(ok(tail)){
                    flag=1;
                    fout<<"Yes"<<endl;
                    return ;
                }
            }
            else
                tail--;//当前不满足，回溯 
        }
        head++;
    }
}
int main(){
    while(fin>>n>>m){
        memset(a,0,sizeof a);
        memset(v,0,sizeof v);
        for(int i=1,x;i<=n;i++){
            for(int j=1;j<=m;j++){
                fin>>x;
                if(x) v[i][++v[i][0]]=j;//模拟动态数组，v[i][++v[i][0]]=j;记录第i行第v[i][0]个1的列号j 
            }
        }
        head=0;tail=0;flag=0;
        bfs();
        if(!flag) fout<<"No"<<endl;
    }
    return 0;
}
