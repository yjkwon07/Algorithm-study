#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/*
	∫ŒµÓ»£
	https://www.acmicpc.net/problem/2529
*/
#define MAX 10
int n;
char bo[MAX];
void print(vector<int> ch) {
	cout << '\n';
	for (int i = 0; i < ch.size(); i++) {
		cout << ch[i] << ' ';

	}
	cout << '\n';
}
bool checks(vector<int> cc) {
	for (int i = 0; i < n; i++) {
		if (bo[i] == '>') {
			if (cc[i] < cc[i + 1]) return false;
		}
		else {
			if (cc[i] > cc[i + 1]) return false;
		}
	}
	return true;
}
int main() {
	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> bo[i];
	}
	vector<int> ch;
	for (int i = 0; i < n + 1; i++) {
		ch.push_back(i);
	}
	vector<int> fh;
	for (int i = 9; i >= (9 - n ); i--) {
		fh.push_back(i);
	}
	do {
		if (checks(fh)) {
			for (int i = 0; i < ch.size(); i++) {
				cout << fh[i];
			}
			cout << '\n';
			break;
		}
		print(fh);
	} while (prev_permutation(fh.begin(), fh.end()));
	do {
		if (checks(ch)) {
			for (int i = 0; i < ch.size(); i++) {
				cout << ch[i];
			}
			cout << '\n';
			break;
		}
		print(ch);
	} while (next_permutation(ch.begin(), ch.end()));
	

	return 0;
}