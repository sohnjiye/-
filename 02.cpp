#include <iostream>
using namespace std;

// ���Ḯ��Ʈ�� �̿��� ť�� �⺻ �Լ� ����, ��� ���� �׽�Ʈ
#define element int

class Node
{
public:
	element data;
	Node* link;
};

Node* front = NULL;
Node* rear = NULL;

bool is_queue_empty()
{
	return(front == NULL); // return (rear == NULL);
}

void enQueue(element data)
{
	// ���ο� ��带 ù ���� �߰�
	Node* new_node = new Node;
	new_node->data = data;
	new_node->link = NULL;

	if (is_queue_empty())
	{
		front = rear = new_node;
	}
	else
	{
		rear->link = new_node;
		rear = new_node;
	}
}

element deQueue()
{
	if (is_queue_empty())
	{
		cout << "ERROR: Queue Empty" << endl;
		return-1; // exit();
	}
	else
	{
		element item = front->data;
		front = front->link;
		if (front == NULL)
			rear = NULL;
		return item;
	}
}

element peek()
{
	if (is_queue_empty())
	{
		cout << "ERROR: Queue Empty" << endl;
		return -1; // exit();
	}
	else
	{
		return rear->data;
	}
}

void print_queue()
{
	cout << "QUEUE STATUS" << endl;
	if (is_queue_empty())
		return;
	else
	{
		for (Node* ptr = front; ptr != NULL; ptr = ptr->link)
			cout << ptr->data << " ";
	}
	cout << endl;
}

void main()
{
	enQueue(10);
	enQueue(20);
	enQueue(30);
	deQueue();
	print_queue();

	enQueue(40);
	enQueue(50);
	deQueue();
	enQueue(60);

	print_queue();

}