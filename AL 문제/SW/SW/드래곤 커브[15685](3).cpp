#include<iostream>
using namespace std;

// ¿À À§ ¿Þ ¾Æ·¡ 
const int dy[] = { 0, -1, 0, 1 };
const int dx[] = { 1, 0, -1, 0 };
int map[101][101];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		int dragon[1024];

		map[y][x] = 1;
		dragon[0] = d;

		int size = 1;
	
		for (int k = 0; k < g; k++) {
			for (int i = size - 1; i >= 0; i--) {
				dragon[size++] = (dragon[i] + 1) % 4;
			}
		}
	
		for (int i = 0; i < size; i++) {
			x += dx[dragon[i]];
			y += dy[dragon[i]];
			if (x < 0 || x > 100 || y < 0 || y >100) {
				continue;
			}
			map[y][x] = 1;
		}
	}

	int count = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) {
				++count;
			}
		}
	}

	cout << count << '\n';
	cin >> n;
	return 0;
}