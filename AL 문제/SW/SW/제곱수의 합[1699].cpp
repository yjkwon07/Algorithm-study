#include <iostream>
using namespace std;
/*
	제곱수의 합
	https://www.acmicpc.net/problem/1699
	주어진 자연수 N을 제곱수들의 합으로 표현할 때에 그 항의 최소개수를 구하는 문제
	11 = 3^2 + 1^2 + 1^2

	D[i] = i를 제곱수의 합으로 나타냈을 때, 필요한 항의 최소 개수
	D[i] = min(D[i-j^2] +1) ( 1<= i <= j ^2)
*/
long long a[100001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		a[i] = i;
		for (int j = 1; j * j <= i; j++) {
			if (a[i] > a[i - j * j] + 1)
				a[i] = a[i - j * j] + 1;
		}
	}

	cout << a[n];
	return 0;
}