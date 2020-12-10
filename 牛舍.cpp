#include<iostream>
#include<algorithm>
using namespace std;
int n;
int a[1010];
long long f[1010];//f[i]代表 i 为进口的距离
int main(){
  cin>>n;
  long long dis=999999999999999999;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    for(int j=i+1;;j++){
      j%=n;
      if(j==i)break;
      if(j>i){
        f[i]+=a[j]*(j-i);
      }else{
        f[i]+=a[j]*(n-(i-j));
      }
    }
    dis=min(dis,f[i]); 
  }
  cout<<dis;
  return 0;
}