#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
	������ ���̱�
	https://www.acmicpc.net/problem/17136

	�����̸� ���� �� �ִ� 1�� �˻��ϰ� 
	���� �� �ִ��� �˻� ** hard
	������ recursive�� ��� �˻� ** hard
	��� �ٿ����� ���� �ľ� 
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

// 0�� 1��, 1�� 0���� ����(������ ���̰ų�, ���� ������ ���󺹱� �뵵)
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

	// ��� �ٿ����� Ȯ��(��� 0?)
	if (prove(paper)) {
		ans = (ans == -1) ? cnt : min(ans, cnt);
		return;
	}

	// 1�� ���� �ϴ��� Ȯ�� 
	// 3�� for������ �ٽ� ������ ���̴� �۾� �����ϸ� ���� ����
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
		
		// ������ ���� �� �ִ��� Ȯ��
		if (color_cnt[len] == 0) {
			continue;
		}

		// ���̷��� ������ ������ 0�� �ְų� ���� ������� Ȯ��
		if (zero_exit(y, x, len, paper)) {
			continue;
		}

		// �ش� ����(������)��ŭ ������ ���
		paper = set_paper(y, x, len, paper); // �ش� ���̸�ŭ 0����
		color_cnt[len]--;
		
		dfs(y, x, cnt + 1, paper);

		paper = set_paper(y, x, len, paper); // �ش� ���̸�ŭ 1��
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

