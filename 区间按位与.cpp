#include<iostream>
using namespace std;
/*
原理：
给出区间m,n
m，n都可以表示成二进制
比如：m   0******
      n   1******
中间一定经过：01111
             10000
这两个数字相与，就是0
这样最后的结果肯定是0
 */
//求二进制最高位是多少位
int msb(int m){
    int count=0;
    while (m>0)
    {
        m=(m>>1);
        count++;
    }
    return count-1;
}
//获取最高位
int get_bit(int m,int i){
    return (m>>i)&1;
}
//将最高位进行相与
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
    //相等的话，我们就要判断相等位是0还是1，并且还要计算与的结果
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