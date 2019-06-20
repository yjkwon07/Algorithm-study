// https://www.acmicpc.net/problem/10971

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
	���ǿ� ��ȸ2
	https://www.acmicpc.net/problem/10971

	1������ N������ ��ȣ�� �Ű����ִ� ���ð� �ִ�.
	�� ���ÿ��� ������ N���� ��� ���ø� ���� �ٽ� ���� ���÷� ���ƿ����� �Ѵ�.(�� �� ���� ���÷δ� �� �� ����.)
	�� ��, ���� ���� ����� ���ϴ� ����
	2 <=  N <= 10
	N! = 3628800
	��� ��츦 ���غ��� �ð� �ȿ� ���´�.
	O(N*N!)
*/
int a[15][15];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	vector<int> b(n);
	for (int i = 0; i < n; i++)
		b[i] = i;
	int min = 100000000;
	do {
		int sum = 0;
		bool check = true;
		for (int i = 0; i < n - 1; i++) {
			if (a[b[i]][b[i + 1]] == 0) check = false;
			else {
				sum += a[b[i]][b[i + 1]];
			}
		}
		if (check == true && a[b[n - 1]][b[0]] != 0) {
			sum += a[b[n - 1]][b[0]];
			if (sum < min) min = sum;
		}
	} while (next_permutation(b.begin(), b.end()));
	cout << min << '\n';
	return 0;
}