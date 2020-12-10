#include<iostream>
using namespace std;
int n,c;//n个元素  子集和c
int sum=0;//记录解的个数
int s=0;//记录当前和
bool used[1000]={0};
int b[1000]={0};//记录后缀和,判断后面元素加起来是否可行
int a[1000]={0};//输入数组

void f(int i){
    // if(sum>0){
    //     return;
    // }
    if(s+b[i]<c){//如果当前s 加上后面所有元素和还小于c,那就不用查找了
        return;
    }
    if(s==c){
        for(int j=1;j<=n;j++){
            if(used[j]&&sum==0){
                cout<<a[j]<<" ";
            }
        }
        cout<<endl;
        sum++;//找到一组解，用于sum>0的结束作用
        //return;
    }
    if(i>n){
        return;
    }
    if(s+a[i]>c){
        f(i+1);//当前a[i]肯定使用不得
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