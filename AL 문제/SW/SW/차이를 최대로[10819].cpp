#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	팩토리얼(Factorial)

	차이를 최대로
	https://www.acmicpc.net/problem/10819
	수 N개가 주어졌을 때(3<=N<=8)
	N! = 8! = 40320
	모든 경우를 다해봐도 된다
*/
int calculate(vector<int> &a, int n) {
	int sum = 0;
	for (int i = 1; i < n; i++) {
		int t = a[i - 1] - a[i];
		sum += abs(t);
	}
	return sum;
}

int main() {
	int n = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int real = 0;
	sort(a.begin(), a.end());
	do {
		int temp = calculate(a, n);
		real = max(temp, real);

	} while (next_permutation(a.begin(), a.end()));
	cout << real;
	return 0;
}