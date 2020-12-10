#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[5000],b[5000],c[5000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i]==b[j]){
                c[k++]=a[i];
            }
        }
    }
    sort(c,c+k);
    for(int i=0;i<k;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}