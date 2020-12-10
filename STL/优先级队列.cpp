#include <iostream>
#include<queue>
#include<deque>
using namespace std;
int main()
{
	//优先级队列默认由vector构造
	priority_queue<int> pq1;
	//想要构造最小值优先队列，就要加上vector
	//priority_queue<int ,vector<int> , greater<int> >  greater<int>最小值
	//也可以由双端队列构造
	priority_queue<int,deque<int>,greater<int> > pq2;

	pq1.push(10);
	pq1.push(5);
	pq1.push(-1);
	pq1.push(20);

	//优先级队列默认是最大值优先队列，即已经排好序了
	while(!pq1.empty()){
		cout<<pq1.top()<<" ";//优先级队列对首
		pq1.pop();
	}
	cout<<endl;
	pq2.push(10);
	pq2.push(5);
	pq2.push(-1);
	pq2.push(20);
}

