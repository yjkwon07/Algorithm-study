#include<iostream>
using namespace std;
/*
	 ��¥ ��� 
	 https://www.acmicpc.net/problem/1476
	1<= n <= 15
	1<= s <= 28
	1<= m <= 19
	����� �� -> 7,980
	��� �� ��� �ؼ� �´� �� ����

	����������
	1 1 1 -> 1
	2 2 2 -> 2
	3 3 3 -> 3

	1 16 16 -> 16
	2 17 17 -> 17
	3 18 18 -> 18
	4 19 19 -> 19

	5 20 1 -> 20
*/
int main() {
	int E, S, M;
	cin >> E >> S >> M;
	int e = 1, s = 1, m = 1;
	for (int i = 1;; i++) {
		if (e == E && s == S && m == M) {
			cout << i << '\n';
			return 0;
		}
		e += 1;
		s += 1;
		m += 1;
		if (e == 16) {
			e = 1;
		}
		if (s == 29) {
			s = 1;
		}
		if (m == 20) {
			m = 1;
		}
	}
	return 0;
}