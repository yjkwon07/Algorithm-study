#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
/*
	이차원 배열과 연산
	https://www.acmicpc.net/problem/17140
	memset , memcpy의 성능은 callstack에서 메모리가 그렇게 높지 않고 속도면에서 까다롭게 생각 안 해도됨
	여기서는 어떻게 operator를 잘 구현해 내는가 문제

*/
#define MAX 101
int arr[MAX][MAX];
int cp_arr[MAX][MAX];
int r, c, k;
int ans = 9999;
int _rmax, _cmax;

struct OP {
	int index, num;
	bool operator < (const OP &op) const {
		if (num < op.num) return true;
		else if (num == op.num) return index < op.index;
		else return false;
	}
};

//priority_queue<OP> v;
vector<OP> v;
map<int, int> mp;

void print() {
	cout << '\n';
	for (int i = 1; i <= _rmax; i++) {
		for (int j = 1; j <= _cmax; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void _R() {
	memset(cp_arr, 0, sizeof(cp_arr));
	int r = _rmax;
	int c = _cmax;
	vector<int> key;

	for (int i = 1; i <= r; i++) {
		// 배열 검사
		v = vector<OP>();
		key = vector<int>();
		mp = map<int, int>();

		for (int j = 1; j <= c; j++) {
			if (arr[i][j]) {
				if (!mp[arr[i][j]]) {
					key.push_back(arr[i][j]);
				}
				mp[arr[i][j]]++;
				arr[i][j] = 0;
			}
		}

		for (int k = 0; k < key.size(); k++) {
			v.push_back({ key[k], mp[key[k]] });
		}

		sort(v.begin(), v.end());

		int len = v.size() * 2;
		_cmax = max(_cmax, len);
		int count = 0;
		for (int j = 1; j <= len; j += 2) {
			int index = v[count].index;
			int cnt = v[count++].num;
			cp_arr[i][j] = index;
			cp_arr[i][j + 1] = cnt;
		}
	}
	memset(arr, 0, sizeof(arr));
	memcpy(cp_arr, arr, sizeof(arr));
}

void _C() {
	memset(cp_arr, 0, sizeof(cp_arr));
	int r = _rmax;
	int c = _cmax;
	vector<int> key;

	for (int i = 1; i <= c; i++) {
		// 배열 검사
		mp = map<int, int>();
		key = vector<int>();
		v = vector<OP>();

		for (int j = 1; j <= r; j++) {
			if (arr[j][i]) {
				if (!mp[arr[j][i]]) {
					key.push_back(arr[j][i]);
				}
				mp[arr[j][i]]++;
				arr[j][i] = 0;
			}
		}

		for (int k = 0; k < key.size(); k++) {
			v.push_back({ key[k], mp[key[k]] });
		}

		sort(v.begin(), v.end());

		int len = v.size() * 2;
		_rmax = max(_rmax, len);

		// 배열 채우기
		// 카운팅 하기 max 찾기
		int count = 0;
		for (int j = 1; j <= len; j += 2) {
			int index = v[count].index;
			int cnt = v[count++].num;
			cp_arr[j][i] = index;
			cp_arr[j + 1][i] = cnt;
		}
	}
	memset(arr, 0, sizeof(arr));
	memcpy(cp_arr, arr, sizeof(cp_arr));
}

void init() {
	memset(arr, 0, sizeof(arr));
	_rmax = 3;
	_cmax = 3;
}

void input() {
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}
}

void solve() {
	for (int count = 0; count < 101; count++) {

		if (arr[r][c] == k) {
			cout << count << '\n';
			return;
		}

		if (_cmax <= _rmax) {
			_R();
			print();
		}

		else {
			_C();
			print();
		}

	}
	cout << -1 << '\n';
}

int main() {
	init();
	input();
	solve();
	return 0;
}