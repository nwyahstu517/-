#include <iostream>
#include<queue>
#include<deque>
using namespace std;
int main()
{
	//���ȼ�����Ĭ����vector����
	priority_queue<int> pq1;
	//��Ҫ������Сֵ���ȶ��У���Ҫ����vector
	//priority_queue<int ,vector<int> , greater<int> >  greater<int>��Сֵ
	//Ҳ������˫�˶��й���
	priority_queue<int,deque<int>,greater<int> > pq2;

	pq1.push(10);
	pq1.push(5);
	pq1.push(-1);
	pq1.push(20);

	//���ȼ�����Ĭ�������ֵ���ȶ��У����Ѿ��ź�����
	while(!pq1.empty()){
		cout<<pq1.top()<<" ";//���ȼ����ж���
		pq1.pop();
	}
	cout<<endl;
	pq2.push(10);
	pq2.push(5);
	pq2.push(-1);
	pq2.push(20);
}

