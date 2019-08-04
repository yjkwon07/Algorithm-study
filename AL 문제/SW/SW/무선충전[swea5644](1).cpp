#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
/*
	무선충전
*/
#define MAX 100
struct BC {
	int x, y;
	int C, P;
};
struct PERSON {
	int x, y, dir;
};
int dx[] = { 0 , 0 , 1 , 0, -1 }; // 정상우하좌
int dy[] = { 0, -1, 0, 1, 0 };
vector<int> aPerson(MAX);
vector<int> bPerson(MAX);
vector<BC> bc;
int ans = 0;
int M, A;
void init() {
	aPerson.clear();
	bPerson.clear();
	bc.clear();
	ans = 0;
}
void input() {
	cin >> M >> A;
	for (int i = 1; i <= M; i++) {
		cin >> aPerson[i];
	}
	for (int i = 1; i <= M; i++) {
		cin >> bPerson[i];
	}
	for (int i = 0; i < A; i++) {
		int x, y, c, p;
		cin >> x >> y >> c >> p;
		bc.push_back({ x - 1, y - 1 , c, p });
	}
}
void solve() {
	PERSON a;
	PERSON b;
	a = { 0 , 0 , 0 };
	b = { 9 ,9 , 0 };
	for (int order = 0; order <= M; order++) {
		vector<int> chargeA, chargeB;
		int addA_MAX = 0;
		int addB_MAX = 0;
		for (int i = 0; i < bc.size(); i++) {
			int distA = abs(a.x - bc[i].x) + abs(a.y - bc[i].y);
			int distB = abs(b.x - bc[i].x) + abs(b.y - bc[i].y);
			if (distA <= bc[i].C) {
				chargeA.push_back(i);
			}
			if (distB <= bc[i].C) {
				chargeB.push_back(i);
			}
		}
		if (chargeA.size() >= 1 && chargeB.size() == 0) {
			int temp = bc[chargeA[0]].P;
			for (int k = 1; k < chargeA.size(); k++) {
				temp = max(temp, bc[chargeA[k]].P);
			}
			addA_MAX = temp;
		}
		else if (chargeB.size() >= 1 && chargeA.size() == 0) {
			int temp = bc[chargeB[0]].P;
			for (int k = 1; k < chargeB.size(); k++) {
				temp = max(temp, bc[chargeB[k]].P);
			}
			addB_MAX = temp;
		}
		else {
			for (int i = 0; i < chargeA.size(); i++) {
				for (int j = 0; j < chargeB.size(); j++) {
					int tempA = 0, tempB = 0;
					if (chargeA[i] == chargeB[j]) {
						tempA = bc[chargeA[i]].P / 2;
						tempB = bc[chargeB[j]].P / 2;
					}
					else {
						tempA = bc[chargeA[i]].P;
						tempB = bc[chargeB[j]].P;
					}
					if (tempA + tempB > addA_MAX + addB_MAX) {
						addA_MAX = tempA;
						addB_MAX = tempB;
					}
				}
			}
		}
		ans += (addA_MAX + addB_MAX);
		a.dir = aPerson[order + 1];
		b.dir = bPerson[order + 1];
		a.x += dx[a.dir];
		a.y += dy[a.dir];
		b.x += dx[b.dir];
		b.y += dy[b.dir];
		cout << order << ' ';
		cout << addA_MAX << " " << addB_MAX << '\n';;
	}
}

int main() {
	int testCase = 0;
	cin >> testCase;
	int order = 1;
	while (testCase--)
	{
		init();
		input();
		solve();
		cout << "#" << order++ << " " << ans << '\n';
	}
	return 0;
}