// 원형 큐의 구현, 배열 이용
#include <iostream>
using namespace std;


const int MAX_QUEUESIZE = 100;

template <typename Element>
class MyQueue
{
public:
	Element myqueue[MAX_QUEUESIZE];
	int front, rear;

	MyQueue()
	{
		front = rear = 0;
	}

	bool is_queue_full()
	{
		return (front == (rear + 1) % MAX_QUEUESIZE);
	}

	bool is_queue_empty()
	{
		return(front == rear);
	}

	void enQueue(Element data)	// 새로운 값을 상단에 추가
	{
		if (is_queue_full())
		{
			cout << "ERROR: QUEUE FULL " << endl;
			return;	// exit
		}
		else
		{
			//myqueue[++rear] = data;	
			//rear++; myqueue[rear] = data;
			rear = (rear + 1) % MAX_QUEUESIZE;
			myqueue[rear] = data;
		}
	}

	Element deQueue()	// 최상단 값을 삭제하면서 동시에 그 값을 반환
	{
		if (is_queue_empty())
		{
			cout << "ERROR: QUEUE EMPTY" << endl;
			exit;
		}
		else
		{
			//return myqueue[++front];
			//front++;
			front = (front + 1) % MAX_QUEUESIZE;
			return myqueue[front];
		}
	}

	void print_queue()
	{
		cout << "## 큐 상태 출력 ##" << endl;
		if (front <= rear)
		{
			for (int i = front + 1; i <= rear; i++)
			{
				cout << myqueue[i] << endl;
			}
		}
		else	// front/rear 순서가 뒤바뀌었으면
		{
			for (int i = front + 1; i <= rear + MAX_QUEUESIZE; i++)
			{
				cout << myqueue[i % MAX_QUEUESIZE] << endl;
			}
		}
		cout << "FRONT: " << front << endl;
		cout << "REAR: " << rear << endl;
		cout << endl;
	}
};

void main()
{
	MyQueue<int> q;

	q.enQueue(10);
	q.enQueue(20);
	q.deQueue();
	q.deQueue();
	q.enQueue(30);
	q.enQueue(40);
	q.enQueue(50);
	q.enQueue(60);
	q.deQueue();
	q.print_queue();
}