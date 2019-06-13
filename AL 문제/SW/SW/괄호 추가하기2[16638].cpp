#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*
	��ȣ �߰��ϱ�2
	https://www.acmicpc.net/problem/16638

	��ȣ �߰��ϱ� �������� ������ �켱������ �߰��� ���� 
	�ռ� ��ȣ�� ���� ����ߴ� �Ͱ� ���������� ���ϱ⸦ �� ������ ���
	��, ��ȣ ��� -> ���ϱ� ��� -> ������ ��� ������ ������ ����
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

	// ��ȣ �켱 ���
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

	// ���ϱ� �켱 ���
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

	// ������ ���
	// ���Ϳ��� �����ڸ� ���� ��, ����� ������
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
	// ��ȣ�� �����Ͽ� ������ ����� ��� �ִ밪 ����
	ans = max(ans, getResult());

	// �ݺ����� ���� ������ ������ ����
	// �ش� �ε����� ���� �ε����� ��ȣ�� �߰���
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
	// cin,cout �ӵ����
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
