#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int year,month;
int month_day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
string blanks[8]={"","    ","        ","            ","                ","                    ","                        ",""};
int cnt[8]={0,1,2,3,4,5,6,0};
bool is_run(int y){
  if(y%4==0&&y%100!=0||y%400==0){
    return 1;
  }
  return 0;
}
void out(){
  //判断Month月1号是星期几
  int sum=0;
  for(int i=1900;i<year;i++){
    if(is_run(i)){
      sum+=366;
    }else{
      sum+=365;
    }
  }
  for(int i=1;i<month;i++){
    sum+=month_day[i];
  }
  int xq=sum%7+1;
  cout<<"Sun"<<setw(4)<<"Mon"<<setw(4)<<"Tus"<<setw(4)<<"Wed"<<setw(4)<<"Thu"<<setw(4)<<"Fri"<<setw(4)<<"Sat"<<endl;
  cout<<blanks[xq];
  int num=cnt[xq];
  if(is_run(year))month_day[2]=29;
  for(int i=1;i<=month_day[month];i++){
    cout<<setw(3)<<i;
    num++;
    if(num%7==0)cout<<endl;else cout<<" ";
  }
}
int main(){
  cin>>year>>month;
  out();
  return 0;
}
