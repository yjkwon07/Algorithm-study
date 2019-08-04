#include<iostream>
#include<vector>
using namespace std;
/*
	드래곤 커브
	https://www.acmicpc.net/problem/15685

	알고리즘 분류 : 시뮬레이션  
	문제에 주어진 조건 그대로 드래곤 커브를 만들어서 사각형의 개수를 세는 문제다. 
	드래곤 커브를 만드는 규칙을 파악해야 한다.

	드래곤 커브는 최대 10세대까지 있으며, 일정한 규칙에 따라 만들어진다.
	1. N세대 드래곤 커브를 만든다고 가정하자.   ㅊ 
	2. N-1세대 드래곤 커브를 우선 복사하고, 이것을 시계 방향으로 90도 회전시킨다.
	3. 회전 시킨 드래곤 커브를 N-1세대 드래곤 커브의 마지막에 이어 붙인다.
	위 1~3 과정을 10세대까지 반복하면 된다.

	쉽게 구현하기 위해서, 드래곤 커브를 좌표 대신 방향을 사용한다.
	방향은 0(→) 1(↑) 2(←) 3(↓) 이다.
	첫 출발 방향을 0으로 둔다.
	이전 세대의 마지막 방향에서 출발 방향까지 거꾸로 탐색하면서, 각 방향에 1을 더하고 이어 붙인다. (%4 연산 필요)
	위 방법으로 드래곤 커브를 미리 10세대까지 만들어둔다.
	이후에 입력받은 방향과 드래곤 세대만큼 좌표에 체크해둔다.
	마지막으로, 사각형 좌표 (X,Y) (X+1,Y) (X,Y+1) (X+1,Y+1)를 체크해서 모두 존재하면, 정답을 1 카운트한다.
	(0, 0)부터 (100,100)까지 모두 확인한 후, 정답 개수를 출력한다.
*/
#define MAX 101
int n, x, y, d, g, ans;
vector<int>v;
bool arr[MAX][MAX];
const int dx[] = { 1 , 0 ,-1, 0 };
const int dy[] = { 0, -1, 0, 1 };

void makeDragon() {
	v.push_back(0);
	for (int i = 1; i <= 10; i++) {
		int k = 1 << (i - 1);
		for (int j = 0; j < k; j++) {
			v.push_back((v[k - j - 1] + 1) % 4);
		}
	}
}

void solve() {
	arr[x][y] = true;
	for (int i = 0; i < (1 << g); i++) {
		x += dx[(v[i] + d) % 4], y += dy[(v[i] + d) % 4];
		arr[x][y] = true;
	}
}

void checked() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1]) ans++;
		}
	}
}

int main() {
	makeDragon();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		solve();
	}
	checked();
	cout << ans << '\n';
	return 0;
}