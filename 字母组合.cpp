#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;
int n, r;
char a[22];
int  aa[22]={0};
bool b[22] = {0};
string res;
int search(int);
int print();
int main()
{
	cin >> n >> r;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	search(1);
}
int search(int k)
{
	int i;
	if(k==r+1)print();
	for (i = aa[k-1]+1; i <=n; i++) //����С�����˳�����У����Դ���һ����ӵ���+1 ��ʼ��������
	{
		if (!b[i])
		{
			aa[k]=i;
			res+=a[aa[k]];
			b[i] = 1;
			search(k + 1);
			b[i] = 0;
			res.erase(res.size()-1);
		}
	}
}
int print()

{
	cout<<res;
	cout << endl;
}
