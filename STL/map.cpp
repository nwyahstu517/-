#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,string> mp;
    //插入键值对
    mp.insert(pair<int,string>(3,"one"));
    mp[2]="two";
    //迭代遍历：根据key排序的
    map<int,string>::iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    //数组遍历
    int len=mp.size();
    for(int i=0;i<len;i++){
        cout<<mp[i]<<" ";
    }
    mp.erase(mp.begin());
    //查找
    it=mp.find(3);
    if(it!=mp.end()){
        cout<<it->first<<" "<<it->second;
    }
    return 0;
}