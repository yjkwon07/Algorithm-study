#include <stdio.h>
#include <algorithm>
using namespace std;
/*
	나무 재테크
	https://www.acmicpc.net/problem/16235
	queue 구현 
*/

struct TREE {
	int y, x, age;
};

bool cmp(TREE& a, TREE& b) {
	return (a.age < b.age);
}

struct QUEUE {
	int f, b;
	TREE tree[684000];

	QUEUE() {
		init();
	}

	void init() {
		f = 0, b = 0;
	}

	bool isempty() {
		return (f == b);
	}

	void push(TREE val) {
		tree[b++] = val;
	}

	void pop() {
		++f;
	}

	TREE front() {
		return tree[f];
	}

	int size() {
		return (b - f);
	}
};

int n, m, k;
QUEUE tree[2];
QUEUE new_tree;
QUEUE dead_tee, birth_of_child_tree;

TREE init_tree[100];

int map[10][10], add[10][10];

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			scanf("%d", &add[y][x]);
			map[y][x] = 5;
		}
	}

	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &init_tree[i].y, &init_tree[i].x, &init_tree[i].age);
		init_tree[i].y--, init_tree[i].x--;
	}

	sort(init_tree, init_tree + m, cmp);

	int cur = 0, next = 0;
	for (int i = 0; i < m; ++i) {
		tree[cur].push(init_tree[i]);
	}

	for (int i = 0; i < k; ++i) {

		next = (cur + 1) % 2;

		dead_tee.init();
		birth_of_child_tree.init();
		tree[next].init();

		while (!new_tree.isempty()) {
			TREE cur_tree = new_tree.front(); new_tree.pop();

			if (map[cur_tree.y][cur_tree.x] >= cur_tree.age) {
				map[cur_tree.y][cur_tree.x] -= cur_tree.age;
				++cur_tree.age;
				tree[next].push(cur_tree);
			}
			else {
				dead_tee.push(cur_tree);
			}
		}

		while (!tree[cur].isempty()) {
			TREE cur_tree = tree[cur].front(); tree[cur].pop();

			if (map[cur_tree.y][cur_tree.x] >= cur_tree.age) {
				map[cur_tree.y][cur_tree.x] -= cur_tree.age;

				++cur_tree.age;
				tree[next].push(cur_tree);

				if ((cur_tree.age % 5) == 0) {
					birth_of_child_tree.push(cur_tree);
				}
			}
			else {
				dead_tee.push(cur_tree);
			}
		}

		while (!dead_tee.isempty()) {
			TREE cur_tree = dead_tee.front();	dead_tee.pop();
			map[cur_tree.y][cur_tree.x] += (cur_tree.age / 2);
		}

		const int dy[] = { -1, -1, -1, 0, 0, +1, +1, +1 };
		const int dx[] = { -1, 0, +1, -1, +1, -1, 0, +1 };

		new_tree.init();
		while (!birth_of_child_tree.isempty()) {
			TREE cur_tree = birth_of_child_tree.front(); birth_of_child_tree.pop();
			for (int dir = 0; dir < 8; ++dir) {
				TREE next_tree;
				next_tree.y = cur_tree.y + dy[dir];
				next_tree.x = cur_tree.x + dx[dir];
				next_tree.age = 1;
				if (next_tree.y < 0 || next_tree.y >= n || next_tree.x < 0 || next_tree.x >= n) {
					continue;
				}
				new_tree.push(next_tree);
			}
		}

		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < n; ++x) {
				map[y][x] += add[y][x];
			}
		}

		cur = next;
	}

	printf("%d\n", tree[next].size() + new_tree.size());

	return 0;
}