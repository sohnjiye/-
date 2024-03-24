#include <iostream> 
using namespace std;

int cnt = 0; // �̵� Ƚ���� �̿�.

void Hanoi(int n, char from, char temp, char to)
// n : ���ݰ���, from : ���� ��ġ, temp : �ӽ� ���, to :������
{

	if (n == 1)
		cout << from << " " << to << endl;
	else
	{
		Hanoi(n - 1, from, to, temp);
		cout << from << " " << to << endl;
		Hanoi(n - 1, temp, from, to);
	}

}


void main()
{
	int n; //������ ��

	cout << "������ ������ �Է��ϼ��� : ";
	cin >> n;
	cnt = pow(2, n) - 1;

	Hanoi(n, 'A', 'B', 'C');    // n���� ������ 'A'���� 'C'�� �̵�

	cout << "��ü ���� �̵� ��(���ݼ� : " << n << ") = " << cnt << endl;
}