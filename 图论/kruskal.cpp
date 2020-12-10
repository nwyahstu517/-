#include<bits/stdc++.h>
using namespace std;
struct EDGE{
    int x;
    int y;
    int v;
}a[9901];//边
int fat[101];//初始每个数为单独集合
int n;
int father(int x){
    if(x!=fat[x]){
        fat[x]=father(fat[x]);
    }
    return fat[x];
}
void unionn(int x,int y){
    int fa=father(x);
    int fb=father(y);
    if(fa!=fb){
        fat[fa]=fb;
    }
}
bool cmp(EDGE a,EDGE b){
    return a.v<b.v;
}
int main(){
    cin>>n;
    int m=0,x;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>x;
            if(x!=0){
                m++;
                a[m].x=i;
                a[m].y=j;
                a[m].v=x;
            }
        }
    }
    for(int i=1;i<=n;i++){
        fat[i]=i;
    }
    
    sort(a+1,a+m+1,cmp);
    int tot=0;
    int k=0;
    for(int i=1;i<=m;i++){
        if(father(a[i].x)!=father(a[i].y)){
            unionn(a[i].x,a[i].y);
            tot+=a[i].v;
            k++;
        }
        if(k==n-1)break;
    }
    cout<<tot;
    return 0;
}