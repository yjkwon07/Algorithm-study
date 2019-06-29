#include<iostream>
#include<algorithm>
using namespace std;
/*
	��ƼĿ 
	https://www.acmicpc.net/problem/9465

	��ƼĿ 2n���� 2 *n������� ��ġ�Ǿ� �ִ�.
	��ƼĿ �� ���� ���� ���� �����ϴ� ��ƼĿ�� ��� �������� ����� �� ����.
	������ ���� �ִ�� ����� ����
	D[i][j] = 2 * i���� ���� �� �ִ� �ִ� ����, i�� ������ ��� ��ƼĿ�� j
	j = 0 -> ���� ����
	 i - 1������ ��ƼĿ�� ��� ������� ����� ����
	max(D[i-1][0], D[i-1][1], D[i-1][2])
	j = 1-> ���� ��ƼĿ�� ����
	 i - 1������ ���� ��ƼĿ�� ������ �ȵȴ�.
	max(D[i-1][0], D[i-1][2] + A[i][0])
	j =2 -> �Ʒ��� ��ƼĿ�� ����
	 i - 1������ ��ƼĿ�� ��� ������� ����� ����
	max(D[i-1][0], D[i-1][1] + A[i][1])

*/
long long a[100001][2];
long long D[100001][3];
int main() {

	int n, m;
	cin >> n;
	while (n--) {
		cin >> m;
		for (int i = 1; i <= m; i++) {
			cin >> a[i][0];
		}
		for (int i = 1; i <= m; i++) {
			cin >> a[i][1];
		}
		D[0][0] = 0;
		D[0][1] = 0;
		D[0][2] = 0;
		for (int i = 1; i <= m; i++) {
			D[i][0] = max(D[i - 1][0], max(D[i - 1][1], D[i - 1][2]));
			D[i][1] = max(D[i - 1][0], D[i - 1][2]) + a[i][0];
			D[i][2] = max(D[i - 1][0], D[i - 1][1]) + a[i][1];
		}
		long long ans = 0;
		for (int i = 1; i <= m; i++)
			ans = max(max(ans, D[i][0]), max(D[i][1], D[i][2]));
		cout << ans << '\n';
	}
	return 0;
}