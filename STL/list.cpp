#include<iostream>
#include<list>//list��˫���������
using namespace std;
int main(){
    //����
    list<int> a;
    //list<int> a(10);
    //list<int> a(10,1);
    //list<int> b(a);
    for(int i=0;i<6;i++){
        a.push_back(i);
    }
    //��С����
    cout<<a.size()<<endl;//���С
    cout<<a.max_size()<<endl;//�������
    a.resize(0);//�޸Ĵ�С
    cout<<a.size()<<endl;
    //��Ӻ���
    a.push_back(2);//ĩβ���Ԫ��
    a.push_front(1);//ͷ������Ԫ��
    list<int>::iterator it;
    for(it=a.begin();it!=a.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    it=a.begin();
    //����
    a.insert(it,0);
    for(it=a.begin();it!=a.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    //����n����ͬ��Ԫ��
    it=a.begin();
    a.insert(it,2,1);
    for(it=a.begin();it!=a.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    //ͷ��ɾ��Ԫ��
    a.pop_front();
    //β��
    a.pop_back();
    it=a.begin();
    a.erase(it);
    //���ʺ���
    cout<<a.front()<<endl;
    cout<<a.back()<<endl;
    a.resize(0);
    a.push_back(3);
    a.push_back(4);
    list<int> b;
    b.push_back(1);
    b.push_back(2);
    b.assign(2,1);//��ֵ:ǰ����Ԫ�ظ�ֵΪ1
    for(it=b.begin();it!=b.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    a.merge(b);//�ϲ�������������
    for(it=a.begin();it!=a.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    list<int> c;
    c.push_back(5);
    c.push_back(6);
    c.push_back(7);
    c.push_back(8);
    //swap(a,c);//��Сһ�²��ܽ���
    a.swap(c);
    for(it=a.begin();it!=a.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    a.splice(it,c);//����λ�ò���list
    for(it=a.begin();it!=a.end();it++){
        cout<<*it<<" ";
    }
    a.unique();//�����ǰ����ȥ��
    for(it=a.begin();it!=a.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}