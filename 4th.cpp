#include <iostream>
using namespace std;

void main()
{
	int num;

	cout << "학생 수는 ";
	cin >> num;

	int* score = new int[num];

	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		cout << i << "번째 학생의 성적은 ";
		//cin >> score[i];
		cin >> score[i];
		sum += score[i];
	}

	cout << "평균은 " << (double) sum / num << endl;
}