#include<iostream>
using namespace std;
int n,c;//n��Ԫ��  �Ӽ���c
int sum=0;//��¼��ĸ���
int s=0;//��¼��ǰ��
bool used[1000]={0};
int b[1000]={0};//��¼��׺��,�жϺ���Ԫ�ؼ������Ƿ����
int a[1000]={0};//��������

void f(int i){
    // if(sum>0){
    //     return;
    // }
    if(s+b[i]<c){//�����ǰs ���Ϻ�������Ԫ�غͻ�С��c,�ǾͲ��ò�����
        return;
    }
    if(s==c){
        for(int j=1;j<=n;j++){
            if(used[j]&&sum==0){
                cout<<a[j]<<" ";
            }
        }
        cout<<endl;
        sum++;//�ҵ�һ��⣬����sum>0�Ľ�������
        //return;
    }
    if(i>n){
        return;
    }
    if(s+a[i]>c){
        f(i+1);//��ǰa[i]�϶�ʹ�ò���
    }
    s+=a[i];
    used[i]=true;
    f(i+1);
    s-=a[i];
    used[i]=false;
    f(i+1);
    //return;
}
int main(){
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        used[i]=false;
    }
    b[n]=a[n];
    for(int i=n-1;i>=1;i--){
        b[i]=a[i]+b[i+1];
    }
    f(1);
    if(sum==0){
        cout<<"NO Solution";
    }
    return 0;
}