#include <iostream>
#include <string>
using namespace std;
/*
	�ε�ȣ
	https://www.acmicpc.net/problem/2529
	�˰��� �з� : ��Ʈ��ŷ

	�⺻������ ��� �Լ��� �̿��Ͽ� ���Ʈ ������ ������ �� �ִ�. 
	��� �Լ��� ȣ���ϱ� ���� �ε�ȣ üũ�� �ϴ� ������� ��Ʈ��ŷ�� �Ͽ� �ð��� ������ �� �ִ�.

	�ϳ��� ���ڸ� ���ϱ� ���ؼ� �Է����� �־��� ����(N)+1 ��ŭ ��� �Լ��� ȣ���ؾ� �Ѵ�. 
	�ùٸ� �ε���� ���� ������ �ε�ȣ �������� 1�� �� ����.
	��� �Լ� ���� ���� : ���� ����(����) == N+1
	���� �ߺ��Ͽ� ����� �� �����Ƿ�, check �迭�� ������ ���� ��� ���θ� Ȯ���ؾ� �Ѵ�.
	��� �Լ��� ȣ���ϱ� ����, ���� ���ڰ� �ε�Ŀ� �´��� ������� �Ѵ�.
	���� ���, �־��� �ε�ȣ�� < > > ���, 0 < 3 > 2 > 1�� �����ϴ�.
	������ 3 < 2 > 1 > 0�� �Ұ����ϴ�. �̷� ���, 3 < 2���� Ʋ�� �ε���̹Ƿ�, �� �ڷδ� �Լ��� ȣ���� �ʿ䰡 ����.
	��� �Լ� ȣ���� 0���� 9���� ������� �θ��Ƿ�, ������ �ּڰ��� ó�� ȣ��� ���̸�, �ִ��� �������� ȣ��� ���̴�.
*/
int n;
char op[9];
bool c[10];
string mn, mx;

bool possible(int i, int j, char k) {
	if (k == '<') return i < j;
	if (k == '>') return i > j;
	return true;
}

void solve(int cnt, string s) {
	if (cnt == n + 1) {
		if (!mn.size()) mn = s;
		else mx = s;
		return;
	}
	for (int i = 0; i<10; i++) {
		if (c[i]) continue;
		if (cnt == 0 || possible(s[cnt - 1], i + '0', op[cnt - 1])) {
			c[i] = true;
			solve(cnt + 1, s + to_string(i));
			c[i] = false;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i<n; i++) cin >> op[i];
	solve(0, "");
	cout << mx << '\n';
	cout << mn << '\n';
	return 0;
}
