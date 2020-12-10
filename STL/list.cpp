#include<iostream>
#include<list>//list由双向链表组成
using namespace std;
int main(){
    //定义
    list<int> a;
    //list<int> a(10);
    //list<int> a(10,1);
    //list<int> b(a);
    for(int i=0;i<6;i++){
        a.push_back(i);
    }
    //大小函数
    cout<<a.size()<<endl;//测大小
    cout<<a.max_size()<<endl;//最大容量
    a.resize(0);//修改大小
    cout<<a.size()<<endl;
    //添加函数
    a.push_back(2);//末尾添加元素
    a.push_front(1);//头部增加元素
    list<int>::iterator it;
    for(it=a.begin();it!=a.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    it=a.begin();
    //插入
    a.insert(it,0);
    for(it=a.begin();it!=a.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    //插入n个相同的元素
    it=a.begin();
    a.insert(it,2,1);
    for(it=a.begin();it!=a.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    //头部删除元素
    a.pop_front();
    //尾部
    a.pop_back();
    it=a.begin();
    a.erase(it);
    //访问函数
    cout<<a.front()<<endl;
    cout<<a.back()<<endl;
    a.resize(0);
    a.push_back(3);
    a.push_back(4);
    list<int> b;
    b.push_back(1);
    b.push_back(2);
    b.assign(2,1);//赋值:前两个元素赋值为1
    for(it=b.begin();it!=b.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    a.merge(b);//合并，并有序链表
    for(it=a.begin();it!=a.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    list<int> c;
    c.push_back(5);
    c.push_back(6);
    c.push_back(7);
    c.push_back(8);
    //swap(a,c);//大小一致才能交换
    a.swap(c);
    for(it=a.begin();it!=a.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    a.splice(it,c);//任意位置插入list
    for(it=a.begin();it!=a.end();it++){
        cout<<*it<<" ";
    }
    a.unique();//有序的前提下去重
    for(it=a.begin();it!=a.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}