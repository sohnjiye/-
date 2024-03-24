#include <iostream>;
using namespace std;

// �迭�� �̿��� ���� ����
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
	// �������
	Node* SP;
public:

	// ������ �Լ�
	Stack()
	{
		SP = NULL;
	}

	// �������
	bool is_stack_empty()
	{
		return(SP == NULL);
	}

	void push(element value)
	{

		// ���ο� ��� ����
		Node* new_node = new Node;
		new_node->data = value;

		// ù ��� ����
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
		cout << "STACK ���� ���" << endl;
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
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')	// �������̸�
		{
			s.push(exp[i]);
		}
		else if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')	// ���� ��ȣ�̸�
		{
			continue;
		}
		else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')	// �ݴ� ��ȣ�̸�
		{
			post[j++] = s.pop();
			//cout << s.pop();
		}
		else // ((exp[i] == 'a' && exp[i] <= 'z') || (exp[i] == 'A' && exp[i] <= 'Z') || (exp[i] == '0' && exp[i] <= '9'))	// �ǿ������̸�
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

element calculate(char post[])	// ����ǥ����� �־����� ��� ���� ��ȯ
{
	Stack s;	// ������ ����

	for (int i = 0; i < strlen(post); i++)	// ����ǥ�� ������ �ѱ��ھ� ó��
	{
		if (post[i] == '+')	// �����ڰ� �����̸�
		{
			// �� ���� �ǿ����ڸ� pop �Ѵ�
			element op2 = s.pop();
			element op1 = s.pop();
			s.push(op1 + op2);
		}
		else if (post[i] == '-')	// �����ڰ� �����̸�
		{
			// �� ���� �ǿ����ڸ� pop �Ѵ�
			element op2 = s.pop();
			element op1 = s.pop();
			s.push(op1 - op2);
		}
		else if (post[i] == '*')	// �����ڰ� �����̸�
		{
			// �� ���� �ǿ����ڸ� pop �Ѵ�
			element op2 = s.pop();
			element op1 = s.pop();
			s.push(op1 * op2);
		}
		else if (post[i] == '/')	// �����ڰ� �������̸�
		{
			// �� ���� �ǿ����ڸ� pop �Ѵ�
			element op2 = s.pop();
			element op1 = s.pop();
			s.push(op1 / op2);
		}	
		else	// �����ڰ� �ƴ� �ǿ������̸�
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

	cout << "������ �Է��ϼ��� : ";
	cin.getline(expression, 100);

	cout << "�Է¹��� ������ : " << expression << endl;

	// �Է¹��� ������ ���� ǥ������� ��ȯ�Ͽ� ���

	convert_postfix(expression, postfix);
	cout << "��ȯ�� ������ : " << postfix << endl;

	cout << "��ȯ�� ������ �� = " << calculate(postfix) << endl;
}