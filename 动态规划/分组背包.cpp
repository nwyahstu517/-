#include <iostream>     // std::cout
#include <cstring>    // std::minmax_element     // std::array
using namespace std;
struct bag{
  int tot;//记录该组有多少件物品
  int w[5],v[5];
}a[66];
int dp[32005];
int main () {
  int n,m,count=1;//count记录有多少组
  cin>>m>>n;
  for(int i=1;i<=n;i++){
    int x,y,z;
    cin>>x>>y>>z;
    if(z==0){
      a[i].tot=1;
      a[i].w[1]=x;
      a[i].v[1]=x*y;
    }else{
      if(a[z].tot==1){//该组只有主件
        a[z].w[2]=a[z].w[1]+x;
        a[z].v[2]=a[z].v[1]+x*y;
        a[z].tot=2;
      }else{
        a[z].w[3]=a[z].w[1]+x;
        a[z].v[3]=a[z].v[1]+x*y;//第二件附件和主件绑定
        a[z].w[4]=a[z].w[2]+x;
        a[z].v[4]=a[z].v[2]+x*y;
        a[z].tot=4;
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=m;j>=0;j--){
      for(int k=1;k<=a[i].tot;k++){
        if(j>=a[i].w[k]){
          dp[j]=max(dp[j],dp[j-a[i].w[k]]+a[i].v[k]);
        }
      }
    }
  }
  cout<<dp[m];
  return 0;
}