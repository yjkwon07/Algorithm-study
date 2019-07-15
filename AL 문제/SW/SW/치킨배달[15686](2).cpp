#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
/*
	치킨배달
	https://www.acmicpc.net/problem/15686
	na982
	문제 설명
	N by N 지도에 집과 치킨 집 또는 빈공간이 배치 됩니다.
	치킨 집중에 M개만 남기고 나머지는 폐업을 한다고 합니다.
	이때 모든 가정집에서 치킨 집과의 거리의 합이 최소가 되도록 할 때 의 거리의 합을 출력하는 문제 입니다.

	N의 범위는 [2, 50]
	M의 범위는 [1, 13]
	최초 입력된 치킨 집의 개수는 [M, 13]
	최초 입력된 집의 개수는 [1, 2N]

	어떤 치킨집이 폐업 되고 어떤 치킨 집이 남느냐 따라서 최소 거리의 합이 달라질 수 있습니다.

	어떻게 풀 수 있을까?
	DFS를 이용해서 남겨질 수 있는 치킨집들의 경우의 수를 모두 찾아냅니다.
	각 집마다 남겨진 치킨집들 중에서 가장 가까운 거리를 구하고 이것을 반복해서 모두 더합니다.
	이렇게 구해진 값들 중에서 가장 작은 값을 출력하면 됩니다.

	Shop의 개수가 N이라고 가정합니다.
	그 중에 M개를 뽑아 pick에 넣으려고 합니다.

	호출은 dfs(0)으로 호출 하면 됩니다.

	M 개의 치킨 집이 선택 되었다면,
	각 집마다 M개의 치킨집과의 거리를 모두 구하고,
	각 집마다 가장 가까운 치킨집과의 거리의 합이 최소가 되는 값만 갱신하면 됩니다.
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