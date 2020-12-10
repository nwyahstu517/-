
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    //d 用来保存最大连续子数组的值
    //m 记录d数组中的最大值
    int n,nums[100],d[100],m;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>nums[i];
        }
        m=d[0] = nums[0];    // 初始化第一个 d[0]
        for(int i=1;i<n;i++) // 遍历从第二数开始
        {
            if(d[i-1]<0)     // i 之前的最大连续子数组小于零，则抛弃它，自己从开始
                d[i] = nums[i];
            else             // i 之前的最大连续子数组不小于零，则加上他们
                d[i] = nums[i]+d[i-1];
            m = max(d[i],m);  // 保存d[i] 中的最大值
        }
        cout<<m<<endl;
    }
    return 0;
}