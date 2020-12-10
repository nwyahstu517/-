#include<iostream>
using namespace std;
int n,s;
void hannoi(int n,char a,char b,char c){
    if(n==1){
        cout<<"ÒÆ¶¯Ô²ÅÌ:"<<n<<"´ÓÅÌ"<<a<<"µ½ÅÌ"<<c<<endl;
        s++;
    }else{
        hannoi(n-1,a,c,b);//½Ó´¥CÅÌÒÆµ½bÅÌ
        cout<<"ÒÆ¶¯Ô²ÅÌ:"<<n<<"´ÓÅÌ"<<a<<"µ½ÅÌ"<<c<<endl;
        s++;
        hannoi(n-1,b,a,c);
    }
}
int main(){
cin>>n;

hannoi(n,'a','b','c');
cout<<s;
return 0;
}