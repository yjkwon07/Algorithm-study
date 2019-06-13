#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define MAX 20
#define INF 987654321
int bound[MAX];
char map[MAX];
int n, ans;

int calculate(int i, int j, char op) {
	switch (op)
	{
	case'+':
		return i + j;
	case '-':
		return i - j; 
	case '*':
		return i * j;
	default:
		break;
	}
}

int getResult() {
	vector<string> v, nv;
	string str = "";

	int i = 1; 
	int res = 0;

	while (i <= n) {
		if (bound[i] == 0) {

		}
		else if (bound[i] & (1 << 1)) {

		}
	}

	for (i = 0; i < v.size(); i++) {
		if (v[i] == "*") {

		}

		else {

		}
	}

	for (i = 0; i < nv.size(); i++) {
		if (nv[i] == "+") {

		}
		else if (nv[i] == "-") {

		}
	}

	return res;
}

void dfs(int ind) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans = max(ans, getResult());
		}
	}

	for (int i = ind; i <= n; i+=2) {
		for (int j = 1; j <= n; j += 2) {

		}
	}

	return;
}

int main() {
	// cin,cout 속도향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	return 0;
}
