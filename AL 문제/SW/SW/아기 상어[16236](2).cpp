#include<stdio.h>
#include<queue>
using namespace std;
/*
	아기 상어
	https://www.acmicpc.net/problem/16236
	
	na982
	문제 설명
	20 by 20 격자 지도에서 상어가 1마리 있고,
	물고기가 1칸에 1마리 또는 0마리가 존재 합니다.
	상어가 1칸을 이동하기 위해서는 1만큼의 시간이 필요합니다.

	상어는 자신보다 작은 물고기를 먹을 수 있고, 자신보다 큰 물고기 칸에는 갈 수 없습니다.

	상어는 자신의 길이와 같은 수의 물고기를 먹으면 길이가 1만큼 증가 합니다.
	(길이가 증가하면 다시 길이 만큼 물고기를 먹어야 증가 할 수 있습니다.)

	상어는 가장 가까운 물고기부터 먹습니다.
	먹을 수 있는 물고기가 여러 마리 이면, 가장 위에 있는 물고기를 먹습니다.
	같은 열에 물고기가 여러 마리 이면, 가장 왼쪽에 물고기를 먹습니다.

	상어가 먹을 수 있는 모든 물고기를 먹었을 때, 걸리는 최소 시간을 출력하는 문제 입니다.
*/

struct SHARK {
	int y, x, time;
};

int n;
int map[20][20];

int shark_size, shark_eat;
SHARK shark;

const int dy[] = { 0 , 0 ,1, -1 };
const int dx[] = { 1, -1, 0, 0 };

int main() {

	scanf("%d", &n);
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			scanf("%d", &map[y][x]);
			if (map[y][x] == 9) {
				shark.y = y, shark.x = x, shark.time = 0;
				shark_size = 2, shark_eat = 0;
				map[y][x] = 0;
			}
		}
	}

	bool is_update = true;
	while (is_update) {
		is_update = false;

		bool visited[20][20] = { false, };
		queue<SHARK> q;
		visited[shark.y][shark.x] = true;
		q.push(shark);

		SHARK candi;
		// 우선 순위
		candi.y = 20, candi.time = -1;

		while (!q.empty()) {
			SHARK cur = q.front(); q.pop();

			// candi update check
			// 4 방향을 모두 체크 해야 하기 때문에
			// 4방향을 모두 체크하고 다음은 cur.time+1 상황이기 때문에 
			// candi.time < cur.time 
			if (candi.time != -1 && candi.time < cur.time) {
				// update 하러 가기
				break;
			}

			// 0 < map < shark_size
			if (map[cur.y][cur.x] < shark_size && map[cur.y][cur.x] != 0) {
				is_update = true;
				// 우선 순위 체크 
				if (candi.y > cur.y || (candi.y == cur.y && candi.x > cur.x)) {
					candi = cur;
				}
			}

			for (int dir = 0; dir < 4; dir++) {
				SHARK next;
				next.y = cur.y + dy[dir];
				next.x = cur.x + dx[dir];
				next.time = cur.time + 1;

				if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n)continue;
				// 0 <= map <shark_size
				if (visited[next.y][next.x] == false && shark_size >= map[next.y][next.x]) {
					visited[next.y][next.x] = true;
					q.push(next);
				}
			}
		}

		if (is_update) {
			shark = candi;
			shark_eat++;

			if (shark_eat == shark_size) {
				shark_size++;
				shark_eat = 0;
			}

			map[shark.y][shark.x] = 0;
		}

	}

	printf("%d\n", shark.time);
	return 0;
}