#include<stdio.h>
#include<queue>
using namespace std;
/*
	�Ʊ� ���
	https://www.acmicpc.net/problem/16236
	
	na982
	���� ����
	20 by 20 ���� �������� �� 1���� �ְ�,
	����Ⱑ 1ĭ�� 1���� �Ǵ� 0������ ���� �մϴ�.
	�� 1ĭ�� �̵��ϱ� ���ؼ��� 1��ŭ�� �ð��� �ʿ��մϴ�.

	���� �ڽź��� ���� ����⸦ ���� �� �ְ�, �ڽź��� ū ����� ĭ���� �� �� �����ϴ�.

	���� �ڽ��� ���̿� ���� ���� ����⸦ ������ ���̰� 1��ŭ ���� �մϴ�.
	(���̰� �����ϸ� �ٽ� ���� ��ŭ ����⸦ �Ծ�� ���� �� �� �ֽ��ϴ�.)

	���� ���� ����� �������� �Խ��ϴ�.
	���� �� �ִ� ����Ⱑ ���� ���� �̸�, ���� ���� �ִ� ����⸦ �Խ��ϴ�.
	���� ���� ����Ⱑ ���� ���� �̸�, ���� ���ʿ� ����⸦ �Խ��ϴ�.

	�� ���� �� �ִ� ��� ����⸦ �Ծ��� ��, �ɸ��� �ּ� �ð��� ����ϴ� ���� �Դϴ�.
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
		// �켱 ����
		candi.y = 20, candi.time = -1;

		while (!q.empty()) {
			SHARK cur = q.front(); q.pop();

			// candi update check
			// 4 ������ ��� üũ �ؾ� �ϱ� ������
			// 4������ ��� üũ�ϰ� ������ cur.time+1 ��Ȳ�̱� ������ 
			// candi.time < cur.time 
			if (candi.time != -1 && candi.time < cur.time) {
				// update �Ϸ� ����
				break;
			}

			// 0 < map < shark_size
			if (map[cur.y][cur.x] < shark_size && map[cur.y][cur.x] != 0) {
				is_update = true;
				// �켱 ���� üũ 
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