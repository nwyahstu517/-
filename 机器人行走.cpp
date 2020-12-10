#include<iostream>
#include<cstring>
using namespace  std;
int main(){
    string s;
    int t;
    cin>>s>>t;
    //比较周期
    int len=s.size(),x=0,y=0;
    if(t<=len){
        for(int i=0;i<t;i++){
            if(s[i]=='N')
                y++;
            else if(s[i]=='S')
                y--;
            else if(s[i]=='W')
                x--;
            else if(s[i]=='E')
                x++;
        }
    }else{
        for(int i=0;i<len;i++){
            if(s[i]=='N')
                y++;
            else if(s[i]=='S')
                y--;
            else if(s[i]=='W')
                x--;
            else if(s[i]=='E')
                x++;
        }//一个周期后的坐标
        x*=t/len;
        y*=t/len;
        for(int i=0;i<t%len;i++){
            if(s[i]=='N')
                y++;
            else if(s[i]=='S')
                y--;
            else if(s[i]=='W')
                x--;
            else if(s[i]=='E')
                x++;
        }
    }
    cout<<x<<" "<<y;
}