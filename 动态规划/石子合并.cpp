#include<bits/stdc++.h>
using namespace std;
const int maxn=220;
int n,a[maxn],sum[maxn],f[maxn][maxn];
int main(int argc, char const *argv[])
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    memset(f,0x7f,sizeof f);
    for(int len=1;len<=n;len++){//len������ i j�ĳ���
        for(int i=1;i+len-1<=n;i++){//i����˵� i+len-1�Ҷ˵�
            int j=i+len-1;
            if(len==1){
                f[i][j]=0;
            }else{
                for(int k=i;k<j;k++){
                    f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
                }
            }
        }
    }
    cout<<f[1][n];
    return 0;
}
