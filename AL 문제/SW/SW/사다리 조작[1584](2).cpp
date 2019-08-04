#include<iostream>
using namespace std;
int n, m, h, ret;
int map[31][11];
/*
	사다리 조작
	https://www.acmicpc.net/problem/15684
	544ms

	DFS
	Queue

	사다리 정보가 입력으로 들어오고
	추가로 0, 1, 2, 3개의 라인을 추가하여
	각자 자기 자리로 되돌아 가는 사다리를 만드는 문제
	출력은 위의 조건을 만족하기 위해서 최소로 추가해야
	하는 라인 수를 출력하는 문제

	3개를 추가 해서도 조건에 만족하지 못하면 -1
	사다리의 세로의 길이는 최대 30줄
	가로의 길이는 최대 10칸이다
	라인이 연속해서 있을 수 없다.

	1. 입력을 처리해서 어떻게 사다리를 표현할 것인가?
	2. 입력된 사다리를 가지고 결과를 어떻게 체크 할 수 있을까?
	3. 추가 할 수 있는 최대 사다리가 3개 뿐이 없기 때문에,
	다해보면 된다. (Depth가 많이 들어가면 queue로 돌리는것이 권장)
*/
bool check() {
	bool ret = true;
	for (int i = 1; i <= n; i++) {
		int pos = i;
		for (int j = 0; j <= h; j++) {
			if (map[j][pos] == 1) {
				++pos;
			}
			else if (map[j][pos - 1] == 1) {
				--pos;
			}
		}
		if (pos != i) {
			return ret = false;
		}
	}

	return ret;
}

void dfs(int count, int y, int x) {
	if (count >= ret) return;
	if (check()) {
		ret = count;
		return;
	}
	if (count == 3) return;
	for (int i = y; i <= h; i++) {
		for (int j = x; j < n; j++) {
			if (map[i][j] == 0 && map[i][j - 1] == 0 && map[i][j + 1] == 0) {
				map[i][j] = 1;
				dfs(count + 1, i, j);
				map[i][j] = 0;
			}
		}
		x = 1;
	}
}

int main() {
	cin >> n >> m >> h;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
	}

	ret = 4;
	dfs(0, 1, 1);
	if (ret == 4) ret = -1;

	cout << ret << '\n';
	return 0;
}