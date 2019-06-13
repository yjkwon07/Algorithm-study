#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*
	������
	https://www.acmicpc.net/problem/16918
	
	time_over.... 
	�޸𸮸� copy�ϸ鼭 �ð��� ���� �ѵ�?

	-> No No 
	-> n�� ¦�� Ȧ�� ������ ���� ������ ſ�� Ʋ���ſ��� ... 
	-> print �� �� ���� ���ϴ°ſ��� .. 


	1. n�� ¦���� ��� ��� ä���� ���� ���
	
	2. n�� Ȧ���� ��� ���� ����
		2-1 ���� ���߹��� map�� true�� ���� -> �ʱ� time�� 1�� 
		
		2-2
		{
			���� ���߹� ��ġ�� mapcopy�� true�� ��� ���� -> n--
			map�� true�� �Ǿ� �ִ� ���¸� attack()���� mapcopy�� false�� ����  -> n--
			��� ������ ������ mapcopy�� �����ִ� true���� 2���Ŀ� ������ �� 
			
			-> why? 
			mapcopy�� ��ġ �Ǿ��� �� 0�� -> attack() 1��(���� ���߹� ����) (���⼭ Ÿ�ӿ�ġ)
			�ٽ� ��ġ�� 2�� -> attack() 3��(�̶� ����)
			���� 2���� �� ����

			���� ���߹� ��ġ�� mapcopy�� true�� ��� ����
		}	
*/
#define MAX 200
bool map[MAX][MAX];
bool mapcopy[MAX][MAX];
int r, c, n;
//vector < vector < bool > > map(MAX, vector<bool>(MAX, false));
//vector < vector < bool > > mapcopy(MAX, vector<bool>(MAX, false));

void print() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == true) {
				cout << 'O';
			}
			else cout << '.';
		}
		cout << '\n';
	}
	return;
}

void full() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
				cout << 'O';
		}
		cout << '\n';
	}
	return;
}

void attack(int i, int j) {
	int dx[] = { 0, 0, 1, -1 };
	int dy[] = { 1, -1 ,0 , 0 };
	for (int k = 0; k < 4; k++) {
		int nx = i + dx[k];
		int ny = j + dy[k];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (mapcopy[nx][ny] == false) continue;
		mapcopy[nx][ny] = false;
	}
}

void boom() {
	memset(mapcopy, true, sizeof(mapcopy));
	//mapcopy = vector< vector < bool> >(r, vector<bool>(c, true));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j]) {
				mapcopy[i][j] = false;
				attack(i, j);
			}
		}
	}
	//map = mapcopy;
	memcpy(map, mapcopy, sizeof(mapcopy));
}

void go() {
	while (n != 0) {
		boom();
		n -= 2;
	}
}

int main() {
	// speed up 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c >> n; 
	char check;

	// init()  
	n--;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> check;
			if (check == '.') {
				map[i][j] = false;
			}
			else {
				map[i][j] = true;
			}
		}
	}

	if (n % 2 != 0) {
		full();
	}

	else {
		go();
		print();
	}

	return 0;
}