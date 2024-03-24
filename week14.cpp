#include <iostream>

using namespace std;

const int NODE_NUM = 8;

int adj[NODE_NUM][NODE_NUM] =
{
	0, 1, 1, 0, 0, 0, 0, 0,
	1, 0, 0, 1, 1, 0, 0, 0,
	1, 0, 0, 0, 0, 1, 1, 0,
	0, 1, 0, 0, 0, 0, 0, 1,
	0, 1, 0, 0, 0, 0, 0, 1,
	0, 0, 1, 0, 0, 0, 0, 1,
	0, 0, 1, 0, 0, 0, 0, 1,
	0, 0, 0, 1, 1, 1, 1, 0
};

string NodeName[NODE_NUM] = { "V1", "V2", "V3", "V4", "V5", "V6", "V7", "V8" };

bool visited[NODE_NUM] = { 0 };



void print_node(int v)
{
	cout << NodeName[v] << "��(��) �湮�߽��ϴ�." << endl;
}

#include <stack>
stack<int> MyStack;

void DFS(int v)	// �ʺ� �켱 ���
{
	MyStack.push(v);
	while (!MyStack.empty())
	{
		v = MyStack.top(); MyStack.pop();
		if (visited[v] != 0)
			return;
		else
			visited[v] = 1;

		print_node(v);

		for (int w = 0; w < NODE_NUM; w++)
		{
			if (adj[v][w] == 0)	// ���Ῡ�� Ȯ��
				continue;
			if (visited[w] != 0)	// �湮���� Ȯ��
				continue;
			MyStack.push(w);
		}
	}
}

#include <queue>
queue<int> MyQueue;

void BFS(int v)	// �ʺ� �켱 ���
{
	MyQueue.push(v);
	while (!MyQueue.empty())
	{
		v = MyQueue.front(); MyQueue.pop();
		if (visited[v] != 0)
			return;
		else
			visited[v] = 1;

		print_node(v);

		for (int w = 0; w < NODE_NUM; w++)
		{
			if (adj[v][w] == 0)	// ���Ῡ�� Ȯ��
				continue;
			if (visited[w] != 0)	// �湮���� Ȯ��
				continue;
			MyQueue.push(w);
		}
	}
}

void main()
{

	//// BFS ��ȸ
	//BFS(0);	// V1����

	//for (int i = 0; i < NODE_NUM; i++)
	//{
	//	visited[i] = 0;
	//}
	DFS(0);
}