#include<iostream>
#include<cstring>
using namespace  std;
int main(){
    string s;
    int t;
    cin>>s>>t;
    //�Ƚ�����
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
        }//һ�����ں������
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