#include<iostream>
using namespace std;
int n,m;//n个人  m对关系
int q;//q个问题
struct UFSTree{
    int data;//数据
    int height;//该数据所在树的高度
    int parent;//该数据所在树的根（根就是祖先）
}t[100];
//初始化每个元素称为一个独立的集合
void Make_Set(){
    for(int i=1;i<=n;i++){
        t[i].data=i;//t[i]代表一个集合
        t[i].height=0;//一个元素高度为0
        t[i].parent=i;//一个元素的集合的代表是它本身
    }
}
//查找x 所在集合的代表是谁
int Find_Set(int x){
    if(x!=t[x].parent){//x所在的集合代表不是x ，说明集合肯定有其他元素作为代表
        return Find_Set(t[x].parent);//递归查找
    }else{
        return x;//返回集合的代表
    }
} 
//合并x和y所在的两个集合
void Union_SET(int x,int y){
    //查找x所在集合的代表
    x=Find_Set(x);
    //查找x所在集合的代表
    y=Find_Set(y);
    //判断高度大小
    if(t[x].parent==t[y].parent)return;
    if(t[x].height>t[y].height){
        t[y].parent=x;//只需要将高度较小的祖先改为高度大的那个祖先
    }else{
        t[x].parent=y;
        if(t[x].height==t[y].height){
            t[y].height++;
        }
    }
}
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    Make_Set();
    while(m--){
        int x,y;
        cin>>x>>y;
        Union_SET(x,y);
    }
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(Find_Set(x)==Find_Set(y)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
