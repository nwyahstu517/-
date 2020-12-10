#include<iostream>
using namespace std;
int main(){
    int m,n,k;
    cin>>m>>n>>k;
    int a[100][100],b[100][100],c[100][100]={0};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>b[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            for(int l=0;l<n;l++){
                c[i][j]+=a[i][l]*b[l][j];
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}