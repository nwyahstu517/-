#include<iostream>
#include<vector>//vector�ļ�
using namespace std;
/*
vector�ĳ����Ƕ�̬�ģ������ܻ�ȡ����
*/
int main(){
    //����vector
    vector<int> v1;
    //vector<int> v2(v1);
    //vector<int> v3(n,i);
    //vector<int> v4(n);
    //��ȡ��С
    int len=v1.size();
    cout<<"size="<<len<<endl;
    //push_back��ӵ�ĩβ
    v1.push_back(1);
    for(int i=2;i<=3;i++){
        v1.push_back(i);
    }
    for(int i=0;i<=2;i++){
        cout<<v1[i]<<" ";//����������ʹ���±�
    }
    cout<<endl;
    for(int i=0;i<=2;i++){
        cout<<v1.at(i)<<" ";//Ҳ����ʹ��at��ȡ�±�
    }
    cout<<endl;
    //��������ʹ��
    vector<int>::iterator it;
    for(it=v1.begin();it!=v1.end();it++){
        cout<<*it<<" ";//��ָ��һ�����
    }
    cout<<endl;
    //�����˳�ǰ���ͷ�vector
    v1.clear()//��������ڵ�Ԫ��
    vector<int>().swap(v1);//�ͷ��ڴ�
    //��������
    /*
    v1.empty();
    v1.erase(n);//ɾ����nλ�õ�Ԫ��
    v1.erase(beg,end);//ɾ��[beg,end)����
    v1.front()//��һ������
    v1.insert(pos,s);//���Ĳ���˭
    v1.pop_back();//ɾ�����һ��Ԫ��
    v1.resize();
    */
    return 0;
}