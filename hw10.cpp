#include <iostream>;
using namespace std;

// 배열을 이용한 스택 구현
const int MAX_STACK_SIZE = 100;
typedef double element;

class Node
{
public:
	element data;
	Node* link;
};
class Stack
{
	// 멤버변수
	Node* SP;
public:

	// 생성자 함수
	Stack()
	{
		SP = NULL;
	}

	// 멤버변수
	bool is_stack_empty()
	{
		return(SP == NULL);
	}

	void push(element value)
	{

		// 새로운 노드 생성
		Node* new_node = new Node;
		new_node->data = value;

		// 첫 노드 삽입
		new_node->link = SP;
		SP = new_node;
	}

	element pop()
	{
		if (is_stack_empty())
		{
			cout << "ERROR : Stack Underflow" << endl;
			exit(1);
		}

		element x = SP->data;
		SP = SP->link;
		return x;
	}

	element peek()
	{
		if (is_stack_empty())
		{
			cout << "ERROR : empty Stack" << endl;
		}
		else return(SP->data);
	}
	
	void print_stack()
	{
		int top = -1;
		cout << "STACK 상태 출력" << endl;
		for (int i = top; i >= 0; i--)
			cout << MAX_STACK_SIZE << endl;
	}

};

void convert_postfix(char exp[], char post[])
{
	Stack s;
	int j = 0;

	for (int i = 0; i < strlen(exp); i++)
	{
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')	// 연산자이면
		{
			s.push(exp[i]);
		}
		else if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')	// 여는 괄호이면
		{
			continue;
		}
		else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')	// 닫는 괄호이면
		{
			post[j++] = s.pop();
			//cout << s.pop();
		}
		else // ((exp[i] == 'a' && exp[i] <= 'z') || (exp[i] == 'A' && exp[i] <= 'Z') || (exp[i] == '0' && exp[i] <= '9'))	// 피연산자이면
		{
			post[j++] = exp[i];
		}

	}
	while (!s.is_stack_empty())
	{
		post[j++] = s.pop();
	}

	post[j] = NULL;
}

element calculate(char post[])	// 후위표기식이 주어지면 계산 값을 변환
{
	Stack s;	// 정수형 스택

	for (int i = 0; i < strlen(post); i++)	// 후위표기 수식의 한글자씩 처리
	{
		if (post[i] == '+')	// 연산자가 덧셈이면
		{
			// 두 개의 피연산자를 pop 한다
			element op2 = s.pop();
			element op1 = s.pop();
			s.push(op1 + op2);
		}
		else if (post[i] == '-')	// 연산자가 뺄셈이면
		{
			// 두 개의 피연산자를 pop 한다
			element op2 = s.pop();
			element op1 = s.pop();
			s.push(op1 - op2);
		}
		else if (post[i] == '*')	// 연산자가 곱셈이면
		{
			// 두 개의 피연산자를 pop 한다
			element op2 = s.pop();
			element op1 = s.pop();
			s.push(op1 * op2);
		}
		else if (post[i] == '/')	// 연산자가 나눗셈이면
		{
			// 두 개의 피연산자를 pop 한다
			element op2 = s.pop();
			element op1 = s.pop();
			s.push(op1 / op2);
		}	
		else	// 연산자가 아닌 피연사자이면
		{
			s.push(post[i] - '0');
		}
	}
	return (s.pop());
}

void main()
{
	char expression[100];
	char postfix[100];

	cout << "수식을 입력하세요 : ";
	cin.getline(expression, 100);

	cout << "입력받은 수식은 : " << expression << endl;

	// 입력받은 수식을 후위 표기식으로 변환하여 출력

	convert_postfix(expression, postfix);
	cout << "변환된 수식은 : " << postfix << endl;

	cout << "변환된 수식의 값 = " << calculate(postfix) << endl;
}