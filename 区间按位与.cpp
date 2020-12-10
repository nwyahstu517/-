#include<iostream>
using namespace std;
/*
ԭ��
��������m,n
m��n�����Ա�ʾ�ɶ�����
���磺m   0******
      n   1******
�м�һ��������01111
             10000
�������������룬����0
�������Ľ���϶���0
 */
//����������λ�Ƕ���λ
int msb(int m){
    int count=0;
    while (m>0)
    {
        m=(m>>1);
        count++;
    }
    return count-1;
}
//��ȡ���λ
int get_bit(int m,int i){
    return (m>>i)&1;
}
//�����λ��������
int set_bit(int result,int i){
    return (result | (1<<i));
}
int rangBitAnd(int m,int n){
    int msb1=msb(m);
    int msb2=msb(n);
    if(msb1!=msb2){
        return 0;
    }
    int msb=msb1;
    int result=0;
    //��ȵĻ������Ǿ�Ҫ�ж����λ��0����1�����һ�Ҫ������Ľ��
    while(msb>=0){
        int x=get_bit(m,msb);
        int y=get_bit(n,msb);
        if(x!=y){
            return result;
        }else if(x==1){
            result=set_bit(result,msb);
        }
        msb--;
    }
    return result;
}
int main(){
    printf("%x",rangBitAnd(1,1));
    return 0;
}