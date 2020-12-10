#include<iostream>
using namespace std;
const int N=10000;
int a[N];
int f[N];
int n;
int main(int argc, char const *argv[])
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    fill(f,f+N,1);
    int maxn=f[0];
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]<a[i]){
                f[i]=max(f[i],f[j]+1);
            }
        }
        //cout<<f[i]<<" ";
        maxn=max(maxn,f[i]);
    }
    cout<<maxn;
    return 0;
}
