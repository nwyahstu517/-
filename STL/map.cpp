#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,string> mp;
    //�����ֵ��
    mp.insert(pair<int,string>(3,"one"));
    mp[2]="two";
    //��������������key�����
    map<int,string>::iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    //�������
    int len=mp.size();
    for(int i=0;i<len;i++){
        cout<<mp[i]<<" ";
    }
    mp.erase(mp.begin());
    //����
    it=mp.find(3);
    if(it!=mp.end()){
        cout<<it->first<<" "<<it->second;
    }
    return 0;
}