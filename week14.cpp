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
	cout << NodeName[v] << "을(를) 방문했습니다." << endl;
}

#include <stack>
stack<int> MyStack;

void DFS(int v)	// 너비 우선 방식
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
			if (adj[v][w] == 0)	// 연결여부 확인
				continue;
			if (visited[w] != 0)	// 방문여부 확인
				continue;
			MyStack.push(w);
		}
	}
}

#include <queue>
queue<int> MyQueue;

void BFS(int v)	// 너비 우선 방식
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
			if (adj[v][w] == 0)	// 연결여부 확인
				continue;
			if (visited[w] != 0)	// 방문여부 확인
				continue;
			MyQueue.push(w);
		}
	}
}

void main()
{

	//// BFS 순회
	//BFS(0);	// V1부터

	//for (int i = 0; i < NODE_NUM; i++)
	//{
	//	visited[i] = 0;
	//}
	DFS(0);
}