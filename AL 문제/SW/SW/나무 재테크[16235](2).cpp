#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
/*
	na982
	���� ����
	N by N ���� ������ ������ �ɰ�, �� ���� ���� �ܿ��� ���鼭
	������ ��ȭ�� �͵��� �����մϴ�.
	K���� ������ �� ������ ���� ����ϴ� ���� �Դϴ�.

	N�� �ִ� 10�̸�, K�� �ִ� 1000�̰� �ʱ� �������� �ִ� N^2 �Դϴ�.

	�� ���� ���� �ܿ￡ ������ ��ȭ�� ����

	������ ������ �ڽ��� ���̸�ŭ ����� �԰�, ���̰� 1 �����Ѵ�.
	������ ������ ������ �ִ� 1 * 1 ũ���� ĭ�� �ִ� ��и� ���� �� �ִ�.
	�ϳ��� ĭ�� ���� ���� ������ �ִٸ�, ���̰� � �������� ����� �Դ´�.
	����, ���� ����� ������ �ڽ��� ���̸�ŭ ����� ���� �� ���� ������ ����� ���� ���ϰ�
	��� �״´�.

	�������� ���� ���� ������ ������� ���ϰ� �ȴ�.
	������ ���� �������� ���̸� 2�� ���� ���� ������ �ִ� ĭ�� ������� �߰� �ȴ�.
	�Ҽ��� �Ʒ��� ������.

	�������� ������ �����Ѵ�.
	�����ϴ� ������ ���̰� 5�� ����̾�� �ϸ�, ������ 8 ���� ĭ�� ���̰� 1�� ������ �����.
	� ĭ (r, c)�� ������ ĭ�� (r -1 , c- 1), (r -1, c) , (r - 1, c +1) ,(r , c - 1) , (r, c+1), (r+1, c -1), (r +1, c),(r+1, c+1)�̴�.
	���� ���� ����� ĭ���� ������ ������ �ʴ´�.

	�ܿ￡�� S2D2�� ���� ���ƴٴϸ鼭 ���� ����� �߰��Ѵ�.
	�� ĭ�� �߰��Ǵ� ����� ���� A[r][c]�̰�, �Է����� �־�����.

	N�� K�� ����� �۰�, ���������� int�� ����� ���� �ʱ� ������ �پ� ���Ǵ�� ����
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
