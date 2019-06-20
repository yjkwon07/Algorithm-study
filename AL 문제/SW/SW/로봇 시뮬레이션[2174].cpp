#include <iostream>
#include <cstring>
using namespace std;
/*
	�κ� �ùķ��̼�
	https://www.acmicpc.net/problem/2174
	�κ��� �������� �״�� �����ϴ� ������. ������ ������ �״�� �����ϸ� �ȴ�. ���������� ����� ȸ���� ���⿡�� �����ϸ� ū ������� ����.

	�Ʒ� �ڵ忡���� ������ ���� �����Ͽ���.
	�κ��� ��ȣ�� �����ִ� ���� ����(A)*����(B) ������� �����д�.
	�κ��� ��ǥ ��ġ�� ȸ�� ������ �����ִ� �迭�� �κ��� ����(N) ��ŭ �����д�.
	�����ϼ� ������ �ε����� �ű��. S(0), E(1), N(2), W(3)
	���� ȸ�� : S(0)��E(1), E(1)��N(2), N(2)��W(3), W(3)��S(0)
	������ ȸ�� : S(0)��W(3), E(1)��S(0), N(2)��E(1), W(3)��N(2)
	ȸ���� ������ ������ �ϸ� �ȴ�. ���� ȸ�� : (�ε���+1)%4, ������ ȸ�� : (�ε���+3)%4
	���� �־����� M���� ����� �����Ѵ�.

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