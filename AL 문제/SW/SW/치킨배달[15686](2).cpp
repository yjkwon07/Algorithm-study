#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
/*
	ġŲ���
	https://www.acmicpc.net/problem/15686
	na982
	���� ����
	N by N ������ ���� ġŲ �� �Ǵ� ������� ��ġ �˴ϴ�.
	ġŲ ���߿� M���� ����� �������� ����� �Ѵٰ� �մϴ�.
	�̶� ��� ���������� ġŲ ������ �Ÿ��� ���� �ּҰ� �ǵ��� �� �� �� �Ÿ��� ���� ����ϴ� ���� �Դϴ�.

	N�� ������ [2, 50]
	M�� ������ [1, 13]
	���� �Էµ� ġŲ ���� ������ [M, 13]
	���� �Էµ� ���� ������ [1, 2N]

	� ġŲ���� ��� �ǰ� � ġŲ ���� ������ ���� �ּ� �Ÿ��� ���� �޶��� �� �ֽ��ϴ�.

	��� Ǯ �� ������?
	DFS�� �̿��ؼ� ������ �� �ִ� ġŲ������ ����� ���� ��� ã�Ƴ��ϴ�.
	�� ������ ������ ġŲ���� �߿��� ���� ����� �Ÿ��� ���ϰ� �̰��� �ݺ��ؼ� ��� ���մϴ�.
	�̷��� ������ ���� �߿��� ���� ���� ���� ����ϸ� �˴ϴ�.

	Shop�� ������ N�̶�� �����մϴ�.
	�� �߿� M���� �̾� pick�� �������� �մϴ�.

	ȣ���� dfs(0)���� ȣ�� �ϸ� �˴ϴ�.

	M ���� ġŲ ���� ���� �Ǿ��ٸ�,
	�� ������ M���� ġŲ������ �Ÿ��� ��� ���ϰ�,
	�� ������ ���� ����� ġŲ������ �Ÿ��� ���� �ּҰ� �Ǵ� ���� �����ϸ� �˴ϴ�.
*/
struct POSI {
	int y, x;
};
int n, m, type, ret;
vector<POSI> house, shop, pick;

void check() {
	int candi = 0;
	for (int i = 0; i < house.size(); i++) {
		int min_dist = 10000000;
		for (int j = 0; j < pick.size(); j++) {
			min_dist = min(min_dist,
				abs(house[i].y - pick[j].y) + abs(house[i].x - pick[j].x));
		}
		candi += min_dist;
	}
	if (ret > candi) {
		ret = candi;
	}
	return;
}

void dfs(int count) {

	if (pick.size() == m) {
		check();
		return;
	}

	for (int i = count; i < shop.size(); i++) {
		pick.push_back(shop[i]);
		dfs(i + 1);
		pick.pop_back();
	}

}

int main() {
	POSI target;
	scanf("%d %d", &n, &m);

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			scanf("%d", &type);
			if (type == 1) {
				target.y = y, target.x = x;
				house.push_back(target);
			}
			if (type == 2) {
				target.y = y, target.x = x;
				shop.push_back(target);
			}
		}
	}
	ret = 0x7fffffff;
	dfs(0);
	printf("%d\n", ret);
	return 0;
}