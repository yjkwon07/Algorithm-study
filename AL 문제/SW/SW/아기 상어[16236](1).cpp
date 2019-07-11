#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
/*
	�Ʊ� ���
	https://www.acmicpc.net/problem/16236
	�˰��� �з� : BFS

	�Ʊ� �� ����⸦ �����鼭 �����̴� �ִ� �Ÿ��� ���ϴ� ������. 
	���� ���� ������ ��ٷο� ������. 
	ù ��°, �Ʊ� ���� �ڽź��� ũ�ų� ���� ũ���� ����⸦ ���� �� ����. 
	�� ��°, ���� ���� ����� ��ġ�� �ִ� ����⸦ �켱������ �Ծ�� �Ѵ�. 
	�� ��°, ���� ������ �����̿� �ִٸ�, ���� ���ʿ� �ִ� �����, �״��� ������ ���� ���ʿ� �ִ� ����⸦ �켱������ �Ծ�� �Ѵ�.
	�� �� ���� ������ ��� �����ϸ鼭 BFS Ž���� �ϱ� ���ؼ���, �ּ� ��(Min Heap)�� ������ �켱���� ť(Priority Queue)�� ����ϸ� �ȴ�.

	����� ũ��(body), ����⸦ ���� Ƚ��(eat)�� ������ �����ϴ� ������ �д�.
	BFS�� ����� ť�� �켱���� ť�� ��ü�Ѵ�. C++�� ��� priority_queue�� �⺻������ Max Heap�̹Ƿ�, ������ �����ε��� ���� Min Heap���� �ٲ�� �Ѵ�. �Ǵ� ������ ó���ϸ� Min Heapó�� �̿��� �� �ִ�. ���̽��� Heapq�� ����ϸ� �ȴ�.
	Min Heap�� �켱������ �̵� �Ÿ�(d), �� ��ǥ(x), �� ��ǥ(y) ������ �д�. ������ �־��� �켱������ �Ÿ��� ����� ��, ���� ����, ���� ���� �����̱� �����̴�.
	������� ũ�Ⱑ ���� ũ�ų� ���ٸ�, ���� ���ϴ� ����̹Ƿ� �����ϰ� �������� �ȴ�.
	�� ����⸦ �Ա� ������, ������ ������ �̵��Ÿ��� 1�� ������Ų��.
	�����̴ٰ�, ��� ũ�⺸�� ���� ũ���� ����⸦ �߰��ϸ� �Դ´�. ���� ĭ�� 0���� �ٲ۴�. ���信 ������� �̵��� �Ÿ��� ���Ѵ�. ���� Ƚ���� 1 ������Ų��.
	���� ���� Ƚ���� ����� ũ��� ���ٸ�, ��� ũ�⸦ 1 ������Ű��, ���� Ƚ���� 0���� �����.
	���� ����⸦ �Ա� ���� ������ ��, �̹� ���� ���� �ٽ� �湮�� ���� �ִ�. ���� �Ÿ��� �湮 üũ �迭�� ��� �ʱ�ȭ�Ѵ�. ť�� ����ִ� ��ǥ�� ����.
	�� �̻� ���� �� �ִ� ����Ⱑ ���ٸ� �����Ѵ�.
*/
#define MAX 20
int shark_size = 2;
int shark_eat = 0;
int ans = 0;
int N;
int arr[MAX][MAX];
bool checked[MAX][MAX];
const int dx[] = { 0 , 0 , 1, -1 };
const int dy[] = { 1 , -1, 0 , 0 };

struct FISH {
	int dist, x, y;
	bool operator < (const FISH & fh) const {
		if (dist == fh.dist) {
			if (x == fh.x) return y > fh.y;
			else return x > fh.x;
		}
		else return dist > fh.dist;
	}
};

priority_queue<FISH> pq;

void _init() {
	memset(checked, false, sizeof(checked));
	pq = priority_queue<FISH>();
}

void _bfs() {

	while (!pq.empty()) {
		int dist = pq.top().dist;
		int x = pq.top().x;
		int y = pq.top().y;
		pq.pop();
		//cout << x << y << '\n';

		if (0 < arr[x][y] && arr[x][y] < shark_size) {
			arr[x][y] = 0;
			shark_eat++;
			if (shark_eat == shark_size) {
				shark_size++;
				shark_eat = 0;
			}
			ans += dist;
			dist = 0;
			_init();
		}

		for (int k = 0; k < 4; k++) {

			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (checked[nx][ny]) continue;
			if (0 < arr[nx][ny] && arr[nx][ny] > shark_size) continue;
			checked[nx][ny] = true;
			pq.push({ dist + 1, nx, ny });
		}
	}
}

void _solve() {
	_bfs();
	cout << ans << '\n';
}

int main() {
	_init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				pq.push({ 0, i, j });
				arr[i][j] = 0;
			}
		}
	}
	_solve();
	return 0;
}