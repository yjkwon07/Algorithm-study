#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
	암호 만들기
	https://www.acmicpc.net/problem/1759

	암호는 서로 다른 L개의 알파벳 소문자들로 구성되며 최소 한 개의 모음과 최소 두 개의 자음으로 구성되어 있다.
	암호를 이루는 알파벳이 암호에서 증가하는 순서로 배열되었어야 한다.
	암호로 사용할 수 있는 문자의 종류는 c가지
	가능성 있는 암호를 모두 구하는 문제

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