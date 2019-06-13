#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
/*
	퍼즐
	https://www.acmicpc.net/problem/1525
	
	3x3 표에서 퍼즐을 맞춰야 하는 문제다. 
	빈칸(0)을 옮겨서 정렬된 123456780으로 퍼즐을 맞춰야 한다. 
	BFS로 퍼즐을 한 칸 옮기면서, 매번 퍼즐 상태를 저장해야 한다. 
	메모리 제한이 32 MB이기 때문에, 9자리의 수를 한 번에 저장할 수는 없다. 
	이 때문에 map 자료구조를 사용해야 한다.

	입력받을 때, 빈 칸(0)을 숫자 9로 치환한다. 
	그 후, 입력받은 9개의 수를 9자리 수로 변환한다.
	퍼즐 상태를 저장할 dist를 map 자료구조로 선언한다. 
	<키, 값>은 <정수, 정수> 자료형이며, 각 값은 <퍼즐 상태, 퍼즐 이동 횟수> 이다.
	큐(Queue)에는 9자리 정수를 push하고, pop한 숫자를 문자열로 변환한다.
	변환한 문자열에서 문자 '9'의 위치를 찾는다.
	9자리 수의 문자열에 문자 '9'의 위치를 k라 하고, 3*3 퍼즐의 각 좌표를 (x, y)라고 하자. 
	이때, x = k/3, y = k%3으로 나타낼 수 있다.
	9를 상하좌우로 옮기면서, 원래 있던 숫자와 교환한다.
	퍼즐을 움직일 수 있을 때까지 움직이면서, 퍼즐 상태가 123456789라면 퍼즐 이동 횟수를 출력하고 바로 종료한다.
	더 이상 못 움직일 때까지 퍼즐을 123456789로 못 맞춘다면, -1을 출력한다.


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