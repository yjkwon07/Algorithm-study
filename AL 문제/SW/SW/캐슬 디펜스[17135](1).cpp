#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
/*
	캐슬 디펜스
	https://www.acmicpc.net/problem/17135
	180ms
	알고리즘 분류 : 브루트 포스, 시뮬레이션

	궁수를 성에 적절히 배치하여 적을 최대한 많이 죽이도록 구현하는 문제다. 
	가능한 궁수의 배치를 모두 만들고, 각 배치에서 적을 얼마나 쏴 죽일 수 있는지 카운트하면 된다.

	N*M 사이즈의 맵에서 궁수는 N+1번째 줄에 3명이 배치된다.
	궁수가 서로 겹치지 않도록, 3중 for문 또는 재귀를 통해 각각 배치한다. 조합 방식으로 구현하면 된다.
	그리고 배치한 위치의 인덱스를 별도로 저장한다. 아래의 코드에서는 archer 배열에 Y좌표(열 인덱스)가 저장되어 있다.
	각 배치에서 궁수로부터 적이 얼마나 떨어져 있는지 계산하고, 각 적을 죽여야 한다.

	1. 궁수의 위치를 (N, K)라고 하고, 적의 위치를 (i, j)라고 하자. 단, (0≤i＜N, 0≤j＜M) 이다.
	2. 궁수와 적 사이의 거리는 dist = |N-i| + |K-j| 가 된다.
	3. dist가 입력으로 주어진 D 이하라면, 죽일 수 있는 적의 후보가 된다. 이 적의 위치를 우선순위 큐(Min Heap)에 집어넣는다. 
		우선순위 큐는 거리(dist), Y좌표(j), X좌표(i) 순으로 우선순위를 가진다.
	4. 적을 모두 찾은 후, 우선순위 큐에 있는 첫 번째 값을 꺼낸다. 이 값은 가장 먼저 죽여야 하는 적의 위치이다. 
		이 위치를 별도의 리스트 V에 저장한다.
	
	세 명의 궁수에 대해서 1~4과정을 진행하고, 리스트 V에서 값을 꺼낸다. 이 리스트에는 중복된 좌표가 존재할 수 있다. 
	해당 좌표에 있는 적을 모두 죽인다.
	한 턴이 종료되었으므로, 적을 한 칸씩 모두 내린다. 적은 최대 N개의 줄에 존재하므로, N번만 내리면 모두 사라지게 된다.
*/
#define MAX 16
int arr[MAX][MAX], attack[3];
struct MOVE {
	int x, y, dist;
	bool operator < (const MOVE &t) const {
		if (t.dist == dist) return y > t.y;
		else return dist > t.dist;
	}
};
int n, m, dist, ans;

void print(int arr[MAX][MAX]) {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int _score() {
	int arr_cp[MAX][MAX], cnt = 0, t = n;
	memcpy(arr_cp, arr, sizeof(arr));
	

	while (t--) {
		// search
		vector<MOVE> v;
		for (int k = 0; k < 3; k++) {
			priority_queue<MOVE> q;
			
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (arr_cp[i][j]) {
						int d = abs(n - i) + abs(attack[k] - j);
						if (d <= dist) q.push({ i , j , d });
					}
				}
			}

			if (q.size()) {
				int x = q.top().x, y = q.top().y;
				v.push_back({ x, y });
			}
		}

		// kill
		for (int i = 0; i < (int)v.size(); i++) {
			int x = v[i].x, y = v[i].y;
			if (arr_cp[x][y]) {
				arr_cp[x][y] = 0;
				cnt++;
			}
		}

		// move
		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				arr_cp[i + 1][j] = arr_cp[i][j];
			}
		}
		for (int i = 0; i < m; i++) {
			arr_cp[0][i] = 0;
		}
		print(arr_cp);
	}
	return cnt;
}

bool checked[MAX];
void _dfs(int cnt) {
	if (cnt == 3) {
		int x = _score();
		ans = max(ans, x);
		return;
	}
	for (int i = 0; i < m; i++) {
		if (!checked[i]) {
			checked[i] = true;
			attack[cnt] = i;
			arr[n][cnt] = 1;
			_dfs(cnt + 1);
			attack[cnt] = 0;
			arr[n][cnt] = 0;
			checked[i] = false;
		}
	}
}

int main() {
	cin >> n >> m >> dist;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	_dfs(0);
	cout << ans << '\n';
	return 0;
}