#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
/*
	ĳ�� ���潺
	https://www.acmicpc.net/problem/17135
	180ms
	�˰��� �з� : ���Ʈ ����, �ùķ��̼�

	�ü��� ���� ������ ��ġ�Ͽ� ���� �ִ��� ���� ���̵��� �����ϴ� ������. 
	������ �ü��� ��ġ�� ��� �����, �� ��ġ���� ���� �󸶳� �� ���� �� �ִ��� ī��Ʈ�ϸ� �ȴ�.

	N*M �������� �ʿ��� �ü��� N+1��° �ٿ� 3���� ��ġ�ȴ�.
	�ü��� ���� ��ġ�� �ʵ���, 3�� for�� �Ǵ� ��͸� ���� ���� ��ġ�Ѵ�. ���� ������� �����ϸ� �ȴ�.
	�׸��� ��ġ�� ��ġ�� �ε����� ������ �����Ѵ�. �Ʒ��� �ڵ忡���� archer �迭�� Y��ǥ(�� �ε���)�� ����Ǿ� �ִ�.
	�� ��ġ���� �ü��κ��� ���� �󸶳� ������ �ִ��� ����ϰ�, �� ���� �׿��� �Ѵ�.

	1. �ü��� ��ġ�� (N, K)��� �ϰ�, ���� ��ġ�� (i, j)��� ����. ��, (0��i��N, 0��j��M) �̴�.
	2. �ü��� �� ������ �Ÿ��� dist = |N-i| + |K-j| �� �ȴ�.
	3. dist�� �Է����� �־��� D ���϶��, ���� �� �ִ� ���� �ĺ��� �ȴ�. �� ���� ��ġ�� �켱���� ť(Min Heap)�� ����ִ´�. 
		�켱���� ť�� �Ÿ�(dist), Y��ǥ(j), X��ǥ(i) ������ �켱������ ������.
	4. ���� ��� ã�� ��, �켱���� ť�� �ִ� ù ��° ���� ������. �� ���� ���� ���� �׿��� �ϴ� ���� ��ġ�̴�. 
		�� ��ġ�� ������ ����Ʈ V�� �����Ѵ�.
	
	�� ���� �ü��� ���ؼ� 1~4������ �����ϰ�, ����Ʈ V���� ���� ������. �� ����Ʈ���� �ߺ��� ��ǥ�� ������ �� �ִ�. 
	�ش� ��ǥ�� �ִ� ���� ��� ���δ�.
	�� ���� ����Ǿ����Ƿ�, ���� �� ĭ�� ��� ������. ���� �ִ� N���� �ٿ� �����ϹǷ�, N���� ������ ��� ������� �ȴ�.
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