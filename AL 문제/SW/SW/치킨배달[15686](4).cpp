#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
/*
	알고리즘 분류 : 브루트 포스  
	https://www.acmicpc.net/problem/15686
	집과 치킨집과의 거리를 각각 구해서 최소의 치킨 거리를 구하는 문제다. 
	여러 개의 치킨 집에서 M개의 치킨 집을 고른 후, 문제에 주어진 조건대로 치킨 거리를 구해서 답을 찾아야 한다.

	입력받을 때, 치킨집(2)의 개수와 집(1)의 개수를 세고, 각 좌표 (X, Y)를 리스트에 저장한다.
	치킨집의 총 개수를 K개라고 할 때, 재귀 함수를 통해 K개 중 M개를 골라야 한다. 조합 방식으로 고르면 된다.
	M개의 치킨집을 모두 고르면, 집과 치킨집과의 치킨거리를 구하고, 그중 최솟값을 정답으로 한다.

*/
struct pos {
	int x, y;
};

int n, m, ans = 1e9;
vector<pos> home, chicken;
vector<int> v;

void solve(int idx, int cnt) {
	if (idx > (int)chicken.size()) return;
	if (cnt == m) {
		int sum = 0;
		for (int i = 0; i<(int)home.size(); i++) {
			int d = 1e9;
			for (auto j : v) {
				d = min(d, abs(home[i].x - chicken[j].x) + abs(home[i].y - chicken[j].y));
			}
			sum += d;
		}
		ans = min(ans, sum);
		return;
	}
	v.push_back(idx);
	solve(idx + 1, cnt + 1);
	v.pop_back();
	solve(idx + 1, cnt);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			scanf("%d", &a);
			if (a == 1) home.push_back({ i, j });
			else if (a == 2) chicken.push_back({ i, j });
		}
	}
	solve(0, 0);
	printf("%d\n", ans);
	return 0;
}