#include<iostream>
using namespace std;
/*
ԭ��ͼ��
   ���飺10 12 93 12 75
��������  0  0  0  0  0  ������ʹ����ͱ��1
*/
int main(){
    int n;
    cin>>n;
    int a[2001];
    bool flag[2001];
    for(int i=0;i<n;i++){
        cin>>a[i];
        flag[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]==a[i]&&flag[j]==0){
                flag[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(flag[i]==0) cout<<a[i]<<" ";
    }
}