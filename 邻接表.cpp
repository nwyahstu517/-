#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 1000
// �����ߵ���Ϣ
struct e{
    int to;
    int next;
    int val;
};
int head[MAXN],num=1;
e ee[MAXN];
void add(int from,int to){
    ee[num].next=head[from];
    ee[num].to=to;
    head[from]=num++;
}
int main(){
    memset(head,0,sizeof head);
    //��ͼ 4������  5����  ��������ͼ��Ҫ����˫�����װɡ�
    for(int i=1;i<=5;i++){
        int from,to,val;//����val�Ͳ������ˣ���Ϊ�� 0
        cin>>from>>to;
        add(from,to);
        add(to,from);
    }
    for(int i=1;i<=4;i++){//����ÿ�����
        for(int j=head[i];j!=0;){
            if(ee[j].to!=0){
                cout<<i<<" "<<ee[j].to<<endl;
            }
            j=head[i]=ee[j].next;
        }
        cout<<endl;
    }
    return 0;
}