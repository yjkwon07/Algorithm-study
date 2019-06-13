#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
/*
	����
	https://www.acmicpc.net/problem/1525
	
	3x3 ǥ���� ������ ����� �ϴ� ������. 
	��ĭ(0)�� �Űܼ� ���ĵ� 123456780���� ������ ����� �Ѵ�. 
	BFS�� ������ �� ĭ �ű�鼭, �Ź� ���� ���¸� �����ؾ� �Ѵ�. 
	�޸� ������ 32 MB�̱� ������, 9�ڸ��� ���� �� ���� ������ ���� ����. 
	�� ������ map �ڷᱸ���� ����ؾ� �Ѵ�.

	�Է¹��� ��, �� ĭ(0)�� ���� 9�� ġȯ�Ѵ�. 
	�� ��, �Է¹��� 9���� ���� 9�ڸ� ���� ��ȯ�Ѵ�.
	���� ���¸� ������ dist�� map �ڷᱸ���� �����Ѵ�. 
	<Ű, ��>�� <����, ����> �ڷ����̸�, �� ���� <���� ����, ���� �̵� Ƚ��> �̴�.
	ť(Queue)���� 9�ڸ� ������ push�ϰ�, pop�� ���ڸ� ���ڿ��� ��ȯ�Ѵ�.
	��ȯ�� ���ڿ����� ���� '9'�� ��ġ�� ã�´�.
	9�ڸ� ���� ���ڿ��� ���� '9'�� ��ġ�� k�� �ϰ�, 3*3 ������ �� ��ǥ�� (x, y)��� ����. 
	�̶�, x = k/3, y = k%3���� ��Ÿ�� �� �ִ�.
	9�� �����¿�� �ű�鼭, ���� �ִ� ���ڿ� ��ȯ�Ѵ�.
	������ ������ �� ���� ������ �����̸鼭, ���� ���°� 123456789��� ���� �̵� Ƚ���� ����ϰ� �ٷ� �����Ѵ�.
	�� �̻� �� ������ ������ ������ 123456789�� �� ����ٸ�, -1�� ����Ѵ�.


*/
queue<int> q;
map<int, int> dist;
const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0 , 0 };

void bfs() {
	while (!q.empty()) {
		int temp = q.front(); q.pop();
		if (temp == 123456789) {
			cout << dist[temp] << '\n';
			return;
		}
		string s = to_string(temp);
		int k = s.find('9');
		int x = k / 3, y = k % 3;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
			int nk = nx * 3 + ny;
			string ns = s;
			swap(ns[k], ns[nk]);
			int nd = stoi(ns);
			if (!dist[nd]) {
				dist[nd] = dist[temp] + 1;
				q.push(nd);
			}
		}
	}
	cout << -1 << '\n';
	return;
}

int main() {
	int n, m = 0;
	for (int i = 0; i < 9; i++) {
		cin >> n;
		if (!n) n = 9;
		m = m * 10 + n;
	}
	q.push(m);
	bfs();
	return 0;
}