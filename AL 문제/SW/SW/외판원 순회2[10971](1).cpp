#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	���ǿ� ��ȸ2
	https://www.acmicpc.net/problem/10971

	1������ N������ ��ȣ�� �Ű����ִ� ���ð� �ִ�.
	�� ���ÿ��� ������ N���� ��� ���ø� ���� �ٽ� ���� ���÷� ���ƿ����� �Ѵ�.(�� �� ���� ���÷δ� �� �� ����.)
	�� ��, ���� ���� ����� ���ϴ� ����
	2 <=  N <= 10
	N! = 3628800
	��� ��츦 ���غ��� �ð� �ȿ� ���´�.
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