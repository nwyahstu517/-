#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    bool flag[5001];
    memset(flag,0,sizeof flag);
    for(int i=1;i<=m;i++){//�˵ı��
        for(int j=1;j<=n;j++){//�Ƶı��
            if(j%i==0){
                flag[j]=!flag[j];
            }
        }
        
    }
    bool f=true;
    for(int j=1;j<=n;j++){
        if(flag[j]&&f){
            cout<<j;
            f=false;
            continue;
        }
        if(flag[j])
            cout<<','<<j;
    }
}