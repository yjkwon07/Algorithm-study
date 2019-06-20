#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	���� ����
	https://www.acmicpc.net/problem/10972

	A[i -1] < A[i] �� �����ϴ� ���� ū i�� ã�´�.
	j >= i �̸鼭 A[j] > A[i-1]�� �����ϴ� ���� ū j�� ã�´�
	A[i-1]�� A[j]�� swap�Ѵ�.
	A[i]���� ������ �����´�.
*/
bool next_permutation(vector<int> &a, int n) {
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) i -= 1;
	if (i <= 0) return false;
	int j = n - 1;
	while (a[j] <= a[i - 1]) j -= 1;
	swap(a[j], a[i - 1]);
	j = n - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i += 1;
		j -= 1;
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (next_permutation(a, n)) {
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
	}
	else cout << "-1" << '\n';

	cout << '\n';
	return 0;
}