#include<iostream>
using namespace std;
int n,m;//n����  m�Թ�ϵ
int q;//q������
struct UFSTree{
    int data;//����
    int height;//�������������ĸ߶�
    int parent;//�������������ĸ������������ȣ�
}t[100];
//��ʼ��ÿ��Ԫ�س�Ϊһ�������ļ���
void Make_Set(){
    for(int i=1;i<=n;i++){
        t[i].data=i;//t[i]����һ������
        t[i].height=0;//һ��Ԫ�ظ߶�Ϊ0
        t[i].parent=i;//һ��Ԫ�صļ��ϵĴ�����������
    }
}
//����x ���ڼ��ϵĴ�����˭
int Find_Set(int x){
    if(x!=t[x].parent){//x���ڵļ��ϴ�����x ��˵�����Ͽ϶�������Ԫ����Ϊ����
        return Find_Set(t[x].parent);//�ݹ����
    }else{
        return x;//���ؼ��ϵĴ���
    }
} 
//�ϲ�x��y���ڵ���������
void Union_SET(int x,int y){
    //����x���ڼ��ϵĴ���
    x=Find_Set(x);
    //����x���ڼ��ϵĴ���
    y=Find_Set(y);
    //�жϸ߶ȴ�С
    if(t[x].parent==t[y].parent)return;
    if(t[x].height>t[y].height){
        t[y].parent=x;//ֻ��Ҫ���߶Ƚ�С�����ȸ�Ϊ�߶ȴ���Ǹ�����
    }else{
        t[x].parent=y;
        if(t[x].height==t[y].height){
            t[y].height++;
        }
    }
}
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    Make_Set();
    while(m--){
        int x,y;
        cin>>x>>y;
        Union_SET(x,y);
    }
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(Find_Set(x)==Find_Set(y)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
