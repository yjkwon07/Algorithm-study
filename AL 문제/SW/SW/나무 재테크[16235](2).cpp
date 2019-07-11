#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
/*
	na982
	문제 설명
	N by N 격자 공간에 나무를 심고, 봄 여름 가을 겨울을 나면서
	나무가 변화는 것들을 구현합니다.
	K년이 지났을 때 나무의 수를 출력하는 문제 입니다.

	N은 최대 10이며, K는 최대 1000이고 초기 나무수는 최대 N^2 입니다.

	봄 여름 가을 겨울에 나무가 변화는 과정

	봄에는 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다.
	각각의 나무는 나무가 있는 1 * 1 크기의 칸에 있는 양분만 먹을 수 있다.
	하나의 칸에 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다.
	만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고
	즉시 죽는다.

	여름에는 봄에 죽은 나무가 양분으로 변하게 된다.
	각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가 된다.
	소수점 아래는 버린다.

	가을에는 나무가 번식한다.
	번식하는 나무는 나이가 5의 배수이어야 하며, 인접한 8 개의 칸에 나이가 1인 나무가 생긴다.
	어떤 칸 (r, c)와 인접한 칸은 (r -1 , c- 1), (r -1, c) , (r - 1, c +1) ,(r , c - 1) , (r, c+1), (r+1, c -1), (r +1, c),(r+1, c+1)이다.
	상동의 땅을 벗어나는 칸에는 나무가 생기지 않는다.

	겨울에는 S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다.
	각 칸에 추가되는 양분의 양은 A[r][c]이고, 입력으로 주어진다.

	N과 K가 충분히 작고, 나무개수가 int형 사이즈를 넘지 않기 때문에 근야 조건대로 구현
*/
struct TREE {
	int y, x, age;
};

bool operator<(TREE a, TREE b) {
	return (a.age > b.age);
}

int n, m, k;
priority_queue<TREE> pq[2];
int map[10][10], add[10][10];

const int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main() {
	int cur = 0, next;

	scanf("%d %d %d", &n, &m, &k);
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			scanf("%d", &add[y][x]);
			map[y][x] = 5;
		}
	}

	for (int i = 0; i < m; i++) {
		TREE tree;
		scanf("%d %d %d", &tree.y, &tree.x, &tree.age);
		--tree.y, --tree.x;
		pq[cur].push(tree);
	}

	for (int i = 0; i < k; i++) {
		next = (cur + 1) % 2;
		queue<TREE> life_tree;
		queue<TREE> dead_tree;

		while (!pq[cur].empty()) {
			TREE cur_tree = pq[cur].top(); pq[cur].pop();

			if (map[cur_tree.y][cur_tree.x] >= cur_tree.age) {
				map[cur_tree.y][cur_tree.x] -= cur_tree.age;

				TREE next_tree;
				next_tree.y = cur_tree.y;
				next_tree.x = cur_tree.x;
				next_tree.age = cur_tree.age + 1;

				life_tree.push(next_tree);
				pq[next].push(next_tree);
			}

			else {
				dead_tree.push(cur_tree);
			}

		}

		while (!dead_tree.empty()) {
			TREE cur_tree = dead_tree.front(); dead_tree.pop();
			map[cur_tree.y][cur_tree.x] += (cur_tree.age / 2);
		}

		while (!life_tree.empty()) {
			TREE cur_tree = life_tree.front(); life_tree.pop();
			if ((cur_tree.age % 5) == 0) {
				for (int dir = 0; dir < 8; dir++) {
					TREE next_tree;
					next_tree.y = cur_tree.y + dy[dir];
					next_tree.x = cur_tree.x + dx[dir];
					next_tree.age = 1;

					if (next_tree.y < 0 || next_tree.y >= n || next_tree.x < 0 || next_tree.x >= n) {
						continue;
					}
					pq[next].push(next_tree);
				}
			}
		}

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				map[y][x] += add[y][x];
			}
		}

		cur = next;
	}

	printf("%d\n", pq[next].size());

	return 0;
}
