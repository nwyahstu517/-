#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
  int x,y;
  cin>>x>>y;
  int step=0,r=1,t=1,f=1;
  while(1){
    int xx=x;
    r=t*f;//¿ØÖÆ 1 -2 4 -8
    xx=xx+r;// 1 -2
    step+=t;// 1 4
    //ÓÒ±ß
    if(y>=x&&xx>=y){
        step-=xx-y;
        break;
    }else if(y<=x&&xx<=y){
        step-=y-xx;
        break;
    }
    step+=t;//2
    t*=2;
    f*=-1;
  }
  cout<<step;
  return 0;
}