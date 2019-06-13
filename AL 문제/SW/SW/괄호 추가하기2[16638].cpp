#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*
	괄호 추가하기2
	https://www.acmicpc.net/problem/16638

	괄호 추가하기 문제에서 연산의 우선순위를 추가한 문제 
	앞서 괄호를 먼저 계산했던 것과 마찬가지로 곱하기를 그 다음에 계산
	즉, 괄호 계산 -> 곱하기 계산 -> 나머지 계산 순으로 연산을 진행
*/

#define MAX 20
#define INF 987654321
using namespace std;

int n, ans;
char map[MAX];
int bound[MAX];

int calculate(int i, int j, char op) {
	switch (op) {
	case '+':
		return i + j;
	case '-':
		return i - j;
	case '*':
		return i * j;
	default:
		break;
	}
	return 0;
}

int getResult() {
	vector<string> v, nv;
	string str = "";

	// 괄호 우선 계산
	int i = 1;
	while (i <= n) {
		
		if (bound[i] == 0) {
			str = map[i];
			v.push_back(str);
			i++;
		}
		
		else if (bound[i] & (1 << 1)) {
			int a = map[i] - '0';
			int b = map[i + 2] - '0';
			char op = map[i + 1];
			v.push_back(to_string(calculate(a, b, op)));
			i += 3;
		}
	}

	// 곱하기 우선 계산
	i = 0;
	while (i<v.size()) {
		if (v[i] == "*") {
			int a = stoi(nv[nv.size() - 1]);
			int b = stoi(v[i + 1]);
			char op = v[i][0];
			nv.pop_back();
			nv.push_back(to_string(calculate(a, b, op)));
			i += 2;
		}
		else {
			nv.push_back(v[i]);
			i++;
		}
	}

	// 나머지 계산
	// 벡터에서 연산자를 꺼낸 뒤, 계산을 진행함
	int res = stoi(nv[0]);
	for (int i = 1; i<nv.size(); i += 2) {
		if (nv[i] == "+") {
			res += stoi(nv[i + 1]);
		}
		else if (nv[i] == "-") {
			res -= stoi(nv[i + 1]);
		}
	}

	return res;
}

void dfs(int ind) {
	// 괄호를 포함하여 연산의 결과를 얻어 최대값 갱신
	ans = max(ans, getResult());

	// 반복문을 통해 수식의 정수만 돌며
	// 해당 인덱스와 다음 인덱스에 괄호를 추가함
	for (int i = ind; i <= n; i += 2) {
		if (bound[i] == 0 && bound[i + 2] == 0 && i + 2 <= n) {
			bound[i] |= (1 << 1);
			bound[i + 2] |= (1 << 0);
			dfs(i + 2);
			bound[i] &= ~(1 << 1);
			bound[i + 2] &= ~(1 << 0);
		}
	}
}

int main(int argc, const char * argv[]) {
	// cin,cout 속도향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> map[i];
	}

	ans = -INF;
	dfs(1);
	cout << ans << "\n";

	return 0;
}
