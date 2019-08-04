#include<iostream>
#include<cstring>
#include<queue>
#include<deque>
using namespace std;
/*
나무 재테크

*/
#define MAX 10
int N, M, K, ans;
int nt[MAX][MAX];
int map[MAX][MAX];
deque<int> dq[MAX][MAX];
const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void _solve() {

	while (K--) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				int &ont = map[i][j];
				deque<int> &d = dq[i][j];

				for (int h = 0; h < (int)d.size(); h++) {
					if (ont >= d[h]) {
						ont -= d[h];
						d[h]++;
					}
					else {
						while (h < d.size()) {
							ont += (d.back() / 2);
							d.pop_back();
							ans--;
						}
						break;
					}
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				//				deque<int> &d = dq[i][j];	
				for (int h = 0; h < (int)dq[i][j].size(); h++) {
					if (dq[i][j][h] % 5 == 0) {
						for (int k = 0; k < 8; k++) {
							int nx = i + dx[k];
							int ny = j + dy[k];
							if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
							ans++;
							dq[nx][ny].push_front(1);
						}
					}
				}

				map[i][j] += nt[i][j];
			}
		}
	}

	cout << ans << '\n';
}
int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> nt[i][j];
			map[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int x, y, age;
		cin >> x >> y >> age;
		dq[x - 1][y - 1].push_back(age);
		ans++;
	}
	_solve();
	return 0;
}