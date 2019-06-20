#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	�κм����� ��
	https://www.acmicpc.net/problem/1182

	��� ������ ���� = 2^N
	��� ������ ���غ��� �ȴ�.
	��ü���� = (1<<N) -1
	�������� �����ؾ� �Ѵ�.
	���տ� ������ ���ԵǾ� �ִ��� Ȯ���ϱ�
	O(N * 2^n)
*/
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i &(1 << j)) {
				sum += a[j];
			}
		}
		if (sum == m) {
			ans += 1;
		}
	}
	cout << ans << '\n';
	return 0;
}