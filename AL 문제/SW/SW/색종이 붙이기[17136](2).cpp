#include <iostream>
#include <algorithm>
using namespace std;

int paper[] = { 0 , 5, 5, 5, 5, 5 };
int map[10][10];
int ans = 9999;
int one_cnt = 0;

// size 만큼의 색종이를 사용할 수 있는지 확인
bool check(int r, int c, int size) {
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			if (map[i][j] == 0) return false;
		}
	}
	return true;
}

// 방문한 점을 0->1 , 1->0
void setVisited(int r, int c, int size) {
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			map[i][j] = map[i][j]^1;
		}
	}
}

void print() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return;
}

void backtracking(int row, int cnt, int total) {
	if (ans <= cnt) return;      // 현재 값보다 색종이를 많이쓰면 가지치기
	
	if (total == one_cnt) {      // 1을 다 채운 경우
		ans = min(ans, cnt);
		return;
	}
	
	for (int i = row; i < 10; i++) {     // r부터 시작
		for (int j = 0; j < 10; j++) {
			
			if (map[i][j] == 1) {	
				bool flag = false;  // 큰 색종이로 덮을 수 있으면 이후 색종이는 확인해 보지 않아도 된다
				for (int k = 5; k >= 1; k--) {
				
					if ((i + k) <= 10 && (j + k) <= 10 && paper[k] > 0) {
						if (!flag) {
							flag = check(i, j, k); // k*k 색종이를 덮을 수 있으면 check = true
						}
						if (flag) {
							setVisited(i, j, k);
							paper[k]--;
							backtracking(i, cnt + 1, total + k * k);
							paper[k]++;
							setVisited(i, j, k);
						}
					}
				}
				if (!flag) return;          // 색종이를 못덮는 경우
			}

			if (map[i][j] == 1) {
				//print();
				return;     // 덮고나서도 해당좌표를 못지우는경우
			}

		}
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
			one_cnt += map[i][j];
		}
	}
	
	backtracking(0, 0, 0);
	if (ans == 9999) ans = -1;
	cout << ans << '\n';
	cin >> ans; 
	return 0;
}