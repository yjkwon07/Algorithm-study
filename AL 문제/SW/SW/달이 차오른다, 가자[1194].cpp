#include <iostream>
#include <queue>
// #include <map>
#include <cstring>
using namespace std;

/*
	���� ��������, ����.
	https://www.acmicpc.net/problem/1194
	ó������ map�� �̿��Ͽ� ���� �湮�� �� ���谡 �ִ��� �Ǻ��Ͽ� �̵��ϱ�� �ߴ�. 
	������ ���⼭ �������� ���� �湮�ߴ� ���� ��� �����ؾ����� ������. 
	humm.. 
	ó�� �����ߴ� logic
	{
		1. bfs ��Ž
		2. key find -> map<char, int> key -> 'a' = 3 (VALUE = distance) -> (flag = true;)
		3. door find -> ���� �ִ���? 
			if(yes) {
				move  = pre_move + (key * 2) + 1; (why key * 2?) -> key�� ã�� �ٽ� ����ġ�� �ǵ��ƿ� ��  + 1(door�� �湮)
				���� => . ���� ��ȯ
			} else continue;
		4. ���� key find���� door�� ���� ã�� �� ������ -> ť�� �������?
			if(yes) {
				key find�� �־�����? (flag = true?)
				if(yes) {
					���� �ִ���? 
					if(yes){
						move = pre_move + (key * 2) + 1;
						���� .���� ��ȯ
					}
				}
				flag  = false;
			}
			else return

		!!__ ������ ���� __ ó�� key�� ã�� ���� �ƹ� ������ ��������, ���� key�� �� ���� ã�� �ȴٸ� ������ �߻��Ѵ�.
		pro
		{
			�� �ٸ� key�� ã�� ��, key  * 2�� ��, (pre_move) ���ϴ� ���� �ƴ϶�. 
			�ش� key�� ã�� ��ġ���� �ٽ� back �Ͽ� ���� ã�°��̴�.
			pre_move�� ���� key�� ������ �ִ� �ּ����� �������� �����ش�. ��, (state)���� �����ؼ� �� �� �ִ� �Ÿ��̴�. 
			�츮�� �̰��� ���ϴ°��� �ƴ�, �� �ٸ� key�� ã���� �� ��ġ���� �ּ����� �Ÿ��� �˰� ���� ���̴�. 
			
			!! bfs() Ư���� �� ���� �ؾ� �Ѵ�. 
			1. bfs�� �ش� ��ġ���� �� �� �ִ� �ּ����� �Ÿ��� ã���� �� ���̴�. 
			2. ���⼭ ���� Ǯ���� ����� key�� ã������ �Ÿ��� �� �� ���� �ش� key�� ���� ���� �ּҰŸ��� �� �� ����. 
				����, move = pre_move + (key * 2)  + 1�� ���� �ʴ� ���̴�.
		}
		pro2
		{
			����� ������ ������� ������ �Ͽ�����, 
			����� ������ �Դ°��� ��ǥ�̹Ƿ� �湮�ϸ鼭 ���踦 ã�� �Ǹ� ���� �湮�ߴ� list�� �����Ͽ� queue�� push�Ͽ�
			������ ã�� 
			empty�� �� �� ������ ������ �����̴�. 
		}
		sol
		{
			�̷θ� Ż���ϴµ� �ɸ��� �ִ� �Ÿ��� ���ϴ� ������. 
			�������� BFS �����ε�, ���� ������ �ణ ��ٷӴ�. 
	
			����� �ҹ��� a~f�� �� 6���� ������ ������, ���� ���������� �빮�� A~F 6������ �ִ�. 
			���谡 ������ �ش� ���ĺ��� �����ϴ� ���� �� �� ��� ����� �� ����. 
			���� ������ �����ϸ鼭 �湮 ���θ� üũ�ϱ� ���� 3���� �迭�� ������ �ʿ䰡 �ִ�.

			1. �湮 ���� üũ�� �̵� �Ÿ��� ������ �迭 'dist'�� 3�������� �����Ѵ�.
			2. dist �迭�� �ε����� [x��ǥ] [y��ǥ] [���� ����] �̴�.
			3. ���� ����� ��Ʈ����ũ�� ����Ѵ�.
			4. �� ����� a(1<<0), b(1<<1), c(1<<2), d(1<<3), e(1<<4), f(1<<5) �̴�.
			5. ���� ��� a, c, f ���踦 �����ٸ�, 100101�� ��Ÿ�� �� �ִ�. 10������ ��Ÿ���� 37�̴�.
			6. ��� ���踦 �����ٸ�, 111111�̴�. 10������ ��Ÿ���� 63�̹Ƿ�, [���� ����] �ε����� 64 ������� �ؾ� �Ѵ�.
			7. ���� ĭ(a~f)�� �湮�ϸ�, OR ������ ���� �ش� ���踦 ��´�.
			8. �� ĭ(A~F)�� �湮�ϸ�, AND ������ ���� �ش� ���谡 �ִ��� Ȯ���ϰ�, ������ ������� ���ϰ� �Ѵ�.
			9. �� ĭ('#')�� �׻� ������� ���ϸ�, �� ��('.')�� �׻� ����� �� �ִ�.
			10. �ⱸ('1')�� ���� ���� ���� ������, ��� ���̵� �ⱸ�� �����ϸ� �ٷ� BFS�� �����Ѵ�.
		}

*/

#define MAX 50
#define KEY 64
struct MOVE {
	int x, y;
};
char maps[MAX][MAX];
int dist[MAX][MAX][KEY];
int exits[MAX][MAX];
int n, m, ans = -1;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
// map<int, int>  key; // ���� �̸�, �Ÿ� �� 
// map<char, MOVE> door;

void print(int k) {
	for (int i = 0; i< n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j][k] << ' ';
		}
		cout << '\n';
	}
}

struct maze {
	int x, y, k;
};


void bfs(int i, int j) {
	queue<maze> q;
	q.push({ i, j, 0 });
	
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, k = q.front().k; q.pop();
		if (exits[x][y] == 1) {
			ans = dist[x][y][k];
			return;
		}
		cout << k << '\n';
		print(k);
		cout << '\n';

		for (int i = 0; i<4; i++) {
			int nx = x + dx[i], ny = y + dy[i], nk = k;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			char next = maps[nx][ny];

			if ('a' <= next && next <= 'f') nk |= (1 << (next - 'a'));
			else if ('A' <= next && next <= 'F') {
				if (!(nk & (1 << (next - 'A')))) continue;
			}
			
			if (dist[nx][ny][nk] || next == '#') continue;
			q.push({ nx, ny, nk });
			dist[nx][ny][nk] = dist[x][y][k] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int cx, cy;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == '0') {
				cx = i;
				cy = j;
			}
			else if (maps[i][j] == '1') {
				exits[i][j] = 1;
			}
		}
	}
	bfs(cx, cy);
	cout << ans << '\n';
	return 0;
}


/*
#include <iostream>
#include <queue>
#include <map>
#include <cstring>
using namespace std;

#define MAX 50
struct MOVE {
	int x, y;
};

char maps[MAX][MAX];
int moves[MAX][MAX];
int exits[MAX][MAX];
int n, m, ans = -1;
const int dx[] = { 0 , 0 ,1 , -1 };
const int dy[] = { 1, -1, 0 , 0 };
map<char, int>  key; // ���� �̸�, �Ÿ� �� 
map<char, MOVE> door;

bool checks(int x, int y) {
	if (exits[x][y] == 1) {
		ans = moves[x][y];
		return true;
	}
	else return false;
}

void print() {
	for (int i = 0; i< n; i++) {
		for (int j = 0; j < m; j++) {
			cout << moves[i][j] << ' ';
		}
		cout << '\n';
	}
}

void bfs(int i, int j) {
	queue<MOVE> qu;
	qu.push({ i , j });
	bool flag = false;

	while (!qu.empty())
	{
		int x = qu.front().x, y = qu.front().y; qu.pop();

		if (checks(x, y)) {
			return;
		}

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (moves[nx][ny]) continue;
			if (maps[nx][ny] == '#') continue;

			if (maps[nx][ny] == '.') {
				moves[nx][ny] = moves[x][y] + 1;
				qu.push({ nx, ny });
			}

			// ����
			else if (maps[nx][ny] >= 'a' && maps[nx][ny] <= 'f') {
				moves[nx][ny] = moves[x][y] + 1;
				key[maps[nx][ny]] = moves[nx][ny];
				qu.push({ nx, ny });
				flag = true;
			}

			// ��
			else if (maps[nx][ny] >= 'A' && maps[nx][ny] <= 'F') {
				if (key[maps[nx][ny] + 32]) {
					qu.push({ nx, ny });
					moves[nx][ny] = moves[x][y] + (key[maps[nx][ny] + 32] * 2) + 1;
					maps[nx][ny] = '.';
				}
				else {
					moves[nx][ny] = moves[x][y] + 1;
					door[maps[nx][ny]] = { nx, ny };
				}

			}

			else if (maps[nx][ny] == '1') {
				moves[nx][ny] = moves[x][y];
				qu.push({ nx, ny });
			}
		}

		// DEBUG
		cout << '\n';
		print();
		cout << flag << '\n';
		//

		if (qu.empty()) {
			cout << "OK" << '\n';
			if (flag) {
				for (char i = 'a'; i <= 'f'; i++) {
					if (key[i] > 0) {

						MOVE move = door[i - 32];
						if (maps[move.x][move.y] != '.' && maps[move.x][move.y] == (i - 32)) {
							MOVE move = door[i - 32];
							qu.push(door[i - 32]);
							maps[move.x][move.y] = '.';
							moves[move.x][move.y] = moves[move.x][move.y] + key[i] + 1;
						}
					}
				}
				flag = false;
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int cx, cy;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == '0') {
				cx = i;
				cy = j;
			}
			else if (maps[i][j] == '1') {
				exits[i][j] = 1;
			}
		}
	}
	bfs(cx, cy);
	cout << ans << '\n';
	return 0;
}
*/