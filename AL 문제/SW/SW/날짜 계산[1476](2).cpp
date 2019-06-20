#include<iostream>
using namespace std;
/*
	��¥ ���
	https://www.acmicpc.net/problem/1476

	������ ����� ��
	15 * 28  * 19 = 7980
	��� ��츦 �� �غ��� �ȴ�
	year mod 15 == E
	year mod 28 == S
	year mod 19 == M
	�̷������� year�� 0���� ������Ű�鼭 ���� ���� �˻��� 
	�����ϴ� ����� �����ϴ�.
*/
int main() {
	int E, S, M;
	cin >> E >> S >> M;
	
	E--;
	S--;
	M--;

	int t = 0;
	for (; ; t++) {
		if ((t % 15  == E) && (t % 28 == S) && (t % 19 == M)) break;
	}
	cout << t + 1 << '\n';
	return 0;
}