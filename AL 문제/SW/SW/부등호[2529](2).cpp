#include<iostream> 
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
	부등호
	https://www.acmicpc.net/problem/2529
	checked? 자리 선정 
*/
int n;
char a[20];                 
bool check[10];
vector<string> ans;

bool checking(char a, char b, char c) {
	if (c == '<') {
		if (a > b) return false;
	}
	else if (c == '>')if (a < b) return false;
	return true;
}

bool go_check(string num) {
	for (int i = 0; i < n; i++) {
		if (a[i] == '<') {
			if (num[i] > num[i + 1]) return false;
		}
		else if (a[i] == '>') {
			if (num[i] < num[i + 1]) return false;
		}
	}
	return true;
}

void go(int index, string num) {

	if (index == n + 1) {
		if (go_check(num)) {
			ans.push_back(num);
		}
		return;

	}

	for (int i = 0; i <= 9; i++) {
		if (check[i]) continue;
		if (index == 0 || checking(num[index - 1], i + '0', a[index - 1])) {
			check[i] = true;
			go(index + 1, num + to_string(i));
			check[i] = false;
		}
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	go(0, "");
	auto p = minmax_element(ans.begin(), ans.end());
	cout << *p.second << '\n';
	cout << *p.first << '\n';
	cin >> n;
	return 0;
}+