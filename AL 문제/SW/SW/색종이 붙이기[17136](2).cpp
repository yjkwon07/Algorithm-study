#include <iostream>
#include <algorithm>
using namespace std;

int paper[] = { 0 , 5, 5, 5, 5, 5 };
int map[10][10];
int ans = 9999;
int one_cnt = 0;

// size ��ŭ�� �����̸� ����� �� �ִ��� Ȯ��
bool check(int r, int c, int size) {
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			if (map[i][j] == 0) return false;
		}
	}
	return true;
}

// �湮�� ���� 0->1 , 1->0
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
	if (ans <= cnt) return;      // ���� ������ �����̸� ���̾��� ����ġ��
	
	if (total == one_cnt) {      // 1�� �� ä�� ���
		ans = min(ans, cnt);
		return;
	}
	
	for (int i = row; i < 10; i++) {     // r���� ����
		for (int j = 0; j < 10; j++) {
			
			if (map[i][j] == 1) {	
				bool flag = false;  // ū �����̷� ���� �� ������ ���� �����̴� Ȯ���� ���� �ʾƵ� �ȴ�
				for (int k = 5; k >= 1; k--) {
				
					if ((i + k) <= 10 && (j + k) <= 10 && paper[k] > 0) {
						if (!flag) {
							flag = check(i, j, k); // k*k �����̸� ���� �� ������ check = true
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
				if (!flag) return;          // �����̸� ������ ���
			}

			if (map[i][j] == 1) {
				//print();
				return;     // �������� �ش���ǥ�� ������°��
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