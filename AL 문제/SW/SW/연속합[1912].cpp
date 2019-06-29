#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
	������ 
	https://www.acmicpc.net/problem/1912
	
	n���� ������ �̷���� ������ ������ �־�����.
	�츮�� �� �� ���ӵ� �� ���� ���ڸ� �����ؼ� ���� �� �ִ� �� �� ���� ū ���� ���Ϸ��� �Ѵ�.
	��, ���ڴ� �� �� �̻� �����ؾ� �Ѵ�.
	���� �� 10, -4, 3, 1, 5, 6, -35, 12, 21, -1�̶�� ������ �־����ٰ� ����.
	���⼭ ������ 12+ 21�� 33�� ������ �ȴ�.
	D[i] = i��° ���� ������ ���� ū ������
	�̷��� ���� ��������, i��° ������ ������ ��츦 ����� �Ѵ�.
	i��° �� ���� ������ ���
	i -1��° ���� �����տ� ���ԵǴ� ���
	D[i-1] + A[i]
	���ο� �������� �����ϴ� ���
	A[i]
	�� �� �߿��� � ���� D[i]�� ���� �ұ�?(�ִ밪)
	D[i] = max(D[i-1] + A[i], A[i])

*/
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i<n; i++) {
		cin >> a[i];
	}
	vector<int> d(n);
	for (int i = 0; i<n; i++) {
		d[i] = a[i];
		if (i == 0) continue;
		if (d[i] < d[i - 1] + a[i]) {
			d[i] = d[i - 1] + a[i];
		}
	}
	int ans = d[0];
	for (int i = 1; i<n; i++) {
		if (ans < d[i]) {
			ans = d[i];
		}
	}
	cout << ans << '\n';
	return 0;
}