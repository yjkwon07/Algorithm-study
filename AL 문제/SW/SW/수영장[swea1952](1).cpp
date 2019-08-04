#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
/*
	¼ö¿µÀå

*/
#define MAX 12
#define MAX_TICKET 4
int arr[MAX];
int ticket[MAX_TICKET];
bool checked[MAX];
int ans;

void init() {
	memset(arr, 0, sizeof(arr));
	memset(ticket, 0, sizeof(ticket));
	memset(checked, false, sizeof(checked));
	ans = 0;
}

void input() {
	for (int i = 0; i < 4; i++) {
		cin >> ticket[i];
	}
	for (int i = 0; i < 12; i++) {
		cin >> arr[i];
	}
}

void dfs(int money, int month) {
	if (month >= 12) {
		ans = min(ans, money);
		return;
	}

	if (arr[month] >= 1) {
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				int n_money = arr[month] * ticket[i];
				dfs(money + n_money, month + 1);
			}
			else if (i == 1) {
				int n_money = ticket[i];
				dfs(money + n_money, month + 1);
			}
			else if (i == 2) {
				int n_money = ticket[i];
				dfs(money + n_money, month + 3);
			}
		}
	}
	else dfs(money, month + 1);
}

int main() {
	int testCase = 0;
	cin >> testCase;
	int t = 1;
	while (testCase--) {
		init();
		input();
		ans = ticket[3];
		dfs(0, 0, 0);
		cout << "#" << t << " " << ans << '\n';
	}
	return 0;
}