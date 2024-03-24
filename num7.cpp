#include <iostream>
using namespace std;

class Node
{
public:
	int coef;
	int expon;
	Node* link;
};

Node* A, * B;

class Type {
public:
	int size;
	Node* head;
	Node* tail;
};

//연결 함수
Type* create() {
	Type* list = (Type*)malloc(sizeof(Type));

	list->size = 0;
	list->head = list->tail = NULL;
	return list;
}

//리스트 생성 함수
void insert_last(Type* list, int coef, int expon) {
	Node* temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL) return;
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (list->tail == NULL) {
		list->head = list->tail = temp;
	}
	else {
		list->tail->link = temp;
		list->tail = temp;
	}
	list->size++;
}

//다항식 덧셈
void add(Type* list1, Type* list2, Type* list3) {
	Node* A = list1->head;
	Node* B = list2->head;

	int sum;

	while (A && B) {
		if (A->expon == B->expon) {
			sum = A->coef + B->coef;
			if (sum != 0) insert_last(list3, sum, A->expon);
			A = A->link;
			B = B->link;
		}
		else if (A->expon > B->expon) {
			insert_last(list3, A->coef, A->expon);
			A = A->link;
		}
		else {
			insert_last(list3, B->coef, B->expon);
			B = B->link;
		}
	}

	for (; A != NULL; A = A->link)
		insert_last(list3, A->coef, A->expon);
	for (; B != NULL; B = B->link)
		insert_last(list3, B->coef, B->expon);
}

void print(Type* list)
{
	Node* p = list->head;

	cout << "다항식 = ";
	for (; p; p = p->link) {
		if (p->link)
		{
			cout << p->coef << "x" << " ^ " << p->expon << " + " << endl;
		}
		else
		{
			cout << p->coef << "x" << " ^ " << p->expon << endl;
		}
	}
}

void main() {
	Type* A, * B, * C;

	A = create();
	B = create();
	C = create();

	insert_last(A, 3, 12);
	insert_last(A, 2, 8);
	insert_last(A, 1, 0);

	insert_last(B, 8, 12);
	insert_last(B, -3, 10);
	insert_last(B, 10, 6);

	print(A);
	print(B);

	add(A, B, C);
	print(C);
}