#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 10010, M = N * 2;
int ans=N;
int n;
int h[N],e[M],ne[M],idx;
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
int dfs(int u,int father){
    int res=0,sum=0;//sum �洢������һ���ж��ٽڵ�
    for(int i=h[u];~i;i = ne[i]){
        int j=e[i];
        if(j == father)continue;
        int t=dfs(j,u);//���ص�ǰ�ڵ�Ķ��ӷ��ص�����ڵ������
        res=max(res,t);//��ɾ����ǰ�ڵ���������Ҷ��ӽڵ��໥�Աȣ�����������ͨ���ֵ
        sum+=t;//ͳ�������������������������������ͨ�������������ͨ�ڵ�ȴ�С�����������ͨ���ֵ
    }
    //��һ�� ��ÿ����ֻ��ִ��һһ��
    res = max(res,n-sum-1);//��ɾ���ýڵ��
    ans = min(ans,res);//���������ͨ���е���Сֵ
    return sum+1;
}
int main(){
    cin >> n;
    memset(h,-1,sizeof h);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    dfs(1,-1);
    cout<<ans;
    return  0;
}