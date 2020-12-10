#include<iostream>
#include<string>
using namespace std;
const int N = 1000;
string s1;
string s2;
int dp[N][N];
int LCS(const string s1,const string s2){
    int len1=s1.size();
    int len2=s2.size();
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[len1][len2];
}
int main(int argc, char const *argv[])
{
    cin>>s1>>s2;
    cout<<LCS(s1,s2);
    return 0;
}
