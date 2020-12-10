#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;
class Solution
{
public:
    vector<int> shortestToChar(string s,char c){
      vector<int> res;//记录答案
      vector<int> con;//记录每个c的下标
      int l=0,k=0,Size=s.size(),cs=0;
      for(int i=0;i<Size;i++){
        int tem=s.find(c,i);//从 i 开始查找 c
        if(tem!=string::npos){
          con.push_back(tem);
        }
      }
      cs=con.size();
      while(1){
        // loveleetcode   e
        //            k

        //        l
        // 3 5 6 11  

        //res:3 2 1 0
        if(k<=con[l]&&l==0){
          res.push_back(con[l]-k);
          k++;
        }else if(k<=con[l]&&l>=1){
          int m=min(con[l]-k,k-con[l-1]);
          res.push_back(m);
          k++;
        }else if(k>con[l]&&l==cs-1){
          res.push_back(k-con[l]);
          k++;
        }
        else{
          l++;
        }
        if(k==Size){
          return res;
        }
      }
    }
};

int main(){
  string s;
  char c;
  cin>>s;
  cin>>c;
  Solution so;
  vector<int> t=so.shortestToChar(s,c);
  vector<int>::iterator it;
  for(it=t.begin();it!=t.end();it++){
    cout<<*it<<" ";
  }
  return 0;
}