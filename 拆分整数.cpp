#include<iostream>
using namespace std;
//��N�ֽ�ɲ�ͬ��֮�ͣ��˻����
int main(){
    int input;
    cin>>input;
    int k=2;//��2��ʼ
    int a[10000]={},i=0;
    while (input>=k)
    {
        a[i++]=k;
        input-=k;
        k++;
    }
    //�ж�input�Ƿ��0�������Ƿ�������һλ
    if(input){
        if(input==a[i-1]){
            a[i-1]++;
        }
        for(int j=0;j<input;j++){
            a[i-1-j]++;
        }
    }
    unsigned long long res=1;
    for(int j=0;j<i;j++){
        res*=a[j];
    }
    cout<<res;
    return 0;
}