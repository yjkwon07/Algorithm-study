#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	연산자 끼워넣기
	https://www.acmicpc.net/problem/14888

	N개의 수로 이루어진 수열과 N -1개의 연산자가 있다.(2 <= N <= 11)
	이때, 수와 수 사이에 연산자를 하나씩 끼워넣어서 만들 수 있는 수식 결과의 최대값과 최소값을 구하는 문제
	수식의 계산은 연산자 우선순위를 무시하고 앞에서부터 진행한다.
	수의 순서는 바꿀 수 없다.
	N <= 11이고, 연산자는 최대 10개이기 때문에, N!가지로 모든 경우의 수를 순회해본다.
*/

// pointer knowledgement need!!!!!
int calc(vector<int> &a, vector<int> &b) {
	int ans = a[0];
	for (int i = 1; i < a.size(); i++) {
		if (b[i - 1] == 0)
			ans += a[i];
		else if (b[i - 1] == 1)
			ans -= a[i];
		else if (b[i - 1] == 2)
			ans *= a[i];
		else
			ans /= a[i];
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> b;
	for (int i = 0; i < 4; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
			b.push_back(i);
	}
	sort(b.begin(), b.end());
	vector<int> temp;
	do {
		temp.push_back(calc(a, b));
	} while (next_permutation(b.begin(), b.end()));
	auto as = minmax_element(temp.begin(), temp.end());
	cout << *as.second << '\n';
	cout << *as.first << '\n';
	return 0;
}