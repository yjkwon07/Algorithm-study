#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	외판원 순회2
	https://www.acmicpc.net/problem/10971

	1번부터 N번까지 번호가 매겨져있는 도시가 있다.
	한 도시에서 시작해 N개의 모든 도시를 거쳐 다시 원래 도시로 돌아오려고 한다.(한 번 갔던 도시로는 갈 수 없다.)
	이 때, 가장 적은 비용을 구하는 문제
	2 <=  N <= 10
	N! = 3628800
	모든 경우를 다해봐도 시간 안에 나온다.
	O(N!)
*/
int n;
int arr[15][15];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	vector<int> a;
	for (int i = 0; i < n; i++) {
		a.push_back(i);
	}
	int ans = 100000000;

	do {
		if (a[0] != 0) break;
		int sum = 0;
		bool ok = true;

		for (int i = 0; i < n - 1; i++) {
			if (arr[a[i]][a[i + 1]] == 0) {
				ok = false;
				break;
			}
			else sum += arr[a[i]][a[i + 1]];
		}
		if (ok == true && arr[a[n - 1]][0] != 0) {
			sum += arr[a[n - 1]][0];
			if (ans > sum) ans = sum;
		}
	} while (next_permutation(a.begin(), a.end()));
	cout << ans << '\n';
	cin >> n;
	return 0;
}