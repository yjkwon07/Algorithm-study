#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
	가장 큰 증가 부분 수열 
	https://www.acmicpc.net/problem/11055

	수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 문제 

	D[i] = A[1], ...A[i] 까지 수열이 있을 때, A[i]을 마지막으로 하는 가장 큰 증가하는 부분 수열의 길이
*/
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && b[i] < b[j] + a[i]) {
				b[i] = b[j] + a[i];
			}
		}
	}
	cout << *max_element(b.begin(), b.end()) << '\n';
	return 0;
}