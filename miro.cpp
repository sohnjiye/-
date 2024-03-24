//#include <iostream>
//#include <stack>
//using namespace std;
//
//// 객체 + 배열을 이용한 스택 구현
//const int MAZE_SIZE = 500;
//
//class Stack
//{
//public:
//	int MyStack[MAZE_SIZE];
//	int Top;
//
//	Stack()
//	{
//		Top = -1;
//	}
//
//	bool is_stack_full()
//	{
//		/*if (Top == MAX_STACK_SIZE - 1)
//			return true;
//		else
//			return false;*/
//		return (Top == MAZE_SIZE - 1);
//	}
//
//	bool is_stack_empty()
//	{
//		/*if (Top == -1)
//			return true;
//		else
//			return false;*/
//		return (Top == -1);
//	}
//
//	int pop()
//	{
//		if (is_stack_empty())
//		{
//			cout << "ERROR : Stack Underflow" << endl;
//			exit(1);
//		}
//		else
//		{
//			/*int x = MyStack[Top];
//			Top--;
//			return x;*/
//			return MyStack[Top--];
//		}
//	}
//
//	int peek()
//	{
//		if (is_stack_empty())
//		{
//			cout << "ERROR : empty Stack" << endl;
//		}
//		else
//			return (MyStack[Top]);
//	}
//
//	void push(int value)
//	{
//		if (is_stack_full())
//		{
//			cout << "ERROR : Stack Overflow" << endl;
//			exit(1);
//		}
//		else
//		{
//			/*Top++;
//			MyStack[Top] = value;*/
//			MyStack[++Top] = value;
//		}
//
//	}
//
//	void print_stack()
//	{
//		cout << "STACK 상태 출력" << endl;
//		for (int i = Top; i >= 0; i--)
//			cout << MyStack[i] << endl;
//	}
//
//	typedef struct
//	{
//		int r;
//		int c;
//	}element;
//
//	element here = { 1,0 }, entry = { 1,0 };
//
//	char maze[MAZE_SIZE][MAZE_SIZE] =
//	{
//		{ '1', '1', '1', '1', '1', '1' },
//		{ 'e', '0', '1', '0', '0', '1' },
//		{ '1', '0', '0', '0', '1', '1' },
//		{ '1', '0', '1', '0', '1', '1' },
//		{ '1', '0', '1', '0', '0', 'x' },
//		{ '1', '1', '1', '1', '1', '1' }
//	};
//
//	void push_loc(int r, int c)
//	{
//		if (r < 0 || c < 0)
//			return;
//		if (maze[r][c] != '1' && maze[r][c] != '.')
//		{
//			element tmp;
//			tmp.r = r;
//			tmp.c = c;
//			push(r);
//			push(c);
//		}
//	}
//};
//
//
//
//void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
//{
//	cout << endl;
//	for (int r = 0; r < MAZE_SIZE; r++)
//	{
//		for (int c = 0; c < MAZE_SIZE; c++)
//		{
//			cout << maze[r][c];
//		}
//		cout << endl;
//	}
//}
//
//void main()
//{
//	int r, c;
//	Stack s;
//
//	s.here = s.entry;
//	while (s.maze[s.here.r][s.here.c] != 'x')
//	{
//		r = s.here.r;
//		c = s.here.c;
//		s.maze[r][c] = '.';
//		maze_print(s.maze);
//		
//		s.push_loc(r - 1, c);
//		s.push_loc(r + 1, c);
//		s.push_loc(r, c - 1);
//		s.push_loc(r, c + 1);
//
//		if (s.is_stack_empty())
//		{
//			cout << "실패" << endl;
//			return;
//		}
//		else
//		{
//			s.here.r = s.pop();
//			s.here.c = s.pop();
//		}
//	}
//	cout << "성공" << endl;
//	return;
//}


//#include <iostream>
//#include<stack>
//#include<stdio.h>
//using namespace std;
//
//#define element int
//const int MAX_SIZE = 1000;
//
//element Stack[MAX_SIZE];
//int top = -1;
//
//bool is_stack_empty()
//{
//	return(top == -1);
//}
//
//bool is_stack_full()
//{
//	return(top == MAX_SIZE - 1);
//}
//
//void push(element data)
//{
//	if (is_stack_full())
//	{
//		cout << "ERROR: Stack Full" << endl;
//		return;
//	}
//	else
//	{
//		Stack[++top] = data;
//	}
//}
//
//element pop()
//{
//	if (is_stack_empty())
//	{
//		cout << "ERROR: Stack Empty" << endl;
//		return -1;
//	}
//	else
//	{
//		return Stack[top--];
//	}
//}
//
//element peek()
//{
//	if (is_stack_empty())
//	{
//		cout << "ERROR: Stack Empty" << endl;
//		return -1;
//	}
//	else
//	{
//		return Stack[top];
//	}
//}
//
//void print_stack()
//{
//	cout << "STACK STATUS" << endl;
//
//	if (is_stack_empty())
//		return;
//	else
//	{
//		for (int i = top; i >= 0; i--)
//		{
//			cout << Stack[i] << endl;
//		}
//	}
//}
//
//typedef struct
//{
//	short r;
//	short c;
//}what;
//
//what here = { 1,0 }, entry = { 1,0 };
//
//char maze[MAX_SIZE][MAX_SIZE] =
//{
//	{ '1', '1', '1', '1', '1', '1' },
//	{ 'e', '0', '1', '0', '0', '1' },
//	{ '1', '0', '0', '0', '1', '1' },
//	{ '1', '0', '1', '0', '1', '1' },
//	{ '1', '0', '1', '0', '0', 'x' },
//	{ '1', '1', '1', '1', '1', '1' }
//};
//
//void push_loc(int r, int c)
//{
//	if (r < 0 || c < 0)
//		return;
//	if (maze[r][c] != '1' && maze[r][c] != '.')
//	{
//		what tmp;
//		tmp.r = r;
//		tmp.c = c;
//		what push(tmp);
//	}
//};
//
//void maze_print(char maze[MAX_SIZE][MAX_SIZE])
//{
//	cout << endl;
//	for (int r = 0; r < MAX_SIZE; r++)
//	{
//		for (int c = 0; c < MAX_SIZE; c++)
//		{
//			cout << maze[r][c];
//		}
//		cout << endl;
//	}
//}
//
//void main()
//{
//	int r, c;
//
//	here = entry;
//	while (maze[here.r][here.c] != 'x')
//	{
//		r = here.r;
//		c = here.c;
//		maze[r][c] = '.';
//		maze_print(maze);
//		
//		push_loc(r - 1, c);
//		push_loc(r + 1, c);
//		push_loc(r, c - 1);
//		push_loc(r, c + 1);
//
//		if (is_stack_empty())
//		{
//			cout << "실패" << endl;
//			return;
//		}
//		else
//		{
//			here.r = pop();
//			here.c = pop();
//		}
//	}
//	cout << "성공" << endl;
//	return;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

// 좌표를 저장하기 위한 구조체
typedef struct {
    short r;
    short c;
} element;

typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;

void init(StackType* s) {
    s->top = -1;
}

int is_empty(StackType* s) {
    return s->top == -1;
}

int is_full(StackType* s) {
    return s->top == MAX_STACK_SIZE - 1;
}

void push(StackType* s, element item) {
    if (is_full(s)) {
        exit(1);
    }
    s->stack[++(s->top)] = item;
}

element pop(StackType* s) {
    if (is_empty(s)) {
        exit(1);
    }
    return s->stack[(s->top)--];
}

element peek(StackType* s) {
    if (is_empty(s)) {
        exit(1);
    }
    return s->stack[s->top];
}

element here = { 1,0 };
element entry = { 1,0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'1','1','1','1','1','1'},
    {'e','0','1','0','0','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','1','1'},
    {'1','0','1','0','0','x'},
    {'1','1','1','1','1','1'}
};

void push_loc(StackType* s, int r, int c) {
    if (r < 0 || c < 0 || r > MAZE_SIZE || c > MAZE_SIZE) 
        return;
    if (maze[r][c] != '1' && maze[r][c] != '.') {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}

void print() {
    int i, j;
    for (i = 0; i < MAZE_SIZE; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int r, c;
    StackType s;

    init(&s);
    here = entry;
    while (maze[here.r][here.c] != 'x') {
        r = here.r;
        c = here.c;
        maze[r][c] = '.';

        print();
        printf("------------\n");

        push_loc(&s, r - 1, c); // north
        push_loc(&s, r + 1, c); // south
        push_loc(&s, r, c - 1); // west
        push_loc(&s, r, c + 1); // east

        if (is_empty(&s)) {
            printf("실패\n");
            exit(1);
        }
        else {
            here = pop(&s);
        }
    }
    printf("성공\n");
    return 0;
}