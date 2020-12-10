#include<bits/stdc++.h>
using namespace std;
/* 
如果判断n范围内有多少个素数？复杂度为O(n*sqrt(n))
    如果n比较大的话，上述方法仍可超时。所以需要加快判断素数的方法。
方法一：埃氏筛
    原理：
        1.因为判断合数比较方面，可以去除合数，剩下的就是素数了。
        2.非0,1的两个数相乘=合数
        3.假设有一个素数q，我们只需要筛掉2*q,3*q……一直到i*q>n时，接着q++，继续筛！
    时间复杂度：
        O(n*log(n))
 */
bool v[1000];//假设0都为素数 1是非素数
int main(){
    v[0]=v[1]=1;//0,1标记为非素数
    for(int i=2;i<=100;i++){//筛选100内的素数
        if(!v[i]){//如果2是素数，那么4 6 8...就不是素数；如果3是素数，那么6 9 12不是素数
            for(int j=2*i;j<=100;j+=i){
                v[j]=1;
            }
        }
    }
    for(int i=2;i<=100;i++){
        if(!v[i]){
            cout<<i<<" ";
        }
    }
    return 0;
}