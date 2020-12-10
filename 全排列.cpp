#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
void perm(int a[],int s,int e){
    int i;
    if(s==e){
        for(int i=0;i<3;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    for(i=s;i<=e;i++){
        swap(a[s],a[i]); 
        perm(a,s+1,e);
        swap(a[s],a[i]);
    }
}
int main()
{
    int a[3]={1,2,3};
    perm(a,0,2);

    return 0;
}
