#include<iostream>
#include<algorithm>
using namespace std;
const int LEN=11;
int son,parent,heap_size=0,n;
int heap[LEN]={0};//存储堆的数组
int a[LEN]={0};
int put(int d){//堆的放入元素操作
    heap[++heap_size]=d;//把当前元素插入数组尾部
   /*  son=heap_size;//当前放入元素的编号
    while (son>1)
    {
        parent=son/2;
        if(heap[parent]<=heap[son])break;
        swap(heap[parent],heap[son]);
        son=parent;
    } */
    //push_heap(heap+1,heap+1+heap_size);//两个参数默认大根堆,
    push_heap(heap+1,heap+1+heap_size,greater<int>());
}
int get(){
    /* int son,parent=1,res=heap[1];
    //把heap数组最后一个元素赋值给heap[1]，并且长度减1
    heap[1]=heap[heap_size--];
    while (parent*2<=heap_size)//如果大于,说明没有儿子
    {
        son=parent*2;//左孩子编号
        //到底是左孩子小还是右孩子小，比较一下
        if(heap[son+1]<heap[son])son++;
        swap(heap[parent],heap[son]);
        parent=son;
    }//完成新的小顶推
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