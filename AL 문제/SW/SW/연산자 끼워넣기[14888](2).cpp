#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	������ �����ֱ�
	https://www.acmicpc.net/problem/14888

	N���� ���� �̷���� ������ N -1���� �����ڰ� �ִ�.(2 <= N <= 11)
	�̶�, ���� �� ���̿� �����ڸ� �ϳ��� �����־ ���� �� �ִ� ���� ����� �ִ밪�� �ּҰ��� ���ϴ� ����
	������ ����� ������ �켱������ �����ϰ� �տ������� �����Ѵ�.
	���� ������ �ٲ� �� ����.
	N <= 11�̰�, �����ڴ� �ִ� 10���̱� ������, N!������ ��� ����� ���� ��ȸ�غ���.
*/

// pointer knowledgement need!!!!!
int calc(vector<int> &a, vector<int> &b) {
	int ans = a[0];
	for (int i = 1; i < a.size(); i++) {
		if (b[i - 1] == 0)
			ans += a[i];
		else if (b[i - 1] == 1)
			ans -= a[i];
		else if (b[i - 1] == 2)
			ans *= a[i];
		else
			ans /= a[i];
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> b;
	for (int i = 0; i < 4; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
			b.push_back(i);
	}
	sort(b.begin(), b.end());
	vector<int> temp;
	do {
		temp.push_back(calc(a, b));
	} while (next_permutation(b.begin(), b.end()));
	auto as = minmax_element(temp.begin(), temp.end());
	cout << *as.second << '\n';
	cout << *as.first << '\n';
	return 0;
}