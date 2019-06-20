#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	모든 순열
	https://www.acmicpc.net/problem/10974
*/
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 1; i <= n; i++)
		a[i - 1] = i;
	do {
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << '\n';
	} while (next_permutation(a.begin(), a.end()));
	return 0;
}