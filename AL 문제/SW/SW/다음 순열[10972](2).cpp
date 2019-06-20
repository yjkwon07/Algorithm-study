#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	다음 순열
	https://www.acmicpc.net/problem/10972

	A[i -1] < A[i] 를 만족하는 가장 큰 i를 찾는다.
	j >= i 이면서 A[j] > A[i-1]를 만족하는 가장 큰 j를 찾는다
	A[i-1]과 A[j]를 swap한다.
	A[i]부터 순열을 뒤집는다.
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