#include<iostream>
#include<vector>
using namespace std;
/*
	�κм����� ��
	https://www.acmicpc.net/problem/1182

	���� �ٸ� N���� ������ �̷���� ������ ���� ��, 
	�� ������ �������� �ƴ� �κ����� �߿��� 
	�������� ���Ҹ� �� ���Ѱ��� S�� �Ǵ� ����� ���� ���ϴ� ����
	1 <= N <= 20
	go(index, sum)
	index: �κ����տ� �������� ���� �����ؾ� �ϴ� �ε���
	sum: ������� �κ������� ��
*/
int go(vector<int> & a, int index, int m, int sum) {
	int ans = 0;
	int n = a.size();
	if (index == n) {
		if (sum == m) {
			return 1;
		}
		return 0;
	}
	ans += go(a, index + 1, m, sum + a[index]);
	ans += go(a, index + 1, m, sum);
	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = go(a, 0, m, 0);
	if (m == 0) ans -= 1;
	cout << ans << '\n';
	cin >> n;
	return 0;
}