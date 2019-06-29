#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	���� �� ������� �κ� ����
	https://www.acmicpc.net/problem/11054

	���� �� �����ϴ� �κ� ����(D)�� ���� �� �����ϴ� �κ� ����(D2)�� ���� ����

	D[i] + D2[i] -1�� ���� ū ���� ã���� �ȴ�.
*/
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> d(n);
	vector<int> s(n);
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		d[i] = 1;

		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
			}
		}

	}
	for (int i = n - 1; i >= 0; i--) {
		s[i] = 1;
		for (int j = n - 1; j > i; j--) {
			if (a[i] > a[j] && s[i] < s[j] + 1) {
				s[i] = s[j] + 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
		ans[i] = d[i] + s[i] - 1;
	cout << *max_element(ans.begin(), ans.end()) << '\n';
	cin >> n;
	return 0;
}
