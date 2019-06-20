#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	�ζ�
	https://www.acmicpc.net/problem/6603

	�迭�� 1, 1, 2, 2, 2�� �ְ� next_permutation�� �����ϸ� ��� �ɱ�?
		- �����ϴ�.
	�Է����� �־��� k���� �� �߿��� 6���� ���� ���� ����
	0�� k-6��, 1�� 6���� ���� ������ next_permutation�� �����ϸ� ��� ������ ���� �� �ִ�.
*/
int main() {
	int n = 16;
	while (n != 0)
	{
		cin >> n;
		if (n == 0)
			break;
		vector<int> a(n);
		vector<int> b(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int j = 0; j < 6; j++)
			b[j] = 1;
		for (int k = 6; k < n; k++)
			b[k] = 0;

		do {
			for (int h = 0; h < n; h++) {
				if (b[h] == 1)
					cout << a[h] << ' ';
			}
			cout << '\n';
		} while (prev_permutation(b.begin(), b.end()));
		cout << '\n';
	}
}