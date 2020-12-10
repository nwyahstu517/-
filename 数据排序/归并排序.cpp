#include <bits/stdc++.h>
using namespace std;
const int N=1010;//数组长度
int a[N];//输入的数组
int t[N];//合并时候用到的数组
int n;
void divide(int a[],int,int);//分
void merge(int a[],int,int,int);//并
//归并排序的复杂度是O(n*logn)
void divide(int a[],int left,int right){
    if(left>=right)return;//如果左端点大于右端点、以及一个数的情况
    int mid=(left+right)/2;//得到中间下标
    divide(a,left,mid);//左边拆分
    divide(a,mid+1,right);//右边拆分
    merge(a,left,mid,right);//开始逐渐合并最小的两部分，自底向上
}
void merge(int a[],int left,int mid,int right){
    int i=left,j=mid+1,k=0;//j是右边起始的位置
    while(i<=mid&&j<=right){
        if(a[i]<=a[j]){
            t[k++]=a[i++];
        }else{
            t[k++]=a[j++];
        }
    }//经过while之后，有一边是先装完，另一边可能还剩下数据
    while(i<=mid){
        t[k++]=a[i++];
    }//将左边剩下的数据复制到t数组
    while(j<=right){
        t[k++]=a[j++];
    }////将右边剩下的数据复制到t数组
    for(int i=left,k=0;i<=right;i++){
        a[i]=t[k++];
    }//将t数组又重新复制给a
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    divide(a,1,n);//将a数组、左端点、右端点代入
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}