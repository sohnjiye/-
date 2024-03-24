//#include <iostream>
//using namespace std;
//
//class Node
//{
//public:
//	int data;
//	Node* link;
//};
//
//Node* Head = NULL;
//
///*
//// void insert_node_at_front
//// 제일 앞에 추가
//
//void insert_node(int value)
//{
//	Node* new_node;
//
//	new_node = new Node;
//	new_node->data = value;
//	new_node->link = NULL;
//
//	new_node->link = Head;
//	Head = new_node;
//}
//*/
//
//// 제일 뒤에 추가
//void insert_node(int value)
//{
//	Node* new_node;
//
//	new_node = new Node;
//	new_node->data = value;
//	new_node->link = NULL;
//
//	if (Head == NULL)
//	{
//		Head = new_node;
//	}
//	else
//	{
//		// 마지막 노드를 찾는다
//		Node* list = Head;
//
//		while (list->link != NULL)
//			list = list->link;
//		// 이 경우, list는 마지막 노드를 가리킴
//		list->link = new_node;
//	}
//}
//// 값을 가진 노드를 삭제
//void delete_node(int value)
//{
//	if (Head == NULL)
//	{
//		cout << "빈리스트입니다" << endl;
//		return;
//	}
//	else if (Head->data == value)
//	{
//		Head = Head->link;
//		return;
//	}
//	else
//	{
//		Node* list = Head;
//		while (list->link != NULL)
//		{
//			if (list->link->data == value)
//			{
//				list->link = list->link->link;
//				return;
//			}
//			list = list->link;
//		}
//
//	}
//}
//
//
//void print_list()
//{
//	for (Node* list = Head; list != NULL; list = list->link)
//		if (list->link != NULL) cout << list->data << "->";
//		else cout << list->data << endl;
//}
//
//void main()
//{
//	// 8개의 노드를 삽입하여 연결리스트 구성
//
//	delete_node(10);
//
//	insert_node(10);
//	insert_node(20);
//	insert_node(30);
//	insert_node(40);
//	insert_node(50);
//	insert_node(60);
//	insert_node(70);
//	insert_node(80);
//
//	print_list();
//
//
//
//	delete_node(40); print_list();
//	delete_node(70); print_list();
//	delete_node(45); print_list();
//	delete_node(80); print_list();
//	delete_node(10); print_list();
//}