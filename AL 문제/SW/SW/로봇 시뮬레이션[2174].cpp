#include <iostream>
#include <cstring>
using namespace std;
/*
	로봇 시뮬레이션
	https://www.acmicpc.net/problem/2174
	로봇의 움직임을 그대로 구현하는 문제다. 문제의 조건을 그대로 구현하면 된다. 동서남북의 방향과 회전의 방향에만 유의하면 큰 어려움은 없다.

	아래 코드에서는 다음과 같이 구현하였다.
	로봇의 번호가 적혀있는 맵을 가로(A)*세로(B) 사이즈로 만들어둔다.
	로봇의 좌표 위치와 회전 방향이 적혀있는 배열을 로봇의 개수(N) 만큼 만들어둔다.
	남동북서 순서로 인덱스를 매긴다. S(0), E(1), N(2), W(3)
	왼쪽 회전 : S(0)→E(1), E(1)→N(2), N(2)→W(3), W(3)→S(0)
	오른쪽 회전 : S(0)→W(3), E(1)→S(0), N(2)→E(1), W(3)→N(2)
	회전은 나머지 연산을 하면 된다. 왼쪽 회전 : (인덱스+1)%4, 오른쪽 회전 : (인덱스+3)%4
	이후 주어지는 M번의 명령을 수행한다.

*/
#define MAX 100
const int dx[] = { -1 , 0 , 1, 0 };
const int dy[] = { 0, 1, 0 , -1 };
int arr[MAX + 1][MAX + 1];
int A, B;
int N, M;

struct MOVE {
	int x, y, dir;
};

struct INFO {
	int r1, r2, er;
};

MOVE robot[MAX + 1];

void print() {
	cout << '\n';
	for (int i = 1; i <= B; i++) {
		for (int j = 1; j <= A; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}

INFO go(int No, char order, int loop) {
	MOVE ro = robot[No];
	int x = ro.x;
	int y = ro.y;
	int z = ro.dir;

	int nx = x;
	int ny = y;
	int nz = z;
	arr[x][y] = 0;

	for (int i = 0; i < loop; i++) {
		if (order == 'F') {
			nx += dx[z];
			ny += dy[z];
			if (nx < 1 || nx > B || ny < 1 || ny > A) {
				INFO info = { No, 0, 1 };
				return info;
			}
			if (arr[nx][ny] != 0) {
				INFO info = { No , arr[nx][ny], 2 };
				return info;
			}
		}
		else if (order == 'L') {
			nz = (nz + 1) % 4;
		}3
		else if (order == 'R') {
			nz = (nz + 3) % 4;
		}
	}
	arr[nx][ny] = No;
	robot[No] = { nx , ny , nz };
	INFO info = { 0 ,0 ,0 };
	// print();
	return info;
}

int main() {

	cin >> A >> B;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int x, y, z;
		char dir;
		cin >> x >> y;
		cin >> dir;
		if (dir == 'N') z = 2;
		else if (dir == 'E') z = 1;
		else if (dir == 'W') z = 3;
		else if (dir == 'S') z = 0;
		robot[i] = { y, x , z };
		arr[y][x] = i;
	}

	for (int i = 0; i < M; i++) {
		int No, loop;
		char order;
		cin >> No >> order >> loop;
		INFO check = go(No, order, loop);
		if (check.er == 1) {
			printf("Robot %d crashes into the wall\n", check.r1);
			return 0;
		}
		else if (check.er == 2) {
			printf("Robot %d crashes into robot %d\n", check.r1, check.r2);
			return 0;
		}
	}
	cout << "OK" << '\n';
	return 0;
}