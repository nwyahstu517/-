#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;
int n, r;
int a[22] = {0};
bool b[22] = {0};
int search(int);
int print();
int main()
{
	cin >> n >> r;
	search(1);
}
int search(int k)
{
	int i;
	if(k==r+1)print();
	for (i = a[k - 1] + 1; i <= n; i++) //按由小到大的顺序排列，所以从上一个添加的数+1 开始搜索数字
	{
		if (!b[i])
		{
			a[k] = i;
			b[i] = 1;
			search(k + 1);
			b[i] = 0;
		}
	}
}
int print()

{
	for (int i = 1; i <= r; i++)
		cout << setw(3) << a[i];
	cout << endl;
}
