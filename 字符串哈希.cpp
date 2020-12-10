#include<iostream>
#include<cstring>
using namespace std;
typedef unsigned long long ULL;
const int N=100010,base=131;//p进制  131 或者 13331
char str[N];
ULL h[N],p[N];
ULL get(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}
int main(){
    cin >> str+1;
    int n=strlen(str+1);
    p[0]=1;//每一位的进制
    for(int i=1;i<=n;i++){
        h[i]=h[i-1]*base+str[i]-'a'+1;
        p[i]=p[i-1]*base;
    }
    int m;
    cin>>m;
    while(m--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(get(l1,r1)==get(l2,r2))cout<<"Yes"<<endl;else cout<<"No"<<endl;
    }
    return 0;
}