#include<iostream>
#include<algorithm>
using namespace std;
const int LEN=11;
int son,parent,heap_size=0,n;
int heap[LEN]={0};//�洢�ѵ�����
int a[LEN]={0};
int put(int d){//�ѵķ���Ԫ�ز���
    heap[++heap_size]=d;//�ѵ�ǰԪ�ز�������β��
   /*  son=heap_size;//��ǰ����Ԫ�صı��
    while (son>1)
    {
        parent=son/2;
        if(heap[parent]<=heap[son])break;
        swap(heap[parent],heap[son]);
        son=parent;
    } */
    //push_heap(heap+1,heap+1+heap_size);//��������Ĭ�ϴ����,
    push_heap(heap+1,heap+1+heap_size,greater<int>());
}
int get(){
    /* int son,parent=1,res=heap[1];
    //��heap�������һ��Ԫ�ظ�ֵ��heap[1]�����ҳ��ȼ�1
    heap[1]=heap[heap_size--];
    while (parent*2<=heap_size)//�������,˵��û�ж���
    {
        son=parent*2;//���ӱ��
        //����������С�����Һ���С���Ƚ�һ��
        if(heap[son+1]<heap[son])son++;
        swap(heap[parent],heap[son]);
        parent=son;
    }//����µ�С����
    return res; */
    //pop_heap(heap+1,heap+1+heap_size);
    pop_heap(heap+1,heap+1+heap_size,greater<int>());
    return heap[heap_size--];
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        put(a[i]);
    }
    for(int i=1;i<=heap_size;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<get()<<" ";
    }
    return 0;
}