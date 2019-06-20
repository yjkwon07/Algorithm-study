#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	���丮��(Factorial)

	���̸� �ִ��
	https://www.acmicpc.net/problem/10819
	�� N���� �־����� ��(3<=N<=8)
	N! = 8! = 40320
	��� ��츦 ���غ��� �ȴ�
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