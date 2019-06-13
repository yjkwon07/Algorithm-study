#include <iostream>
#include <queue>
// #include <map>
#include <cstring>
using namespace std;

/*
	달이 차오른다, 가자.
	https://www.acmicpc.net/problem/1194
	처음에는 map을 이용하여 문을 방문할 시 열쇠가 있는지 판별하여 이동하기로 했다. 
	하지만 여기서 문제점은 이전 방문했던 값을 어떻게 갱신해야할지 몰랐다. 
	humm.. 
	처음 생각했던 logic
	{
		1. bfs 완탐
		2. key find -> map<char, int> key -> 'a' = 3 (VALUE = distance) -> (flag = true;)
		3. door find -> 열쇠 있는지? 
			if(yes) {
				move  = pre_move + (key * 2) + 1; (why key * 2?) -> key를 찾고 다시 원위치를 되돌아올 수  + 1(door문 방문)
				문을 => . 으로 변환
			} else continue;
		4. 만약 key find보다 door를 빨리 찾을 수 있으니 -> 큐가 비었는지?
			if(yes) {
				key find가 있었는지? (flag = true?)
				if(yes) {
					문이 있는지? 
					if(yes){
						move = pre_move + (key * 2) + 1;
						문을 .으로 변환
					}
				}
				flag  = false;
			}
			else return

		!!__ 문제가 생김 __ 처음 key를 찾을 때는 아무 문제가 없었지만, 만약 key를 두 개를 찾게 된다면 문제가 발생한다.
		pro
		{
			또 다른 key를 찾을 때, key  * 2한 후, (pre_move) 더하는 것이 아니라. 
			해당 key를 찾은 위치에서 다시 back 하여 문을 찾는것이다.
			pre_move는 이전 key가 가지고 있는 최소한의 움직임을 보여준다. 즉, (state)에서 시작해서 갈 수 있는 거리이다. 
			우리는 이것을 구하는것이 아닌, 또 다른 key를 찾고나면 그 위치부터 최소한의 거리를 알고 싶은 것이다. 
			
			!! bfs() 특직을 잘 이해 해야 한다. 
			1. bfs는 해당 위치에서 갈 수 있는 최소한의 거리를 찾고자 할 때이다. 
			2. 여기서 내가 풀이한 방법은 key를 찾기전의 거리를 알 수 있지 해당 key를 갖고난 후의 최소거리는 알 수 없다. 
				따라서, move = pre_move + (key * 2)  + 1은 맞지 않는 논리이다.
		}
		pro2
		{
			열쇠와 유사한 문제라고 생각을 하였지만, 
			열쇠는 문서를 먹는것이 목표이므로 방문하면서 열쇠를 찾게 되면 문을 방문했던 list를 참조하여 queue에 push하여
			문서를 찾고 
			empty가 될 때 실행을 끝내는 원리이다. 
		}
		sol
		{
			미로를 탈출하는데 걸리는 최단 거리를 구하는 문제다. 
			전형적인 BFS 문제인데, 열쇠 조건이 약간 까다롭다. 
	
			열쇠는 소문자 a~f로 총 6가지 종류가 있으며, 문도 마찬가지로 대문자 A~F 6종류가 있다. 
			열쇠가 없으면 해당 알파벳에 상응하는 문을 열 수 없어서 통과할 수 없다. 
			열쇠 조건을 만족하면서 방문 여부를 체크하기 위해 3차원 배열을 선언할 필요가 있다.

			1. 방문 여부 체크와 이동 거리를 저장할 배열 'dist'를 3차원으로 선언한다.
			2. dist 배열의 인덱스는 [x좌표] [y좌표] [보유 열쇠] 이다.
			3. 보유 열쇠는 비트마스크를 사용한다.
			4. 각 열쇠는 a(1<<0), b(1<<1), c(1<<2), d(1<<3), e(1<<4), f(1<<5) 이다.
			5. 예를 들어 a, c, f 열쇠를 가졌다면, 100101로 나타낼 수 있다. 10진수로 나타내면 37이다.
			6. 모든 열쇠를 가졌다면, 111111이다. 10진수로 나타내면 63이므로, [보유 열쇠] 인덱스는 64 사이즈로 해야 한다.
			7. 열쇠 칸(a~f)에 방문하면, OR 연산을 통해 해당 열쇠를 얻는다.
			8. 문 칸(A~F)에 방문하면, AND 연산을 통해 해당 열쇠가 있는지 확인하고, 없으면 통과하지 못하게 한다.
			9. 벽 칸('#')은 항상 통과하지 못하며, 빈 곳('.')은 항상 통과할 수 있다.
			10. 출구('1')는 여러 개일 수도 있으며, 어느 곳이든 출구에 도착하면 바로 BFS를 종료한다.
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
// map<int, int>  key; // 열쇠 이름, 거리 값 
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
map<char, int>  key; // 열쇠 이름, 거리 값 
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

			// 열쇠
			else if (maps[nx][ny] >= 'a' && maps[nx][ny] <= 'f') {
				moves[nx][ny] = moves[x][y] + 1;
				key[maps[nx][ny]] = moves[nx][ny];
				qu.push({ nx, ny });
				flag = true;
			}

			// 문
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