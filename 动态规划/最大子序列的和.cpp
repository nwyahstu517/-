
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    //d ����������������������ֵ
    //m ��¼d�����е����ֵ
    int n,nums[100],d[100],m;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>nums[i];
        }
        m=d[0] = nums[0];    // ��ʼ����һ�� d[0]
        for(int i=1;i<n;i++) // �����ӵڶ�����ʼ
        {
            if(d[i-1]<0)     // i ֮ǰ���������������С���㣬�����������Լ��ӿ�ʼ
                d[i] = nums[i];
            else             // i ֮ǰ��������������鲻С���㣬���������
                d[i] = nums[i]+d[i-1];
            m = max(d[i],m);  // ����d[i] �е����ֵ
        }
        cout<<m<<endl;
    }
    return 0;
}