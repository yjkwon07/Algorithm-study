#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	로또
	https://www.acmicpc.net/problem/6603

	배열에 1, 1, 2, 2, 2를 넣고 next_permutation을 수행하면 어떻게 될까?
		- 가능하다.
	입력으로 주어진 k개의 수 중에서 6개의 수를 고르는 문제
	0을 k-6개, 1을 6개를 넣은 다음에 next_permutation를 수행하면 모든 조합을 구할 수 있다.
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