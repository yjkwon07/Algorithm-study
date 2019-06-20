#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	�ϰ� ������
	https://www.acmicpc.net/problem/2309

	��ȩ ���� ������ �� �ϰ� ���� �����̸� ã�� ����
	�ϰ� �������� Ű�� ���� 100�̴�.
	��ȩ �� �߿� �� ���� ���� �Ͱ� ����.
	�������� ���� N�̶�� ���� ��
	�� ���� ���� ����� ��: N^2��� �� �� �ִ�.
	������ �������� Ű�� ���� ���� �ð����⵵: O(N)
	O(N^2)(����� ����) * O(N)(��) = O(N^3)
*/
int main() {

	int n = 9;
	vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((sum - a[i] - a[j]) == 100) {
				for (int k = 0; k < n; k++) {
					if (i == k || j == k) continue;
					cout << a[k] << '\n';
				}
				return 0;
			}
		}
	}
	return 0;
}