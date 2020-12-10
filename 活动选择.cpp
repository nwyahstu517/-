#include<bits/stdc++.h>
using namespace std;
const int N=1001;
typedef pair<int,int> pa;
//ifstream cin("1.txt");
//ofstream cout("2.txt"); 
pa p[N];
bool cmp(pa x,pa y){
    return x.second<y.second;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].first>>p[i].second;
    }
    sort(p,p+n,cmp);
    int act[N],k=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=1;
        int last=i;
        for(int j=i+1;j<n;j++){
            if(p[j].first>=p[last].second){
                last=j;
                sum++;
            }
        }
        act[k++]=sum;
    }
    sort(act,act+k);
    cout<<act[k-1];
    return 0;
}
