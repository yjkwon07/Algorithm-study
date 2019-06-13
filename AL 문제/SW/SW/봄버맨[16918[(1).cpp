#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*
	봄버맨
	https://www.acmicpc.net/problem/16918
	
	time_over.... 
	메모리를 copy하면서 시간을 오버 한듯?

	-> No No 
	-> n이 짝수 홀수 나머지 정리 부족한 탓에 틀린거였어 ... 
	-> print 할 때 띄어쓰기 안하는거였어 .. 


	1. n이 짝수일 경우 모두 채워진 상태 출력
	
	2. n이 홀수일 경우 폭발 과정
		2-1 이전 폭발물은 map에 true로 설정 -> 초기 time은 1초 
		
		2-2
		{
			지금 폭발물 설치를 mapcopy에 true로 모두 세팅 -> n--
			map에 true로 되어 있는 상태를 attack()으로 mapcopy에 false로 설정  -> n--
			모두 세팅이 끝나면 mapcopy가 남아있는 true들이 2초후에 터질것 들 
			
			-> why? 
			mapcopy에 설치 되었을 때 0초 -> attack() 1초(이전 폭발물 폭발) (여기서 타임워치)
			다시 설치가 2초 -> attack() 3초(이때 폭발)
			따라서 2초후 똑 폭발

			지금 폭발물 설치를 mapcopy에 true로 모두 세팅
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