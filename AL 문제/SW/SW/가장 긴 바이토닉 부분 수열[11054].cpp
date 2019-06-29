#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	가장 긴 바이토닉 부분 수열
	https://www.acmicpc.net/problem/11054

	가장 긴 증가하는 부분 수열(D)과 가장 긴 감소하는 부분 수열(D2)를 구한 다음

	D[i] + D2[i] -1이 가장 큰 값을 찾으면 된다.
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
