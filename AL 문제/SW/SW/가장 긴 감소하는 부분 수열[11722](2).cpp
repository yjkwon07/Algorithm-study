#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	가장 긴 감소하는 부분 수열
	https://www.acmicpc.net/problem/11722
	수열 A가 주어졌을 때, 그 수열의 감소하는 부분 수열 중에서 가장 긴 것을 구하는 문제

	두 가지 방법이 있다.
	입력으로 주어진 수열 A를 뒤집어서 가장 긴 증가하는 부분 수열을 구하는 방법
	가장 긴 증가하는 부분 수열과 비슷하게 구하는 방법 (뒤에서부터 구해야 한다.)
	D[i] = A[i]에서 시작하는 가장 긴 감소하는 부분 수열의 길이
	D[i] = max(D[j]) + 1 ( i < j && A[i] > A[j])

*/
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> b(n);
	for (int i = n - 1; i >= 0; i--) {
		b[i] = 1;
		for (int j = n - 1; j > i; j--) {
			if (a[i] > a[j] && b[i] < b[j] + 1) { 
				b[i] = b[j] + 1;
			}
		}
	}
	cout << *max_element(b.begin(), b.end()) << '\n';
	cin >> n;
	return 0;
}