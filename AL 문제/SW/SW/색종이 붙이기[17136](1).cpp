#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
	색종이 붙이기
	https://www.acmicpc.net/problem/17136

	색종이를 붙일 수 있는 1을 검색하고 
	붙일 수 있는지 검사 ** hard
	있으면 recursive로 재귀 검사 ** hard
	모두 붙였으면 개수 파악 
*/
int ans = -1; 
int color_cnt[6] = {0,5,5,5,5,5};

bool prove(vector<vector<int> >  paper) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (paper[i][j])
				return false;
		}
	}
	return true;
}

bool zero_exit(int y, int x, int len, vector<vector<int> >  paper) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (y + i >= 10 || x + j >= 10) return true;
			if (paper[y + i][x + j] == 0) return true;
		}
	}
	return false;
}

// 0을 1로, 1을 0으로 세팅(색종이 붙이거나, 붙인 색종이 원상복귀 용도)
vector<vector<int> > set_paper(int y, int x, int len, vector<vector<int> > paper) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			paper[y + i][j + x] = (paper[y + i][j + x]) ? 0 : 1;
		}
	}
	return paper;
}

void dfs(int y, int x, int cnt, vector<vector<int> > paper) {

	if (ans != -1 && cnt > ans) {
		return;
	}

	// 모두 붙였는지 확인(모두 0?)
	if (prove(paper)) {
		ans = (ans == -1) ? cnt : min(ans, cnt);
		return;
	}

	// 1이 존재 하는지 확인 
	// 3중 for문으로 다시 색종이 붙이는 작업 진행하면 무한 루프
	bool check = false;
	for (; y < 10; y++) {
		for (x = 0;  x < 10; x++) {
			if (paper[y][x]) {
				check = true;
				break;
			}
		}
		if (check) break;
	}

	for (int len = 5; len > 0; len--) {	
		
		// 색종이 붙일 수 있는지 확인
		if (color_cnt[len] == 0) {
			continue;
		}

		// 붙이려는 색종이 공간에 0이 있거나 범위 벗어나는지 확인
		if (zero_exit(y, x, len, paper)) {
			continue;
		}

		// 해당 길이(사이즈)만큼 색종이 사용
		paper = set_paper(y, x, len, paper); // 해당 길이만큼 0으로
		color_cnt[len]--;
		
		dfs(y, x, cnt + 1, paper);

		paper = set_paper(y, x, len, paper); // 해당 길이만큼 1로
		color_cnt[len]++;
	}
}

int main() {
	vector<vector<int> > paper(10, vector<int>(10, 0));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> paper[i][j];
		}
	}

	dfs(0, 0, 0, paper);
	cout << ans << '\n';
	cin >> ans;
	return 0;
}

