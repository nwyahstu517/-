#include <bits/stdc++.h>
using namespace std;
const int N=1010;//���鳤��
int a[N];//���������
int t[N];//�ϲ�ʱ���õ�������
int n;
void divide(int a[],int,int);//��
void merge(int a[],int,int,int);//��
//�鲢����ĸ��Ӷ���O(n*logn)
void divide(int a[],int left,int right){
    if(left>=right)return;//�����˵�����Ҷ˵㡢�Լ�һ���������
    int mid=(left+right)/2;//�õ��м��±�
    divide(a,left,mid);//��߲��
    divide(a,mid+1,right);//�ұ߲��
    merge(a,left,mid,right);//��ʼ�𽥺ϲ���С�������֣��Ե�����
}
void merge(int a[],int left,int mid,int right){
    int i=left,j=mid+1,k=0;//j���ұ���ʼ��λ��
    while(i<=mid&&j<=right){
        if(a[i]<=a[j]){
            t[k++]=a[i++];
        }else{
            t[k++]=a[j++];
        }
    }//����while֮����һ������װ�꣬��һ�߿��ܻ�ʣ������
    while(i<=mid){
        t[k++]=a[i++];
    }//�����ʣ�µ����ݸ��Ƶ�t����
    while(j<=right){
        t[k++]=a[j++];
    }////���ұ�ʣ�µ����ݸ��Ƶ�t����
    for(int i=left,k=0;i<=right;i++){
        a[i]=t[k++];
    }//��t���������¸��Ƹ�a
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    divide(a,1,n);//��a���顢��˵㡢�Ҷ˵����
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}