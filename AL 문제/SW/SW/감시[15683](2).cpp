#include <stdio.h>
/*
	na982
	���� ����
	�ִ� 8 by 8�� 2���� ������ �ֽ��ϴ�.
	�� ����(0), ���ø��ɶ�(1 ~ 5), ��(6)�� �Է����� ��� �ɴϴ�.
	����ī�޶��� �ִ� ������ 8���Դϴ�.
	����ī�޶��� ��ġ�� �̵� ��ų �� ����, ���ڸ����� 90�� �� ȸ���� �����մϴ�.
	�׸��� ���� ���� �Ͽ� ���� �� �� �����ϴ�.
	����ī�޶� ������ �� ȸ�� ���� ���� ���� ���ϴ� ������ ���� ���� �ǵ��� �մϤ���
	�׸��� �� �� �������� ���ϴ� ������ ������ ����ϴ� ���� �Դϴ�.

	����ī�޶� ȸ������ ���� �� �ִ� ��츦 ��� ����� ���ϴ�.
	�׸��� �� ��� ���� �繫�� ������ ��� üũ�Ͽ� ���� ���� ���ϴ� ������ ī��Ʈ �մϴ�.

	�־��� ��� ī�޶�� �� 8�� �̱� ������,
	4 ^ 8 = 65536 ��찡 �߻��մϴ�.
	�� ��츶�� �繫���� �ִ� ũ�� 8 * 8 (64) ���� ���� ���ϴ� ������ ī��Ʈ �ϸ�,
	65536 * 65 = 4194304 �Դϴ�.(�� 400��)
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