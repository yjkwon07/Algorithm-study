#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	로또
	https://www.acmicpc.net/problem/6603

	로또의 모든 조합을 출력해보는 문제 
	go(index, cnt)
		index: 선택할지 말지 결정해야 하는 인덱스
		cnt: 현재까지 포함한 수의 개수
*/
vector<int> num;
int a[7];
int n;

void go(int index, int selected) {
	if (index == n) {
		if (selected == 6) {
			for (int i = 0; i < 6; i++) {
				cout << num[a[i]] << ' ';
			}
			cout << '\n';
		}
		return;
	}

	if (selected > 6) return;
	a[selected] = index;
	go(index + 1, selected + 1);
	go(index + 1, selected);
}

int main() {

	while (true) {
		cin >> n;
		if (n == 0) break;
		num = vector<int>(n);
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		go(0, 0);
		cout << '\n';
	}
	return 0;
}