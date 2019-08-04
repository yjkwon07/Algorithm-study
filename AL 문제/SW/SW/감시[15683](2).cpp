#include <stdio.h>
/*
	na982
	문제 설명
	최대 8 by 8의 2차원 공간이 있습니다.
	빈 공간(0), 감시마케라(1 ~ 5), 벽(6)이 입력으로 들어 옵니다.
	감시카메라의 최대 개수는 8개입니다.
	감시카메라의 위치는 이동 시킬 수 없고, 제자리에서 90도 씩 회전은 가능합니다.
	그리고 벽을 투과 하여 감시 할 수 없습니다.
	감시카메라를 적절히 잘 회전 시켜 감시 하지 못하는 공간이 가장 적게 되도록 합니ㅏㄷ
	그리고 그 때 감시하지 못하는 공간의 개수를 출력하는 문제 입니다.

	감시카메라를 회전시켜 만들 수 있는 경우를 모두 만들어 냅니다.
	그리고 각 경우 마다 사무실 공간을 모두 체크하여 감시 하지 못하는 공간을 카운트 합니다.

	최악의 경우 카메라는 총 8대 이기 때문에,
	4 ^ 8 = 65536 경우가 발생합니다.
	매 경우마다 사무실의 최대 크기 8 * 8 (64) 에서 감시 못하는 공간을 카운트 하면,
	65536 * 65 = 4194304 입니다.(약 400만)
*/
struct CCTV {
	int type, y, x;
};

int n, m, ret;
int map[8][8];
int cctv_size;
CCTV cctv[8];

const int rot_size[] = { 4, 2, 4, 4, 1 };

void map_copy(int desc[8][8], int src[8][8]) {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			desc[y][x] = src[y][x];
		}
	}
}

void update(int dir, CCTV cctv) {
	dir = (dir % 4);

	if (dir == 0) {
		for (int x = cctv.x + 1; x < m; x++) {
			if (map[cctv.y][x] == 6) break;
			map[cctv.y][x] = -1;
		}
	}
	if (dir == 1) {
		for (int y = cctv.y - 1; y >= 0; y--) {
			if (map[y][cctv.x] == 6) break;
			map[y][cctv.x] = -1;
		}
	}
	if (dir == 2) {
		for (int x = cctv.x - 1; x >= 0; x--) {
			if (map[cctv.y][x] == 6) break;
			map[cctv.y][x] = -1;
		}
	}
	if (dir == 3) {
		for (int y = cctv.y + 1; y < n; y++) {
			if (map[y][cctv.x] == 6) break;
			map[y][cctv.x] = -1;
		}
	}
}
void dfs(int count) {
	if (count == cctv_size) {
		int candi = 0;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (map[y][x] == 0) {
					candi++;
				}
			}
		}

		if (ret > candi) ret = candi;
		return;
	}

	int backup[8][8];
	int type = cctv[count].type;
	for (int dir = 0; dir < rot_size[type]; dir++) {
		map_copy(backup, map);

		if (type == 0) {
			update(dir, cctv[count]);
		}
		else if (type == 1) {
			update(dir, cctv[count]);
			update(dir + 2, cctv[count]);
		}
		else if (type == 2) {
			update(dir, cctv[count]);
			update(dir + 1, cctv[count]);
		}
		else if (type == 3) {
			update(dir, cctv[count]);
			update(dir + 1, cctv[count]);
			update(dir + 2, cctv[count]);
		}
		else if (type == 4) {
			update(dir, cctv[count]);
			update(dir + 1, cctv[count]);
			update(dir + 2, cctv[count]);
			update(dir + 3, cctv[count]);
		}
		dfs(count + 1);
		map_copy(map, backup);

	}



	return;
}

int main() {

	scanf("%d %d", &n, &m);
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			scanf("%d", &map[y][x]);

			if (map[y][x] != 0 && map[y][x] != 6) {
				cctv[cctv_size].y = y;
				cctv[cctv_size].x = x;
				cctv[cctv_size].type = map[y][x] - 1;
				cctv_size++;
			}
		}
	}

	ret = 100;
	dfs(0);
	printf("%d\n", ret);
}