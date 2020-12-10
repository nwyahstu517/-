#include<iostream>
#include<vector>//vector文件
using namespace std;
/*
vector的长度是动态的，而且能获取长度
*/
int main(){
    //创建vector
    vector<int> v1;
    //vector<int> v2(v1);
    //vector<int> v3(n,i);
    //vector<int> v4(n);
    //获取大小
    int len=v1.size();
    cout<<"size="<<len<<endl;
    //push_back添加到末尾
    v1.push_back(1);
    for(int i=2;i<=3;i++){
        v1.push_back(i);
    }
    for(int i=0;i<=2;i++){
        cout<<v1[i]<<" ";//可以像数组使用下标
    }
    cout<<endl;
    for(int i=0;i<=2;i++){
        cout<<v1.at(i)<<" ";//也可以使用at获取下标
    }
    cout<<endl;
    //迭代器的使用
    vector<int>::iterator it;
    for(it=v1.begin();it!=v1.end();it++){
        cout<<*it<<" ";//像指针一样理解
    }
    cout<<endl;
    //程序退出前，释放vector
    v1.clear()//清除容器内的元素
    vector<int>().swap(v1);//释放内存
    //其他函数
    /*
    v1.empty();
    v1.erase(n);//删除第n位置的元素
    v1.erase(beg,end);//删除[beg,end)区间
    v1.front()//第一个数据
    v1.insert(pos,s);//在哪插入谁
    v1.pop_back();//删除最后一个元素
    v1.resize();
    */
    return 0;
}