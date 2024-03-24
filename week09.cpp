//#include <iostream>
//using namespace std;
//
//typedef int element;
//element STACK[100];
//int top = -1;
//
//void push(element item)
//{
//	STACK[++top] = item;
//}
//
//element pop()
//{
//	if (top == -1)
//	{
//		cout << "\n\nSTACK is empty!\n\n";
//		return 0;
//	}
//	else
//		return (STACK[top--]);
//}
//
//element peek()
//{
//	if (top == -1)
//	{
//		cout << "\n\nSTACK is empty!\n\n";
//		return 0;
//	}
//	else
//		return(STACK[top]);
//}
//
//void printSTACK()
//{
//	int	sp = top;
//	cout << "\n\nSTACK [ ";
//	while (sp >= 0)
//	{
//		cout << STACK[sp];
//		sp--;
//	}
//	cout << "]";
//}
//
//element evalPostfix(char* exp)
//{
//	int opr1, opr2, value;
//	int length = strlen(exp);
//	char symbol;
//
//	for (int i = 0; i < length; i++)
//	{
//		symbol = exp[i];
//		if (symbol != '+ ' && symbol != '-' && symbol != '*' && symbol != '/')
//		{
//			value = symbol - '0';
//			push(value);
//		}
//		else
//		{
//			opr2 = pop();
//			opr1 = pop();
//			switch (symbol)
//			{
//			case '+': push(opr1 + opr2);
//				break;
//			case'-': push(opr1 - opr2);
//				break;
//			case'*': push(opr1 * opr2);
//				break;
//			case'/': push(opr1 / opr2);
//				break;
//			}
//		}
//	}
//	return pop();
//}
//
//void main()
//{
//	int result;
//	char *express = "35*62/-";
//
//	cout << "후위표기식: " << express;
//
//	result = evalPostfix(express);
//	cout << "=" << result << endl << endl;
//}