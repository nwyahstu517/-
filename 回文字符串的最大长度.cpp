#include<iostream>
#include<cstring>
using namespace std;
const int N = 100010,base=131;
typedef unsigned long long ULL;
char str[N];
ULL hl[N];//正序哈希值
ULL hr[N];//逆序哈希值
ULL p[N];
ULL get(ULL h[],int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}
int main(){
    int T=0;
    while(scanf("%s",str+1),strcmp(str+1,"END")){
        int n=strlen(str+1);
        p[0]=1;
        for(int i=n*2;i>0;i-=2){
            str[i]=str[i/2];
            str[i-1]='z'+1;
        }
        n*=2;
        for(int i=1,j=n;i<=n;i++,j--){
            hl[i]=hl[i-1]*base+str[i]-'a'+1;
            hr[i]=hr[i-1]*base+str[j]-'a'+1;
            p[i]=p[i-1]*base;
        }
        int res=0;
        //枚举中点 二分半径,枚举每一个点作为中点
        //以此中点，划半径，半径最小为 0 ，最大看距离哪边端点较小
        for(int i=1;i<=n;i++){
            int r_mix=0;
            int r_max=min(i-1,n-i);// i 左边有 i-1 个，右边有 n-i
            while(r_mix<r_max){
                int mid=(r_mix+r_max)>> 1;
                if(get(hl,i-mid,i-1)!=get(hr,n-(i+mid)+1,n-(i+1)+1))r_max=mid-1;
                else r_mix=mid+1;
            }
            //此时是包含其他符号的长度，现在要求真实长度
            if(str[i-r_mix]<='z') res = max(res ,r_mix+1);
            else res=max(res,r_mix);
        }
        printf("Case %d:%d\n",T++,res);
    }
    return 0;
}