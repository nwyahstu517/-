#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,m,l,r,mid,sum=0,mx=0,cn=0;
int vi[100001];
bool check(int x){
    int total=0;
    cn=0;
    for(int i=0;i<n;i++){
        if(vi[i]>x)return 0;
        total+=vi[i];
        if(total>mid){
            total=vi[i];
            cn++;
        }
    }  
    if(cn>=m)return 0;
    else return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>vi[i];
        mx=(mx,vi[i]);
        sum+=vi[i];
    }
    l=mx;
    r=sum;
    while (l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
    cout<<l;
    return 0;
}