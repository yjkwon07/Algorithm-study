// https://www.acmicpc.net/problem/10971

#include <iostream>
#include <vector>
#include <algorithm>
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
	O(N*N!)
*/
int a[15][15];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	vector<int> b(n);
	for (int i = 0; i < n; i++)
		b[i] = i;
	int min = 100000000;
	do {
		int sum = 0;
		bool check = true;
		for (int i = 0; i < n - 1; i++) {
			if (a[b[i]][b[i + 1]] == 0) check = false;
			else {
				sum += a[b[i]][b[i + 1]];
			}
		}
		if (check == true && a[b[n - 1]][b[0]] != 0) {
			sum += a[b[n - 1]][b[0]];
			if (sum < min) min = sum;
		}
	} while (next_permutation(b.begin(), b.end()));
	cout << min << '\n';
	return 0;
}