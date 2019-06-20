#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
	��ȣ �����
	https://www.acmicpc.net/problem/1759

	��ȣ�� ���� �ٸ� L���� ���ĺ� �ҹ��ڵ�� �����Ǹ� �ּ� �� ���� ������ �ּ� �� ���� �������� �����Ǿ� �ִ�.
	��ȣ�� �̷�� ���ĺ��� ��ȣ���� �����ϴ� ������ �迭�Ǿ���� �Ѵ�.
	��ȣ�� ����� �� �ִ� ������ ������ c����
	���ɼ� �ִ� ��ȣ�� ��� ���ϴ� ����

*/
int start[20];
bool check_ja_mo(string goal) {
	int ja = 0;
	int mo = 0;

	for (char x : goal) {
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
			mo += 1;
		}
		else ja += 1;
	}

	return ja >= 2 && mo >= 1;
}
void create_passward(int index, int selected, int n, vector<char> &a, string goal) {
	if (index == a.size()) {
		if (goal.length() == n) {
			if (check_ja_mo(goal)) {
				cout << goal << '\n';
			}
			return;
		}
		return;
	}

	start[index] = selected;
	create_passward(index + 1, selected + 1, n, a, goal + a[start[index]]);
	create_passward(index + 1, selected + 1, n, a, goal);
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<char> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	create_passward(0, 0, n, a, "");
	return 0;
}